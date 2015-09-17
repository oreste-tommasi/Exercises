#include "qt_stackwidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Qt_Stackwidget w;
	w.show();
	return a.exec();
}
