#pragma once

#include <QDialog>
#include "ui_SeclectDlg.h"

class SeclectDlg : public QDialog
{
	Q_OBJECT

public:
	SeclectDlg(QWidget *parent = Q_NULLPTR);
	~SeclectDlg();

private:
	Ui::SeclectDlg ui;
};
