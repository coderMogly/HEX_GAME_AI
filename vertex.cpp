// Author Anirudh Yadav @coderMogly
// Licence: Use it as you wish



#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include <math.h>
#include "vertex.h"
#include "point.h"
#include <fstream>

using namespace std;



///////////////////////////functions for graph class
vertex::vertex(point i_pt){
	pt = i_pt;
	OW = BLANK;
}

vertex::vertex(){
}

ostream& operator <<(ostream& out, vertex& ver){
	out <<ver.pt;
}
bool operator ==(vertex v1, vertex v2){
	if(v1.pt == v2.pt){
		return true;
	}
	return false;
}