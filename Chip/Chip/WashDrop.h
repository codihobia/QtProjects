#pragma once
#include<vector>
#include<qpoint.h>
#include<qcolor.h>
using namespace std;
class WashDrop
{
public:
	WashDrop();
	WashDrop(vector<QPoint>_path,int _t);
	~WashDrop();
	int t;
	QColor color;
	vector<QPoint>path;
};

