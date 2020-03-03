#pragma once

#include <QtWidgets/QWidget>
#include<QtWidgets>
#include "ui_Clock.h"
#include<qtimer.h>
#include<qevent>
#include<qpainter.h>
class Clock : public QWidget
{
	Q_OBJECT

public:
	Clock(QWidget *parent = Q_NULLPTR);

private:
	Ui::ClockClass ui;
	int extent = 200;
	int edge = 200;
	QPoint mid;
	QTimer* timer;
	int t = 0;
	void paintEvent(QPaintEvent* event);
private slots:

	void OnStart();
	void OnPause();
	void OnReset();
	void OnNext();
};
