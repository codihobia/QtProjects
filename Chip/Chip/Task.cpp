#include "Task.h"

Task::Task(QObject *parent)
	: QObject(parent)
{
}
Task::Task(int a, QObject *parent)
	: QObject(parent),t(a)
{
}

Task::~Task()
{
}

void Task::ADDINPUT(Input a)
{
	inputActions.push_back(a);
}

void Task::ADDOUTPUT(Output a)
{
	outputActions.push_back(a);
}

void Task::ADDMOVE(Move a)
{
	moveActions.push_back(a);
}

void Task::ADDMERGE(Merge a)
{
	mergeActions.push_back(a);
}

void Task::ADDSPLIT(Split a)
{
	splitActions.push_back(a);
}
