#pragma once

#include <QtWidgets/QMainWindow>
#include<qevent>
#include<QtWidgets>
#include<qpixmap.h>
#include<qimage.h>
#include "ui_PAINT.h"
#include<qpainter.h>
#include<cmath>

class PAINT : public QMainWindow
{
	Q_OBJECT

public:
	PAINT(QWidget *parent = Q_NULLPTR);

private:
	
	Ui::PAINTClass ui;
	void paintEvent(QPaintEvent* event);

	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void keyPressEvent(QKeyEvent* event);
	void drawPic(QPixmap& p);
	int m_angle = 0;
	double  rate = 0.5;
	/*bool eventFilter(QObject* obj, QEvent *event)
	{
		if (obj == ui.pushButton&&event->type() == QEvent::Paint)
		{
			QPixmap cover("Cover.jpg");
			drawPic(cover);
			return true;
		}
		return QMainWindow::eventFilter(obj, event);
	}*/
};
