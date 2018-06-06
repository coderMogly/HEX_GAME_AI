// Author Anirudh Yadav @coderMogly
// Licence: Use it as you wish



#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include <math.h>
#include "edge.h"
#include "vertex.h"
#include "point.h"
#include <fstream>

using namespace std;


edge::edge(vertex ver1, vertex ver2){
	v1 = ver1;
	v2 = ver2;
}
bool operator== (edge& e1, edge& e2){
	if((e1.v1==e2.v1 && e1.v2==e2.v2)||(e1.v1==e2.v2 && e1.v2==e2.v1)){
		return true;
	}
	return false;
}

ostream& operator <<(ostream& out, edge& ed){
	out<<ed.v1<<"---"<<ed.v2;
	return out;
}