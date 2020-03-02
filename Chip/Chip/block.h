#pragma once
#include<qcolor.h>
#include<vector>
using namespace std;
class block
{
public:
	block();
	~block();
	bool isBarrier = false;
	bool in=false;
	bool out=false;
	vector<int>times;
	vector<QColor>colors;
	void addTained(int t, QColor c);
	void wipe(int t);
	void reverseBarrier();

	
};

