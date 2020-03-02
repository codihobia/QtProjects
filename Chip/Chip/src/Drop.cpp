#include "Drop.h"



Drop::Drop()
{
	int r, g, b;
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;
	color.setRed(r);
	color.setBlue(b);
	color.setGreen(g);
}





Drop::Drop(int a) :startTime(a)
{

	int r, g, b;
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;
	color.setRed(r);
	color.setBlue(b);
	color.setGreen(g);
}

Drop::Drop(int a, QPoint & b)
{
	startTime = a;
	setPath(a, b);
	int r, g, B;
	r = rand() % 256;
	g = rand() % 256;
	B = rand() % 256;
	color.setRed(r);
	color.setBlue(B);
	color.setGreen(g);
}

Drop::~Drop()
{
}

void Drop::setEnd(int a)
{
	endTime = a;
}

void Drop::setPath(int t, QPoint & a)
{	
	int pos = times.size() - 1;
	if (pos < 0)
	{
		times.push_back(t);
		path.push_back(a);
		return;
	}
	if (t == times[pos])return;
	if (t > times[pos])
	{
		times.push_back(t);
		path.push_back(a);
		return;
	}
	while (t<times[pos])
	{
		pos--;
		if (pos < 0)break;
	}
	times.insert(times.begin() + pos + 1, t);
	path.insert(path.begin() + pos + 1, a);

}

void Drop::setSplit(QPoint & a, QPoint & b)
{
	splitTarget1 = a;
	splitTarget2 = b;
	spliting = true;
}

void Drop::setMerge(QPoint & a)
{
	mergeTarget = a;
	merging = true;
}

QPoint * Drop::pos(int t)
{
	if (t<startTime || t>=endTime)return nullptr;
	for (int i = 0; i < times.size()-1; i++)
	{
		if (times[i] <= t && times[i + 1] > t)
		{
			return &path[i];
		}
	}
	return &path[path.size() - 1];
}



