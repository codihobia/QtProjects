#pragma once
#include<vector>
#include<qpoint.h>
#include<cmath>
using namespace std;
class state
{
public:
	int t = -1;
	int mx = 1000;
	int X = 19, Y = 19;
	state();
	state(int _X, int _Y,int _t);
	~state();
	void setBarrier(int x, int y);
	void setBarrier(QPoint a);
	void addDangerZone(int x, int y);
	void addDangerZone(QPoint a);
	void reset();
	vector<QPoint>bs(int x1, int y1, int x2, int y2);
	vector<QPoint>bs(QPoint a, QPoint b);
	vector<QPoint>getPath(int x, int y);
	vector<QPoint>getPath(QPoint a);
	vector<QPoint>getPath(vector<QPoint>target);
	int p[20][20];

};

