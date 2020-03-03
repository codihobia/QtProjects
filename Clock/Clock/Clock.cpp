#include "Clock.h"

Clock::Clock(QWidget *parent)
	: QWidget(parent),timer(new QTimer(this))
{
	ui.setupUi(this);
	
	connect(ui.start, SIGNAL(clicked()), this, SLOT(OnStart()));
	connect(ui.pause, SIGNAL(clicked()), this, SLOT(OnPause()));
	connect(ui.reset, SIGNAL(clicked()), this, SLOT(OnReset()));
	timer->setInterval(1000);
	
	connect(timer, SIGNAL(timeout()), this, SLOT(OnNext()));
	//timer->start();

}

void Clock::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	if (width() > height())
		extent = height() - edge;
	else
		extent = width() - edge;
	mid.setX((width() - extent) / 2 + extent / 2);
	mid.setY((height() - extent) / 2 + extent / 2);
	painter.translate(width() / 2, height() / 2);

	QPen pen;
	pen.setColor(Qt::black);
	pen.setWidth(3);
	painter.setPen(pen);
	for (int angle = 0; angle < 360; angle +=6)
	{
		painter.save();
		painter.rotate(angle + 180);
		painter.drawLine(extent*0.4, 0, extent*0.48, 0);
		painter.restore();
	}
	QPolygon polygon1;
	QPolygon polygon2;
	painter.rotate(t*6%360);
	polygon1 << QPoint(-0.02*extent, 0) << QPoint(0.02*extent, 0) << QPoint(0, -0.4*extent);
	polygon1 << QPoint(-0.02*extent, 0) << QPoint(0.02*extent, 0) << QPoint(0, 0.02*extent);
	painter.setPen(Qt::NoPen);
	painter.setBrush(QColor(255, 0, 0, 120));
	painter.drawPolygon(polygon1);
	painter.drawPolygon(polygon2);


}

void Clock::OnStart()
{
	timer->start();
	update();

}

void Clock::OnPause()
{
	timer->stop();
	update();
}

void Clock::OnReset()
{
	if (timer->isActive())return;
	t = 0;
	ui.lcdNumber->display(t);
	update();
}

void Clock::OnNext()
{
	t++;
	ui.lcdNumber->display(t);
	update();
}
