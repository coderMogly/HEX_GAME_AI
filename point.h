// Author Anirudh Yadav @coderMogly
// Licence: Use it as you wish


#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include <fstream>


using namespace std;


class point{
	public:
		//point();
		point(int x=0, int y=0);
		friend bool operator ==(point& pt1, point& pt2);
		friend ostream& operator <<(ostream& out, point& pt);
		int x;
		int y; 
};

#endif