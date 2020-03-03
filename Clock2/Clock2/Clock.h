#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Clock.h"
#include<qtimer.h>
#include<qevent>
#include<qpainter.h>
class Clock : public QMainWindow
{
	Q_OBJECT

public:
	Clock(QWidget *parent = Q_NULLPTR);

private:
	Ui::ClockClass ui;
};
