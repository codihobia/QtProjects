#include "WashDrop.h"



WashDrop::WashDrop()
{
	color = QColor(0, 128, 255);
}

WashDrop::WashDrop(vector<QPoint> _path,int _t):path(_path),t(_t)
{
	color = QColor(0, 128, 255);
}


WashDrop::~WashDrop()
{
}
