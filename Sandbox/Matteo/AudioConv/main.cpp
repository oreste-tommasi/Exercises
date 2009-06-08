#include <QtGui/QApplication>
#include "AudioConv.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AudioConv w;
	w.show();
	return a.exec();
}
