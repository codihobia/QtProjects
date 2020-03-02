#include "block.h"
#include<vector>


block::block()
{
}


block::~block()
{
}

void block::addTained(int t, QColor c)
{
	for (auto x : colors)
	{
		if (x == c)
			return;
	 }
	times.push_back(t);
	colors.push_back(c);
}

void block::wipe(int t)
{
	for (int i = 0; i < times.size(); i++)
	{
		if (times[i] <= t)
		{
			times.erase(times.begin() + i);
			colors.erase(colors.begin() + i);
			i--;
		}
	}
}

void block::reverseBarrier()
{
	isBarrier = !isBarrier;
}
