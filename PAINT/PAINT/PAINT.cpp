#include "PAINT.h"

PAINT::PAINT(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//ui.pushButton->installEventFilter(this);
}

void PAINT::paintEvent(QPaintEvent * event)
{
	QPixmap cover("Cover.jpg");
	//QPainter painter(this);
	//QRect rect(50, 50, 500, 500);
	//painter.drawImage(rect, cover.toImage());
	drawPic(cover);


}

void PAINT::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_angle += 2;
	}
	else if (event->button() == Qt::RightButton)
	{
		m_angle -= 2;
	}
	update();

}

void PAINT::mouseMoveEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_angle += 2;
	}
	else if (event->button() == Qt::RightButton)
	{
		m_angle -= 2;
	}
	update();
}

void PAINT::mouseReleaseEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_angle += 2;
	}
	else if (event->button() == Qt::RightButton)
	{
		m_angle -= 2;
	}
	update();
}

void PAINT::keyPressEvent(QKeyEvent * event)
{
	int ke = event->key();
	if (ke == Qt::Key_Up || ke == Qt::Key_Right)
	{
		m_angle += 1;
	}
	else if (ke == Qt::Key_Left || ke == Qt::Key_Down)
	{
		m_angle -= 1;
	}
	update();
	QMainWindow::keyPressEvent(event);
	return;
}

void PAINT::drawPic(QPixmap & p)
{
	int w = p.width();
	int h = p.height();
	QPainter painter(this);
	static double edgeScale = 0.05;
	int space = 100;
	int edgeW = edgeScale * w;
	int edgeH = edgeScale * h;
	QRect rect1(space, space, (2 * edgeW + w)/2, (2 * edgeH + h)/2);
	QRect rect2(w/4, h/4, w/2, h/2);
	QTransform t;
	
	int deltaX;
	int deltaY;
	m_angle %= 360;
	if (m_angle < 180)
	{

		deltaX = m_angle * rate;
		deltaY = deltaX;
	}
	else
	{
		deltaX = (360 - m_angle)*rate;
		deltaY = deltaX;
	}
	t.translate(deltaX+space+ (2 * edgeW + w) / 4, deltaY+space+(2 * edgeH + h) / 4);
	t.rotate(m_angle, Qt::YAxis);
	t.rotate(m_angle,Qt::ZAxis);
	t.translate(-space-(2*edgeW+w)/4, -deltaY-(2 * edgeH + h) / 4);

	painter.setTransform(t);
	painter.setBrush(QColor(0, 50, 250));
	
	painter.drawImage(rect1,p.toImage(),rect2);

}
