#pragma once

#include <QtWidgets/QMainWindow>
#include<qmediaservice.h>
#include<qmediaplayer.h>
#include "ui_Chip.h"
#include<qtimer.h>
#include<iostream>
#include<fstream>
#include<qevent.h>
#include"Drop.h"
#include"GBK.h"
#include"block.h"
#include<string>
#include<qpainter.h>
#include<qmessagebox.h>
#include<qsound.h>
#include"InitDialg.h"
#include"state.h"
#include"WashDrop.h"
class Chip : public QMainWindow
{
	Q_OBJECT

public:
	Chip(QWidget *parent = Q_NULLPTR);
private slots:
	void OnRead();
	void OnInit();
	void OnNextStep();
	void OnLastStep();
	void OnStart();
	void OnHalt();
	void OnReset();
	void OnWash(bool a );

private:
	vector<WashDrop>washDrops;
	vector<Drop>drops;
	vector<QPoint>washTarget[1200];
	WashDrop* curWash = nullptr;

	QTimer* secTimer;
	QTimer* frameTimer;
	int t=-1;
	int tWash = -1;
	int grid = 50;
	int X=3, Y=3;
	int edge = 200;
	int diameter = 50;
	int maxTime = 1;
	int washFailTime = 12000;
	bool initialized = false;
	bool wash = false;
	block** blocks;
	Ui::ChipClass ui;
	virtual void paintEvent(QPaintEvent* event);
	virtual void timerEvent(QTimerEvent* event);
	QPoint pos2bolck(QPoint& p);
	QPoint block2pos(QPoint& p);
	void drawBlocks();
	void drawDrops();
	void drawWashDrops();
	void drawInOut();
	void drawTaints();
	void drawNumbers();
	void drawBarriers();
	void setParameters(int _x, int _y, QString ins, QString outs);
	vector<int>parse(string a);
	Drop* getDrop(int ti,int a, int b);
	Drop* getDrop(int ti,QPoint a);
	int getDropIndex(int ti,int a, int b);
	int getDropIndex(int ti,QPoint a);
	void addInput(string a);
	void addOutput(string a);
	void addMove(string a);
	void addSplit(string a);
	void addMerge(string a);
	void addMix(string a);
	bool dangerClose(QPoint&a, QPoint&b);
	bool staticCheck();
	bool dynamicCheck();
	void soundEffect();
	void setWash();
	bool isWashing();
	void updateTaint();
	WashDrop* nowWashing();
	virtual void mousePressEvent(QMouseEvent* event);
	void CheckDrops();
};
