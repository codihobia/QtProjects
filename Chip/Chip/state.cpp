#include "state.h"



state::state()
{
}

state::state(int _X, int _Y,int _t):X(_X),Y(_Y),t(_t)
{
	for (int i = 0; i <= X+1; i++)
	{
		for (int j = 0; j <= Y+1; j++)
		{
			p[i][j] = mx;
		}
	}

	int a = t;
}


state::~state()
{
}

void state::setBarrier(int x, int y)
{
	p[x][y] = -1;
}

void state::setBarrier(QPoint a)
{
	p[a.x()][a.y()] = -1;
}

void state::addDangerZone(int x, int y)
{
	setBarrier(x, y);
	setBarrier(x + 1, y);
	setBarrier(x - 1, y);
	setBarrier(x, y + 1);
	setBarrier(x, y - 1);
	setBarrier(x - 1, y - 1);
	setBarrier(x + 1, y + 1);
	setBarrier(x - 1, y + 1);
	setBarrier(x + 1, y - 1);
}

void state::addDangerZone(QPoint a)
{
	addDangerZone(a.x(), a.y());
}

void state::reset()
{
	for (int i = 0; i <= X+1; i++)
	{
		for (int j = 0; j <= Y+1; j++)
		{
			if (p[i][j] !=-1)
			{
				p[i][j] = mx;
			}
		}
	}
}

vector<QPoint> state::bs(int x1, int y1, int x2, int y2)
{
	vector<QPoint>way;
	if(p[x2][y2]==-1)return vector<QPoint>();
	p[x2][y2] = 0;
	bool found = false;
	while (true)
	{
		bool changed = false;
		
		for (int i = 1; i <= X; i++)
		{
			for (int j = 1; j <= Y; j++)
			{
				if (p[i][j] == -1)continue;
				if (i > 1)
				{
					if (p[i - 1][j] != -1)
					{
						
						if (p[i][j] > p[i - 1][j] + 1)
						{
							changed = true;
							p[i][j] = p[i - 1][j] + 1;
							if (i == x1 && j == y1)found = true;
						}
					}

				}
				if (j > 1)
				{
					if (p[i][j - 1] != -1)
					{
						
						if (p[i][j] > p[i][j - 1] + 1)
						{
							changed = true;
							p[i][j] = p[i][j - 1] + 1;
							if (i == x1 && j == y1)found = true;
						}
					}
				}
				if (i < X)
				{
					if (p[i + 1][j] != -1)
					{
						
						if (p[i][j] > p[i + 1][j] + 1)
						{
							changed = true;
							p[i][j] = p[i + 1][j] + 1;
							if (i == x1 && j == y1)found = true;
						}
					}
				}
				if (j < Y)
				{
					if (p[i][j + 1] != -1)
					{
						
						if (p[i][j] > p[i][j + 1] + 1)
						{
							changed = true;
							p[i][j] = p[i][j + 1] + 1;
							if (i == x1 && j == y1)found = true;
						}
					}
				}
			}
		}
		if (!changed)break; 
		
		if (found)break;
	}
	if (!found)
	{
		return vector<QPoint>();
	}
	int a;
	while (x2 != x1 || y2 != y1)
	{
		way.push_back(QPoint(x1, y1));
		if (x1>1&&p[x1 - 1][y1] == p[x1][y1] - 1)
		{
			x1 -= 1;
		}
		else if (x1<X&&p[x1 + 1][y1] == p[x1][y1] - 1)
		{
			x1 += 1;
			int tmp = p[x1][y1+1];
		}
		else if (y1>1&&p[x1][y1 - 1] == p[x1][y1] - 1)
		{
			y1 -= 1;
		}
		else if (y1<Y&&p[x1][y1 + 1] == p[x1][y1] - 1)
		{
			y1 += 1;
		}
	}
	way.push_back(QPoint(x2, y2));
	return way;

}

vector<QPoint> state::bs(QPoint a, QPoint b)
{
	return bs(a.x(), a.y(), b.x(), b.y());
}

vector<QPoint> state::getPath(int x, int y)
{

	vector<QPoint>path1 = bs(1, 1, x, y);
	reset();
	vector<QPoint>path2 = bs(x, y, X, Y);
	if (path1.size() <= 1 || path2.size() <= 1)
	{
		return vector<QPoint>();
	}
	for (int i = 1; i < path2.size(); i++)
	{
		path1.push_back(path2[i]);
	}
	return path1;
}

vector<QPoint> state::getPath(QPoint a)
{
	return getPath(a.x(), a.y());
}

vector<QPoint> state::getPath(vector<QPoint> target)
{	
	vector<QPoint>path1 = bs(1, 1, target[0].x(), target[0].y());
	if(path1.size()<=1)return vector<QPoint>();
	reset();
	for (int i = 0; i < target.size() - 1; i++)
	{
		vector<QPoint>path2 = bs(target[i], target[i + 1]);
		if(path2.size()<=1)return vector<QPoint>();
		for (int j = 1; j < path2.size(); j++)
		{
			path1.push_back(path2[j]);
		}
		reset();
	}
	vector<QPoint>path3 = bs(target[target.size() - 1], QPoint(X, Y));
	if (path3.size() <= 1)
	{
		return vector<QPoint>();
	}
	for (int j = 1; j < path3.size(); j++)
	{
		path1.push_back(path3[j]);
	}
	return path1;
}
