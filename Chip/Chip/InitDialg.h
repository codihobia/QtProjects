#pragma once

#include <QDialog>
#include<qmessagebox.h>
#include "ui_InitDialg.h"

class InitDialg : public QDialog
{
	Q_OBJECT

public:
	InitDialg(QWidget *parent = Q_NULLPTR);
	~InitDialg();
	int x, y;
	QString ins, outs;
signals:
	void getParameters(int x, int y, QString ins, QString outs);
		

private slots:
	void OnOK();
	void OnCancel();

private:
	Ui::InitDialg ui;

};
