#include "MP.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MP w;
	w.show();
	return a.exec();
}
