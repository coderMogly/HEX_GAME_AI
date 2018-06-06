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



///////////////////////////functions for graph class

//contructor for creating a board,
graph::graph(int size){
	//adding vertexes
	for(int i =1; i<=size; i++){
		for(int j =1; j<=size;j++){
			point temp_pt = point(i,j);
			vertex temp_ver = vertex(temp_pt);
			add_vertex(temp_ver);
		}
	}
	//adding edges
	for(int i =1; i<=size; i++){
		for(int j =1; j<=size;j++){
			point temp_pt = point(i,j);

			//getting all posible vertexes that can be the neighbour of temp_ver
			list <vertex>::iterator temp_ver = get_vertex(temp_pt);
			point nei_pt1 = point(i-1,j);
			vertex temp_ver1 = vertex(nei_pt1);
			point nei_pt2 = point(i,j-1);
			vertex temp_ver2 = vertex(nei_pt2);
			point nei_pt3 = point(i+1,j);
			vertex temp_ver3 = vertex(nei_pt3);
			point nei_pt4 = point(i,j+1);
			vertex temp_ver4 = vertex(nei_pt4);
			point nei_pt5 = point(i+1,j-1);
			vertex temp_ver5 = vertex(nei_pt5);
			point nei_pt6 = point(i-1,j+1);
			vertex temp_ver6 = vertex(nei_pt6);

			//checking only permissible vertexes
			//the legal edges will exist with all the posible vertexs which are in the board.
			if(is_present(temp_ver1)){
				list <vertex>::iterator temp = get_vertex(nei_pt1);
				edge temp_edge = edge(*temp_ver, *temp);
				if(!is_present(temp_edge)){
					add_edge(temp_edge);
				}
			}
			if(is_present(temp_ver2)){
				list <vertex>::iterator temp = get_vertex(nei_pt2);
				edge temp_edge = edge(*temp_ver, *temp);
				if(!is_present(temp_edge)){
					add_edge(temp_edge);
				}
			}
			if(is_present(temp_ver3)){
				list <vertex>::iterator temp = get_vertex(nei_pt3);
				edge temp_edge = edge(*temp_ver, *temp);
				if(!is_present(temp_edge)){
					add_edge(temp_edge);
				}
			}
			if(is_present(temp_ver4)){
				list <vertex>::iterator temp = get_vertex(nei_pt4);
				edge temp_edge = edge(*temp_ver, *temp);
				if(!is_present(temp_edge)){
					add_edge(temp_edge);
				}
			}
			if(is_present(temp_ver5)){
				list <vertex>::iterator temp = get_vertex(nei_pt5);
				edge temp_edge = edge(*temp_ver, *temp);
				if(!is_present(temp_edge)){
					add_edge(temp_edge);
				}
			}
			if(is_present(temp_ver6)){
				list <vertex>::iterator temp = get_vertex(nei_pt6);
				edge temp_edge = edge(*temp_ver, *temp);
				if(!is_present(temp_edge)){
					add_edge(temp_edge);
				}
			}
		}
	}
}



//constructor for making the graphs of individual graphs of the palyers
graph::graph(graph& G, owner PL){
	int size = G.get_size();
	list <vertex>::iterator it_v;

	//adding the vertexs that are owned by a particular player
	for(it_v=G.V_list.begin();it_v!=G.V_list.end();++it_v){
		if(it_v->OW == PL){
			vertex temp_ver = *it_v ;
			V_list.push_back(temp_ver);
		}
	}
	int board_size = G.get_size();
	point pt_start = point(0,0);
	point pt_end = point(board_size+1,board_size+1);
	vertex ver_start = vertex(pt_start);
	vertex ver_end = vertex(pt_end);
	list <vertex>::iterator it_o;
	list <vertex>::iterator it_i;

	//adding the edges that are present between the pre added vertexes in the player graph	
	for(it_o = V_list.begin(); it_o!=V_list.end();++it_o){
		for(it_i = it_o;it_i!=V_list.end();++it_i){
			edge temp_edge = edge(*it_o,*it_i);
			if(G.is_present(temp_edge)){
				E_list.push_back(temp_edge);
			}
		}
	}


	//inserting some special nodes to check the game finishing criterion
	V_list.push_back(ver_start);
	V_list.push_back(ver_end);

	//adding edges with special nodes if possible all the starting nodes to start node and connecting all the ending nodes with end node
	if(PL == CROSS){
		for(int i =1;i<=size;i++){
			point t_pt = point(i,1);
			vertex test_ver = vertex(t_pt);
			if(is_present(test_ver)){
				list <vertex>::iterator temp = get_vertex(t_pt);
				edge temp_edge = edge(ver_start, *temp);
				add_edge(temp_edge);
			}
		}
		for(int i =1;i<=size;i++){
			point t_pt = point(i,size);
			vertex test_ver = vertex(t_pt);
			if(is_present(test_ver)){
				list <vertex>::iterator temp = get_vertex(t_pt);
				edge temp_edge = edge(ver_end, *temp);
				add_edge(temp_edge);
			}
		}
	}
	if(PL == ZERO){
		for(int i =1;i<=size;i++){
			point t_pt = point(1,i);
			vertex test_ver = vertex(t_pt);
			if(is_present(test_ver)){
				list <vertex>::iterator temp = get_vertex(t_pt);
				edge temp_edge = edge(ver_start, *temp);
				add_edge(temp_edge);
			}
		}
		for(int i =1;i<=size;i++){
			point t_pt = point(size,i);
			vertex test_ver = vertex(t_pt);
			if(is_present(test_ver)){
				list <vertex>::iterator temp = get_vertex(t_pt);
				edge temp_edge = edge(ver_end, *temp);
				add_edge(temp_edge);
			}
		}
	}  
}


int graph::get_size(){
	return sqrt(V_list.size());
}

void graph::add_vertex(vertex& v_add){
	V_list.push_back(v_add);
}

bool graph::is_present(vertex& f_ver){
	list <vertex>::iterator it;
	for(it = V_list.begin();it!=V_list.end();++it){
		if(*it == f_ver){
			return true;
		}
	}
	return false;
}

list <vertex>::iterator graph::get_vertex(point& f_pt){
	list <vertex>::iterator it;
	for(it = V_list.begin();it!=V_list.end();++it){
		if(it->pt == f_pt){
			return it;
		}
	}
	cout<< f_pt<<" is not present in the graph"<<endl;
	return it;
}

void graph::add_edge(edge& ed){
	E_list.push_back(ed);
}

bool graph::is_present(edge& f_ed){
	list <edge>::iterator it;
	for(it = E_list.begin();it!= E_list.end();++it){
		if(*it == f_ed){
			//cout<<"is present"<<endl;
			return true;
		}
	}
	//cout<<"naaaah"<<endl;
	return false;
}

list <edge>::iterator graph::get_edge(vertex& v1, vertex& v2){
	list <edge>::iterator it;
	for(it = E_list.begin();it!= E_list.end();++it){
		if((it->v1==v1&&it->v2==v2)||(it->v1==v2&&it->v2==v1)){
			return it;	
		}
	}
	cout<<"The required edge is not present in graph."<<endl;
}

void graph::print_vertices(){
	list <vertex>::iterator it;
	for(it = V_list.begin();it!=V_list.end();++it){
		cout<<*it<<endl;
	}
}

void graph::print_edges(){
	list <edge>::iterator it;
	for(it = E_list.begin();it!=E_list.end();++it){
		cout<<*it<<endl;
	}
}

int graph::total_edges(){
	return E_list.size();	
}

bool graph::no_blank(){
	list <vertex>::iterator it;
	for(it = V_list.begin();it!=V_list.end(); ++it){
		if(it->OW == BLANK){
			return false;
		}
	}
	return true;
}

list <vertex> graph::neighbour(vertex& ver){
	list <vertex> ret;
	list <edge>::iterator it;
	for(it = E_list.begin();it!=E_list.end();++it){
		if(it->v1 == ver){
			ret.push_back(it->v2);
		}
		if(it->v2 == ver){
			ret.push_back(it->v1);
		}
	}
	return ret;
}

list <vertex> graph::emt_list(){
	list <vertex> ret;
	list <vertex>::iterator it;
	for(it = V_list.begin();it!=V_list.end();++it){
		if(it->OW == BLANK){
			ret.push_back(*it);
		}
	}
	return ret;
}

vector <vertex> graph::emt_vect(){
	vector <vertex> ret;
	list <vertex>::iterator it;
	for(it = V_list.begin();it!=V_list.end();++it){
		if(it->OW == BLANK){
			ret.push_back(*it);
		}
	}
	return ret;
}

bool graph::is_connected(vertex& start, vertex& end){
	list <vertex> open_set;
	list <vertex> closed_set;
	open_set = neighbour(start);
	closed_set.push_back(start);
	//ending the loop only when the top of the open set has the ending loop at the top
	while(!open_set.empty()){
		if(*open_set.begin() == end){
			return true;
		}
		list <vertex> temp_list = neighbour(*open_set.begin());
		closed_set.push_back(*open_set.begin());
		open_set.pop_front();
		list <vertex>::iterator it;
		//adding the vertex only if it is not in closed set and open set
		for(it = temp_list.begin();it!=temp_list.end();++it){
			bool found = (std::find(closed_set.begin(), closed_set.end(), *it) != closed_set.end());
			if(!found){
				bool found_o = (std::find(open_set.begin(), open_set.end(), *it) != open_set.end());
				if(!found_o){
					open_set.push_back(*it);
				}
			}
		}
	}
	return false;
}

void graph::update_owner(vertex& ver, owner newO){
	list <vertex>::iterator it;
	for(it = V_list.begin();it!=V_list.end();++it){
		if(*it==ver){
			it->OW = newO;
		}
	}
}

owner graph::who_owner(vertex& ver){
	list <vertex>::iterator it;
	for(it = V_list.begin();it!=V_list.end();++it){
		if(*it==ver){
			return it->OW;
		}
	}
	cout<<"vertex not in graph";
}