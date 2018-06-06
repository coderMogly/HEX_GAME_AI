// Author Anirudh Yadav @coderMogly
// Licence: Use it as you wish



#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include <math.h>
#include "point.h"
#include <fstream>

using namespace std;



point::point(int i, int j){
	x = i;
	y = j;
}

ostream& operator <<(ostream& out, point& p_pt){
	out <<" (" <<p_pt.x<<","<<p_pt.y<<") "<<endl;
}

bool operator ==(point& p1, point& p2){
	if(p1.x==p2.x && p1.y==p2.y){
		return true;
	}
	return false;
}