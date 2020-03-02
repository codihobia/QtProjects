#include "InitDialg.h"

InitDialg::InitDialg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.Cancel, SIGNAL(clicked()), this, SLOT(OnCancel()));
	connect(ui.OK, SIGNAL(clicked()), this, SLOT(OnOK()));


}

InitDialg::~InitDialg()
{
}
void InitDialg::OnOK()
{
	 x = ui.X->text().toInt();
	 y = ui.Y->text().toInt();
	 ins = ui.IN->text();
	 outs = ui.OUT->text();
	emit getParameters(x, y,ins, outs);
	accept();
	return;
}
void InitDialg::OnCancel()
{
	reject();
}
