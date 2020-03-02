#include "Chip.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Chip w;
	w.show();
	return a.exec();
}
