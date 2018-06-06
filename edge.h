// Author Anirudh Yadav @coderMogly
// Licence: Use it as you wish


#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include <fstream>
#include "point.h"
#include "vertex.h"


using namespace std;


class edge{
	public:
		//edge();
		edge(vertex v1, vertex v2);
		friend bool operator ==(edge& ed1,edge& ed2);
		friend ostream& operator <<(ostream& out, edge& ver);
		//vertex get_v1();
		//vertex get_v2();
		vertex v1;
		vertex v2; 
};

#endif