#include "ivan_qttwowaycommunication.h"
#include <QtWidgets/QApplication>
#include <QSurfaceFormat>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QSurfaceFormat format;
	format.setDepthBufferSize(24);
	format.setStencilBufferSize(0);
	format.setVersion(1, 5);
	format.setRedBufferSize(8);
	format.setGreenBufferSize(8);
	format.setBlueBufferSize(8);
	format.setAlphaBufferSize(0);
	format.setProfile(QSurfaceFormat::CompatibilityProfile);
	QSurfaceFormat::setDefaultFormat(format);

	QSurfaceFormat theFormat = QSurfaceFormat::defaultFormat();
	int a1 = theFormat.depthBufferSize();
	int a2 = theFormat.stencilBufferSize();
	auto a3 = theFormat.version();
	int a4 = theFormat.redBufferSize();
	int a5 = theFormat.greenBufferSize();
	int a6 = theFormat.blueBufferSize();
	int a7 = theFormat.alphaBufferSize();
	QSurfaceFormat::OpenGLContextProfile a8 = theFormat.profile();



	Ivan_QtTwoWayCommunication w;
	w.show();

	return a.exec();
}
