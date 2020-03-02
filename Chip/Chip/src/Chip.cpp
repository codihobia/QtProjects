#include "Chip.h"
#include<qdebug.h>
Chip::Chip(QWidget *parent)
	: QMainWindow(parent),secTimer(new QTimer(this)),frameTimer(new QTimer(this))
{
	ui.setupUi(this);
	secTimer->setInterval(1000);
	frameTimer->setInterval(100);
	connect(ui.read, SIGNAL(clicked()), this, SLOT(OnRead()));
	connect(ui.actionInit, SIGNAL(triggered()), this, SLOT(OnInit()));
	connect(ui.start, SIGNAL(clicked()), this, SLOT(OnStart()));
	connect(ui.pause, SIGNAL(clicked()), this, SLOT(OnHalt()));
	connect(ui.reset, SIGNAL(clicked()), this, SLOT(OnReset()));
	connect(ui.lastStep, SIGNAL(clicked()), this, SLOT(OnLastStep()));
	connect(ui.nextStep, SIGNAL(clicked()), this, SLOT(OnNextStep()));
	connect(frameTimer, SIGNAL(timeout()), this, SLOT(update()));
	connect(ui.wash, SIGNAL(clicked(bool )), this, SLOT(OnWash(bool)));


}

void Chip::OnRead()
{
	QString fileOrig = ui.fileName->text();
	std::string file= GBK::FromUnicode(fileOrig);
	ifstream in(file);
	if (!in)
	{
		QMessageBox::information(NULL,GBK::ToUnicode( "Error"), GBK::ToUnicode("无此文件！"));
		return;
	}
	std::string order;
	std::string parameters;
	
	
	while (!in.eof())
	{
		in >> order >> parameters;
		if (parameters[parameters.length() - 1] == ';')
		{
			parameters = parameters.substr(0, parameters.length() - 1);
		}
		if (order == "Input")
		{
			addInput(parameters);
		}
		else if (order == "Output")
		{
			addOutput(parameters);
		}
		else if (order == "Move")
		{
			addMove(parameters);
		}
		else if (order == "Mix")
		{
			addMix(parameters);
		}
		else if (order == "Merge")
		{
			addMerge(parameters);
		}
		else if (order == "Split")
		{
			addSplit(parameters);
		}
	}
	ui.nextStep->setEnabled(true);
	ui.start->setEnabled(true);
	ui.lastStep->setEnabled(true);
	ui.pause->setEnabled(true);
	ui.reset->setEnabled(true);
	for (int i = 0; i < drops.size(); i++)
	{
		if (drops[i].endTime > maxTime)
		{
			maxTime = drops[i].endTime;
		}
	}
	if (wash)
	{
		setWash();
	}
	
}

void Chip::OnInit()
{
	InitDialg dlg(this);
	int ret = dlg.exec();

	if (ret == QDialog::Accepted)
	{
		setParameters(dlg.x, dlg.y, dlg.ins, dlg.outs);
	}
	else
	{
		
	}
	

}

void Chip::OnNextStep()
{
	
	if (t > maxTime)
	{
		return;
	}
	
	soundEffect();
	update();
	updateTaint();
	
	if (wash&&t>=0)
	{	
		int w = washTarget[t].size();
		if (washTarget[t].size() != 0&&washFailTime!=t+2)
		{
			if (!curWash)
			{
				state curState(X, Y, t);
				for (int m = 0; m < drops.size(); m++)
				{
					QPoint* pos = drops[m].pos(t);
					if (!pos)continue;
					if (drops[m].endTime == t + 1 && drops[m].spliting)
					{
						curState.addDangerZone(drops[m].splitTarget1);
						curState.addDangerZone(drops[m].splitTarget2);
					}
					else
					{
						curState.addDangerZone(*pos);
					}
				}
				for (int i = 1; i <= X; i++)
				{
					for (int j = 1; j <= Y; j++)
					{
						if (blocks[i][j].isBarrier)
						{
							curState.setBarrier(i, j);
						}
					}
				}
				vector<QPoint>path = curState.getPath(washTarget[t]);
				if (path.size() <= 2)
				{
					washFailTime = t+2;
				}
				else
				{
					curWash = new WashDrop(path, t);
					tWash = 0;
				}
				
				if(washFailTime!=t+2)
				return;
			}
			else
			{
				if (tWash<int(curWash->path.size()-1))
				{
					tWash++;
					int xWash = curWash->path[tWash].x();
					int yWash = curWash->path[tWash].y();
					if (blocks[xWash][yWash].isBarrier)
					{
						tWash--;
						QMessageBox::warning(this, "Warning!", GBK::ToUnicode("清洗失败！"));
						return;
					}
					blocks[xWash][yWash].wipe(t);
					return;
				}
				else
				{
					tWash = 0;
					delete curWash;
					curWash = nullptr;
				}
			}
		}

		
		
	}

	t++;

	if (t == washFailTime && wash)
	{
		QMessageBox::warning(this, "Warning!", GBK::ToUnicode("清洗失败！"));
		return;
	}

	if (staticCheck() && dynamicCheck()) {}
	else
	{
		QMessageBox::warning(this, "Warning", GBK::ToUnicode("违反约束条件！"));
		return;
	}
}

void Chip::OnLastStep()
{
	
	if (t == -1)return;
	t--;
	update();

	
}

void Chip::OnStart()
{
	connect(secTimer, SIGNAL(timeout()), this, SLOT(OnNextStep()));
	secTimer->start();


	ui.lastStep->setEnabled(false);
	ui.nextStep->setEnabled(false);
}

void Chip::OnHalt()
{
	secTimer->stop();
	ui.lastStep->setEnabled(true);
	ui.nextStep->setEnabled(true);
}

void Chip::OnReset()
{
	t = -1;
	update();
}

void Chip::OnWash(bool a )
{
	wash = a;
}

void Chip::paintEvent(QPaintEvent * event)
{
	if (!initialized)return;
	drawBlocks();
	drawInOut();
	drawDrops();
	drawTaints();
	drawBarriers();
	if (t >= maxTime)
	{
		drawNumbers();
	}
	if (wash)
	{
		drawWashDrops();
	}
}

void Chip::timerEvent(QTimerEvent * event)
{
}

QPoint Chip::pos2bolck(QPoint & p)
{
	int x0 = p.x()-edge;
	int y0 = p.y()-edge;
	x0 /= grid;
	y0 /= grid;
	x0 += 1;
	y0 += 1;
	return QPoint(x0, Y+1-y0);

}

QPoint Chip::block2pos(QPoint & p)
{
	int x0 = p.x()-1;
	int y0 = Y+1-p.y()-1;
	x0 *= grid;
	y0 *= grid;
	x0 += edge + grid / 2;
	y0 += edge + grid / 2;
	return QPoint(x0, y0);
}


void Chip::drawBlocks()
{
	QPainter* painter=new QPainter(this);
	QPen pen(QColor(0, 0, 0));
	pen.setWidth(3);
	painter->setPen(pen);
	for (int i = 0; i <= X; i++)
	{
		painter->drawLine(i*grid + edge, edge, i*grid + edge, edge + Y * grid);
	}
	for (int i = 0; i <= Y; i++)
	{
		painter->drawLine( edge, i*grid+edge, X*grid + edge, i*grid+edge);
	}

	
	delete painter;
}

void Chip::drawDrops()
{
	QPainter* painter=new QPainter(this);
	painter->setRenderHint(QPainter::Antialiasing);
	for (auto x : drops)
	{
		if (x.startTime > t||x.endTime<=t)continue;
		QColor color = x.color;
		QPen pen;
		pen.setStyle(Qt::NoPen);
		pen.setBrush(color);
		
		painter->setPen(pen);
		painter->setBrush(QBrush(color));
		QPoint pos = block2pos(*x.pos(t));

		if (x.endTime == t + 1 && x.spliting)
		{
			QPoint tmp = x.splitTarget1;
			if (tmp.x() != x.pos(t)->x())
			{
				painter->drawEllipse(pos.x() - 3 * diameter / 2, pos.y() - diameter / 2, 3 * diameter, diameter);

			}
			else
			{
				painter->drawEllipse(pos.x() -  diameter / 2, pos.y() -3* diameter / 2, diameter, 3*diameter);
			}
		}
		else if (x.endTime == t + 1 && x.merging)
		{

			QPoint tmp1 = block2pos(x.mergeTarget);
			QPoint tmp2 = block2pos(*x.pos(t));
			QPoint tmp = tmp1 + tmp2;
			tmp /= 2;
			painter->drawEllipse(tmp.x() - diameter / 2, tmp.y() - diameter / 2, diameter, diameter);
		}
		else
		{
			painter->drawEllipse(pos.x() - diameter / 2, pos.y() - diameter / 2, diameter, diameter);
		}

	}
	
	

	delete painter;

}

void Chip::drawWashDrops()
{
	if (!wash)return;
	if (!curWash)return;
	if (tWash < 0 || tWash >= curWash->path.size())return;
	QPainter* painter = new QPainter(this);
	painter->setRenderHint(QPainter::Antialiasing);
	QPen pen;
	pen.setStyle(Qt::NoPen);
	painter->setPen(pen);
	painter->setBrush(curWash->color);
	
	QPoint pos = block2pos(curWash->path[tWash]);
	painter->drawEllipse(pos.x() - grid / 2, pos.y() - grid / 2, grid, grid);
	delete painter;

	
}

void Chip::drawInOut()
{
	QPainter* painter = new QPainter(this);
	QPen pen(QColor(0, 0, 0));
	pen.setWidth(3);
	
	painter->setBrush(QColor(245, 0, 0));
	for (int i = 1; i <= Y; i++)
	{
		if (blocks[1][i].in)
		{
			QPoint p(0, i);
			QPoint q = block2pos(p);
			QRect rect = QRect(q.x() - diameter / 2, q.y() - diameter / 2, diameter, diameter);
			painter->drawRect(rect);

			
			
		}
		else if (blocks[X][i].in)
		{
			QPoint p(X + 1, i);
			QPoint q = block2pos(p);
			QRect rect = QRect(q.x() - diameter / 2, q.y() - diameter / 2, diameter, diameter);
			painter->drawRect(rect);
			
		}
	}
	for (int i = 2; i < X; i++)
	{
		if (blocks[i][1].in)
		{
			QPoint p(i, 0);
			QPoint q = block2pos(p);
			QRect rect = QRect(q.x() - diameter / 2, q.y() - diameter / 2, diameter, diameter);
			painter->drawRect(rect);
			
		}
		else if (blocks[i][Y].in)
		{
			QPoint p(i, Y + 1);
			QPoint q = block2pos(p);
			QRect rect = QRect(q.x() - diameter / 2, q.y() - diameter / 2, diameter, diameter);
			painter->drawRect(rect);
			
		}
	}
	painter->setBrush(QColor(0, 0, 253));
	for (int i = 1; i <= Y; i++)
	{
		if (blocks[1][i].out)
		{
			QPoint p(0, i);
			QPoint q = block2pos(p);
			QRect rect = QRect(q.x() - diameter / 2, q.y() - diameter / 2, diameter, diameter);
			painter->drawRect(rect);
			
		}
		else if (blocks[X][i].out)
		{
			QPoint p(X + 1, i);
			QPoint q = block2pos(p);
			QRect rect = QRect(q.x() - diameter / 2, q.y() - diameter / 2, diameter, diameter);
			painter->drawRect(rect);
			
		}
	}
	for (int i = 2; i < X; i++)
	{
		if (blocks[i][1].out)
		{
			QPoint p(i, 0);
			QPoint q = block2pos(p);
			QRect rect = QRect(q.x() - diameter / 2, q.y() - diameter / 2, diameter, diameter);
			painter->drawRect(rect);
			
		}
		else if (blocks[i][Y].out)
		{
			QPoint p(i, Y + 1);
			QPoint q = block2pos(p);
			QRect rect = QRect(q.x() - diameter / 2, q.y() - diameter / 2, diameter, diameter);
			painter->drawRect(rect);
			
		}
	}

	
	QPoint washIn = block2pos(QPoint(0, 1));
	QPoint washOut = block2pos(QPoint(X+1, Y));
	painter->setBrush(QColor(255, 100, 0));
	QRect rect1 = QRect(washIn.x() - diameter / 2, washIn.y() - diameter / 2, diameter, diameter);
	painter->drawRect(rect1);

	painter->setBrush(QColor(0, 100, 100));
	QRect rect2 = QRect(washOut.x() - diameter / 2, washOut.y() - diameter / 2, diameter, diameter);
	painter->drawRect(rect2);


}

void Chip::drawTaints()
{
	QPainter* painter = new QPainter(this);
	painter->setRenderHint(QPainter::Antialiasing);
	QPen pen;
	pen.setStyle(Qt::NoPen);
	painter->setPen(pen);
	for (int i = 1; i <= X; i++)
	{
		for (int j = 1; j <= Y; j++)
		{
			for (int k = 0; k < blocks[i][j].times.size(); k++)
			{
				if (blocks[i][j].times[k] <= t)
				{
					QColor color = blocks[i][j].colors[k];
					painter->setBrush(QBrush(color));
					for (int l = 0; l < 5; l++)
					{
						QPoint tmp = block2pos(QPoint(i, j));
						QPoint setback(grid / 2, grid / 2);
						tmp -= setback;
						int delta_x = rand() % grid;
						int delta_y = rand() % grid;
						if (delta_x < 5)delta_x += 5;
						if (delta_x > grid - 5)delta_x -= 5;
						if (delta_y < 5)delta_y += 5;
						if (delta_y > grid - 5)delta_y -= 5;
						
						tmp += QPoint(delta_x, delta_y);
						painter->drawEllipse(tmp, 3, 3);
						
					}
				}
			}
		}
	}

}

void Chip::drawNumbers()
{
	QPainter* painter = new QPainter(this);
	
	for (int i = 1; i <= X; i++)
	{
		for (int j = 1; j <= Y; j++)
		{
			QPoint pos = block2pos(QPoint(i,j));
			QRect rects(pos.x() - grid / 2, pos.y() - grid / 2, grid, grid);
			QFont font;
			font.setFamily("Microsoft YaHei");
			font.setPointSize(24);
			painter->setFont(font);
			painter->drawText(rects, Qt::AlignCenter, QString::number(blocks[i][j].times.size()));
			
		}
	}
}

void Chip::drawBarriers()
{
	QPainter* painter = new QPainter(this);
	painter->setRenderHint(QPainter::Antialiasing);
	painter->setBrush(QColor(0, 0, 0));
	for (int i = 1; i <= X; i++)
	{
		for (int j = 1; j <= Y; j++)
		{
			if (blocks[i][j].isBarrier)
			{
				QPoint p = block2pos(QPoint(i, j));
				painter->drawRect(p.x() - grid / 2, p.y() - grid / 2, grid, grid);
			}
		}
	}
}

void Chip::setParameters(int _x, int _y, QString ins, QString outs)
{
	if (_x <= 3 && _y <= 3)
	{
		QMessageBox::warning(this, tr("Warning"), GBK::ToUnicode("尺寸过小！"));
		return;
	}
	X = _x;
	Y = _y;
	std::string in = GBK::FromUnicode(ins);
	std::string out = GBK::FromUnicode(outs);
	blocks = new block*[_x + 1];
	for (int i = 0; i <= _x; i++)
	{
		blocks[i] = new block[_y + 1];
	}
	
	for (int i = 0; i < in.length(); i++)
	{
		if (in[i] == '(')
		{
			int mid = i + 1, end = i + 1;
			for (int j = i + 1; j < in.length(); j++)
			{
				if (in[j] == ')')
				{
					end = j;
					break;
				}
			}
			for (int j = i + 1; j < end; j++)
			{
				if (in[j] == ',')
				{
					mid = j;
					break;
				}
			}
			int x_tmp = stoi(in.substr(i + 1, mid - i));
			int y_tmp = stoi(in.substr(mid + 1, end - mid));
			if (x_tmp != 1 && x_tmp != X && y_tmp != 1 && y_tmp != Y)
			{
				QMessageBox::warning(this, tr("Error"), GBK::ToUnicode("输入端口不在边界！"));
				return;
			}
			blocks[x_tmp][y_tmp].in = true;
		}
	}
	for (int i = 0; i < out.length(); i++)
	{
		if (out[i] == '(')
		{
			int mid = i + 1, end = i + 1;
			for (int j = i + 1; j < out.length(); j++)
			{
				if (out[j] == ')')
				{
					end = j;
					break;
				}
			}
			for (int j = i + 1; j < end; j++)
			{
				if (out[j] == ',')
				{
					mid = j;
					break;
				}
			}
			int x_tmp = stoi(out.substr(i + 1, mid - i));
			int y_tmp = stoi(out.substr(mid + 1, end - mid));
			if (x_tmp != 1 && x_tmp != X && y_tmp != 1 && y_tmp != Y)
			{
				QMessageBox::warning(this, tr("Error"), GBK::ToUnicode("输出端口不在边界！"));
				return;
			}
			blocks[x_tmp][y_tmp].out = true;
		}
	}
	
	update();
	ui.read->setEnabled(true);
	ui.wash->setEnabled(true);
	initialized = true;
	frameTimer->start();
}

vector<int> Chip::parse(string a)
{
	vector<int>w;
	int last = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ','||i==a.length()-1)
		{
			if (i == a.length()-1)i += 1;
			string stmp = a.substr(last, i - last );
			int tmp = stoi(stmp);
			w.push_back(tmp);
			last = i + 1;
		}
	}
	string b = a;
	return w;
}

Drop * Chip::getDrop(int ti, int a, int b)
{	
	QPoint c(a, b);
	return getDrop(ti, c);
}


Drop * Chip::getDrop(int ti,QPoint a)
{
	for (int i = 0; i < drops.size(); i++)
	{	
		QPoint* tmp = drops[i].pos(ti);
		QPoint* z = tmp;

		if (tmp)
		{
			if (*tmp == a)
			{
				return &drops[i];
			}
		}
	}
	return nullptr;
}

int Chip::getDropIndex(int ti,int a, int b)
{
	QPoint c(a, b);
	return getDropIndex(ti,c);
}

int Chip::getDropIndex(int ti,QPoint a)
{
	for (int i = 0; i < drops.size(); i++)
	{
		if (*drops[i].pos(ti)== a)
		{
			return i;
		}
	}
	return -1;
}

void Chip::addInput(string a)
{
	vector<int>b = parse(a);
	if (!blocks[b[1]][b[2]].in)
	{
		QMessageBox::warning(this, tr("Warning"), GBK::ToUnicode("无入口!"));
		return;
	}
	QPoint pos(b[1], b[2]);
	Drop d(b[0], pos);
	drops.push_back(d);
	blocks[b[1]][b[2]].addTained(b[0], d.color);
	

}

void Chip::addOutput(string a)
{
	vector<int>b = parse(a);
	if (!blocks[b[1]][b[2]].out)
	{
		QMessageBox::warning(this, tr("Warning"), GBK::ToUnicode("无出口!"));
		return;
	}
	QPoint pos(b[1], b[2]);
	Drop* d = getDrop(b[0]-1,pos);
	if (!d)return;
	d->setEnd(b[0]);
	d->setPath(b[0]-1, pos);
	
}

void Chip::addMove(string a)
{
	vector<int>b = parse(a);
	QPoint s(b[1], b[2]);
	QPoint e(b[3], b[4]);
	Drop* d = getDrop(b[0] - 1, s);
	if (!d)return;
	d->setPath(b[0], e);
	blocks[b[3]][b[4]].addTained(b[0], d->color);
	
}

void Chip::addSplit(string a)
{
	vector<int>b = parse(a);
	QPoint s(b[1], b[2]);
	QPoint r1(b[3], b[4]);
	QPoint r2(b[5], b[6]);
	Drop* d = getDrop(b[0] - 1, s);
	if (!d)return;
	d->setEnd(b[0] + 1);
	d->setSplit(r1, r2);
	Drop d1(b[0] + 1,r1);
	Drop d2(b[0] + 1, r2);
	drops.push_back(d1);
	drops.push_back(d2);
	blocks[b[3]][b[4]].addTained(b[0]+1, d1.color);
	blocks[b[5]][b[6]].addTained(b[0]+1, d2.color);

	
}

void Chip::addMerge(string a)
{
	vector<int>b = parse(a);
	QPoint m1(b[1], b[2]);
	QPoint m2(b[3], b[4]);
	QPoint r((b[1]+b[3])/2, (b[2]+b[4])/2);
	Drop* d1 = getDrop(b[0]-1, m1);
	Drop* d2 = getDrop(b[0]-1, m2);
	if (!d1)return;
	if (!d2)return;
	d1->setMerge(r);
	d2->setMerge(r);
	d1->setEnd(b[0] + 1);
	d2->setEnd(b[0] + 1);
	Drop res(b[0] + 1, r);
	drops.push_back(res);
	blocks[r.x()][r.y()].addTained(b[0] + 1, res.color);

	
}

void Chip::addMix(string a)
{
	vector<int>b = parse(a);
	int n = (b.size() - 1) / 2;
	int t_start = b[0];
	Drop* d = getDrop(b[0] - 1, QPoint(b[1], b[2]));
	if (!d)return;
	for (int i = 0; i < n-1; i++)
	{
		QPoint s(b[2*i+1], b[2*i+2]);
		QPoint e(b[2*i+3], b[2*i+4]);
		d->setPath(b[0] + i, e);
		blocks[b[2 * i + 3]][b[2 * i + 4]].addTained(b[0] + i, d->color);
	
	}
}

bool Chip::dangerClose(QPoint & a, QPoint & b)
{
	QPoint c = a - b;
	return (c.x() >= -1 && c.x() <= 1 && c.y() >= -1 && c.y() <= 1);
}

bool Chip::staticCheck()
{
	for (int i = 0; i < drops.size(); i++)
	{
		for (int j = 0; j < drops.size(); j++)
		{
			if (i == j)continue;
			QPoint* a = drops[i].pos(t);
			QPoint* b = drops[j].pos(t);
			if (a&&b)
			{
				if (dangerClose(*a, *b))
				{
					return false;
				}
				
			}
		}
	}
	return true;
}

bool Chip::dynamicCheck()
{
	if (t == 0)return true;
	for (int i = 0; i < drops.size(); i++)
	{
		for (int j = 0; j < drops.size(); j++)
		{
			if (j == i)continue;
			QPoint* a = drops[i].pos(t);
			QPoint* b = drops[j].pos(t-1);
			if (a&&b)
			{
				if (dangerClose(*drops[i].pos(t), *drops[j].pos(t - 1)))
				{	if(drops[j].endTime!=t)
					return false;
				}
			}
		}
	}
	return true;
}

void Chip::soundEffect()
{
	bool move = false, split1 = false, split2 = false, merge = false;
	for (int i = 0; i < drops.size(); i++)
	{
		QPoint* last = drops[i].pos(t);
		QPoint* now = drops[i].pos(t+1);
		if (last&&now)
		{
			if (last != now)move = true;
		}
		if (drops[i].endTime == t + 1)
		{
			if (drops[i].spliting)split1 = true;
			if (drops[i].merging)merge = true;
		}
		if (drops[i].endTime == t+2)
		{
			if (drops[i].spliting)split2 = true;
			
		}
	}
	if (move)
	{
		QSound::play("hit.wav");
	}
	if (merge)QSound::play("death.wav");
	if (split1)QSound::play("wounded.wav");
	if (split2)QSound::play("scream.wav");

}



void Chip::setWash()
{

	for (int i = 1; i <= X; i++)
	{
		for (int j = 1; j <= Y; j++)
		{
			if (blocks[i][j].times.size() <= 1)continue;
			block* curBlock = &blocks[i][j];
			for (int k = 0; k < curBlock->times.size() - 1; k++)
			{
				int curTime = curBlock->times[k + 1] - 2;
				if (curTime <= curBlock->times[k])
				{
					washFailTime = min(washFailTime, curTime + 2);
					continue;
				}
				washTarget[curTime].push_back(QPoint(i, j));
				
			}
		}
	}


}

bool Chip::isWashing()
{
	for (int i = 0; i < washDrops.size(); i++)
	{
		if (washDrops[i].t == t)return true;
	}
	return false;
}

void Chip::updateTaint()
{
	for (int i = 0; i < drops.size(); i++)
	{
		QPoint* pos = drops[i].pos(t);
		if (!pos)continue;
		blocks[pos->x()][pos->y()].addTained(t, drops[i].color);
	}

}

WashDrop * Chip::nowWashing()
{
	for (int i = 0; i < washDrops.size(); i++)
	{
		if (washDrops[i].t == t)
		{
			return &washDrops[i];
		}
	}
	return nullptr;
}

void Chip::mousePressEvent(QMouseEvent * event)
{
	if (event->button() != Qt::RightButton)return;
	QPoint pos = event->pos();
	QPoint blockPos = pos2bolck(pos);
	if (blockPos.x() < 1 || blockPos.y() < 1 || blockPos.x() > X || blockPos.y() > Y)return;
	blocks[blockPos.x()][blockPos.y()].reverseBarrier();


}

void Chip::CheckDrops()
{
	for (int i = 0; i < drops.size(); i++)
	{
		QColor w = drops[i].color;
	}
}

