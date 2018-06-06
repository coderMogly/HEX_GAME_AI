// Author Anirudh Yadav @coderMogly
// Licence: Use it as you wish

//graph class- the board for the game of HEX is represented as a graph. Graph contains a list of vertexs and a list of edges.


#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include "edge.h"
#include "vertex.h"
#include <fstream>


using namespace std;

class graph{
	public:
		graph(int size = 7);                                                //constructer used for making a graph that represents the board for HEX.
		graph(graph& G, owner PL);											//contructor used for making individual player graphs	
		void add_vertex(vertex& v_ad);										//adding a vertex to the graph 
		list <vertex>::iterator get_vertex(point& f_pt);					//get a vertex represented by given point
		bool is_present(vertex& f_ver);										//checking whether the vertex is present or not
		bool is_present(edge& f_ed);										//checking whether the edge is present or not
		void add_edge(edge& a_ed);											//adding an edge to the graph
		list <edge>::iterator get_edge(vertex& v1, vertex& v2);				//getting an edge that joins two graphs 
		void print_vertices();												//printing all the vertices of a graph
		void print_edges();													//printing all the edges of a graph		
		int total_edges();													//get total number of edges in a graph	
		int get_size();														//get size of a borad represented by a graph	
		bool no_blank();													//checking if there is any blank vertex in graph or not
		bool is_connected(vertex& start, vertex& end);						//checking whether two nodes are connected or not
		list <vertex> neighbour(vertex& ver);								//returning a list of neighours of a vertex
		void update_owner(vertex& ver, owner newO);							//updating owner of a graph
		owner who_owner(vertex& ver);
		list <vertex> emt_list();
		vector <vertex> emt_vect();										//getting the owner of a particular vertex
	private:
		list <edge> E_list;
		list <vertex> V_list; 
};

#endif