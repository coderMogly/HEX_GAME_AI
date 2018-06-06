// Author Anirudh Yadav @coderMogly
// Licence: Use it as you wish


#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include <fstream>
#include "point.h"


using namespace std;

enum owner{BLANK, CROSS, ZERO};

class vertex{
	public:
		vertex();
		vertex(point pt);
		friend ostream& operator <<(ostream& out, vertex& ver);
		friend bool operator ==(vertex v1, vertex v2);
		point pt;
		owner OW; 
};

#endif