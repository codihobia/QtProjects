#include "PAINT.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PAINT w;
	w.show();
	return a.exec();
}
