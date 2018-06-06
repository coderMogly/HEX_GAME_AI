// Author Anirudh Yadav @coderMogly
// Licence: Use it as you wish



#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include "graph.h"
#include "edge.h"
#include "vertex.h"
#include "point.h"
#include <fstream>
#include <math.h>
#include "game.h"

using namespace std;

vertex next_best_move(graph board, owner turn){
	cout<<"running monte carlo simulations to find next best move please wait....."<<endl;
	list <pair<vertex, double> > prob;
	//taking out empty vertex list from the board. 
	list <vertex> empty_list = board.emt_list();
	list <vertex>::iterator it;
	list <vertex>::iterator it1;
	//iterating the empty list 
	
	for(it = empty_list.begin();it!=empty_list.end();++it){
		//creating dummy graph for simulations
		graph board1 = board;
		it->OW = turn;
		board1.update_owner(*it, it->OW);
		//starting the iterator simulations for each node
		int won = 0; 
		vector <vertex> emty_vect = board1.emt_vect();
		for(int i=0; i<1000;i++){
			//taking out all the empty vertexes in a vector to run random simulations 
			vector <vertex>::iterator it2;
	
			//if the ramining nodes are odd the second player is getting less chances
			int size = emty_vect.size()/2;
			//randum shuffling of nodes
			random_shuffle(emty_vect.begin(), emty_vect.end());
			int counter=1;
			//assigning first half nodes first symbol and second half another symbol 
			for(it2 = emty_vect.begin();it2!=emty_vect.end();++it2){
				if(counter>size){
					if(turn==CROSS){
						it2->OW  = ZERO;
						board1.update_owner(*it2, it2->OW);
					}
					if(turn==ZERO){
						it2->OW = CROSS;
						board1.update_owner(*it2, it2->OW);
					}
				} 
				if(counter<=size){
					if(turn==CROSS){
						it2->OW  = CROSS;
						board1.update_owner(*it2, it2->OW);
					}
					if(turn==ZERO){
						it2->OW = ZERO;
						board1.update_owner(*it2, it2->OW);
					}
				}
				counter = counter + 1;
			}
			//finding out the winner
			owner winner = who_game_finish(board1);
			//cout<<"winner  "<<winner<<endl;
			if(winner == turn){
				won = won + 1;
			}
		}
		//cout<<won<<endl;
		//pushing the probability in pairs
		prob.push_back(make_pair(*it, 1.0*won/1000));
	}

	list <pair<vertex, double> >::iterator iit;
	vertex next_move;
	double max=0.0;
	//iterating to find out max probability pair
	for(iit=prob.begin();iit != prob.end();++iit){
		//cout<< (*iit).first<<"  "<<(*iit).second<<endl;
		if(max<(*iit).second){
			next_move = (*iit).first;
			max = (*iit).second;
		}

	}
	// if all the moves reusult in loss picking first possible move
	if(next_move.pt.x == 0 && next_move.pt.y == 0){

		next_move = (*prob.begin()).first;
	}
	return next_move;
}



int main(){
	int size = 0;
	cout<<"WELCOME TO THE GAME OF HEX"<<endl;
	cout<<"Enter the size of the board you want to play on:";
	cin>>size;
	graph board = graph(size);  // initializing the board.
	cout<<"You are player one (CROSS)"<<endl<<"The aim of player 1(CROSS) is to make a horizontal connection"<<endl;
	cout<<"Player 2 (ZERO) is computer"<<endl<<"The aim of player 2(ZERO) is to make a vertical connection"<<endl;
	cout<<"This is your board"<<endl;
	print_board(board);			//printing the board using a function in game.cpp
	cout<<"each node is represented by a tuple (row,column). row(1-size). column(1-size)"<<endl;
	int temp_row1=0;
	int temp_col1=0;
	int temp_row2=0;
	int temp_col2=0;
	while(true){
		startp1:
		//asking p 1 for the input
		cout<<"Player 1 Enter the row of your choice:"<<endl;
		cin>>temp_row1;
		cout<<"Player 1 Enter the column of your choice:"<<endl;
		cin>>temp_col1;
		
		point new_point = point(temp_row1, temp_col1);
		vertex new_ver = vertex(new_point);
		
		//checking legality of the move.
		if((temp_row1<1||temp_row1>size)||(temp_col1<1||temp_col1>size)){
			cout<<"Player 1 illegal move"<<endl;
			goto startp1;
		}
		if(board.who_owner(new_ver)!= BLANK){
			cout<<"Player 1 illegal move"<<endl;
			goto startp1;
		}
		board.update_owner(new_ver, CROSS);  // updating the owner of the board
		
		//checking if the game is complete
		bool fin = game_finish(board);			
		print_board(board);
		if(fin){
			cout<<"Player 1 the throne is yours"<<endl<<"Player 2 you know nothing"<<endl;
			break;
		}
		
		
		startp2:
		
		//calling monte carlo routine to find next best move
		vertex new_ver1  = next_best_move(board, ZERO);
		point new_point1 = new_ver1.pt;
		//vertex new_ver1 = vertex(new_point1);
		temp_row2 = new_point1.x;
		temp_col2 = new_point1.y;
		if((temp_row2<1||temp_row2>size)||(temp_col2<1||temp_col2>size)){
			//cout<<temp_row2<<"  "<<temp_col2<<endl;
			cout<<"Player 2 illegal move"<<endl;
			goto startp2;
		}
		if(board.who_owner(new_ver1)!= BLANK){
			cout<<"Player 2 illegal move"<<endl;
			goto startp2;
		}
		board.update_owner(new_ver1, ZERO);
		fin = game_finish(board);
		print_board(board);
		if(fin){
			cout<<"You are fool."<<endl<<"You lost to your own program."<<endl;
			break;
		}
	}
}