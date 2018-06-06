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

using namespace std;


//printing the board it is more of a emperically tweaked code to get the desired result
void print_board(graph& board){
	int size = board.get_size();
	int line =0;
	for(int i=1; i<=size; i++){
		for(int j =1; j<=size; j++){
			point pt1 = point(i,j);
			list <vertex>::iterator temp_ver = board.get_vertex(pt1);
			owner turf = temp_ver->OW;
			switch(turf){
				case BLANK :
					cout<<".";
					if(j!=size){
						cout<<" - ";
					}
					break;
				case ZERO :
					cout<<"0";
					if(j!=size){
						cout<<" - ";
					}
					break;
				case CROSS :
					cout<<"X";
					if(j!=size){
						cout<<" - ";
					}
					break;
			}
			}
			cout<<endl;
			line++;
			if(line!=(size*2-1)){
				for(int dash = 0;dash<line;dash++){
					cout<<" ";
				}
			}
			if(i!=size){
				for(int k = 1; k<=size;k++){
					if(k!=size){
						cout<<"\\ / ";
					}else{
						cout<<"\\";
					}
				}
				cout<<endl;
				line++;
				if(line!=(size*2-1)){
					for(int dash = 0;dash<line;dash++){
						cout<<" ";
					}
				}
			}
	}
}




bool game_finish(graph& board){
	bool is_full = board.no_blank();
	if(is_full){
		return true;
	}
	//intiating the graphs for individual players
	graph cross_graph = graph(board, CROSS);
	graph zero_graph = graph(board, ZERO);
	int size = board.get_size();
	point st_point= point(0,0);
	point end_point = point(size + 1, size + 1);
	vertex start = vertex(st_point);
	vertex end = vertex(end_point);
	//checking if the game is finished 
	if(cross_graph.is_connected(start, end)){
		return(true);
	}
	if(zero_graph.is_connected(start, end)){
		return(true);
	}
	return false;
}

owner who_game_finish(graph& board){
	
	//intiating the graphs for individual players
	graph cross_graph = graph(board, CROSS);
	graph zero_graph = graph(board, ZERO);
	int size = board.get_size();
	point st_point= point(0,0);
	point end_point = point(size + 1, size + 1);
	vertex start = vertex(st_point);
	vertex end = vertex(end_point);
	//checking if the game is finished 
	if(cross_graph.is_connected(start, end)){
		return CROSS;
	}
	if(zero_graph.is_connected(start, end)){
		return ZERO;
	}
	return BLANK;
}



//void populate_board(graph& board, list <vertex>& completelist){
//	list <vertex>::iterator it;
//	for(it = )
//}