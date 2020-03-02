#pragma once
#include<vector>
#include<qpoint.h>
#include<qcolor.h>
using namespace std;
class Drop
{
public:
	Drop();
	Drop(int a);
	Drop(int a, QPoint&b);
	~Drop();
	int startTime=-1;
	int endTime=1200;
	void setEnd(int a);
	void setPath(int t, QPoint& a);
	void setSplit(QPoint&a, QPoint&b);
	void setMerge(QPoint&a);
	QPoint* pos(int t);
	vector<QPoint>path;
	vector<int>times;
	QPoint splitTarget1;
	QPoint splitTarget2;
	QPoint mergeTarget;
	QColor color;
	bool spliting = false;
	bool merging = false;
};

