#pragma once

#include <QObject>
#include<qpoint.h>
#include<vector>
using namespace std;
struct Move
{
	QPoint start;
	QPoint end;
};
struct Mix
{
	vector<QPoint>path;
};
struct Merge
{
	QPoint merge1;
	QPoint merge2;
	QPoint res;
};
struct Split
{
	QPoint split;
	QPoint res1;
	QPoint res2;
};
struct Input
{
	QPoint pos;
};
struct Output
{
	QPoint pos;
};
class Task : public QObject
{
	Q_OBJECT

public:
	Task(QObject *parent=NULL);
	Task(int a, QObject* parent = NULL);
	~Task();
	int t;
	vector<Input>inputActions;
	vector<Output>outputActions;
	vector<Move>moveActions;
	vector<Merge>mergeActions;
	vector<Split>splitActions;
	//vector<Mix>mixActions;
	void ADDINPUT(Input a);
	void ADDOUTPUT(Output a);
	void ADDMOVE(Move a);
	void ADDMERGE(Merge a);
	void ADDSPLIT(Split a);
	
};
