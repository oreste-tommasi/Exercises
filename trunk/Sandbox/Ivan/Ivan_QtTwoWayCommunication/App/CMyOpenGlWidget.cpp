
#include "CMyOpenGlWidget.h"




CMyOpenGlWidget::CMyOpenGlWidget(QWidget * parent , Qt::WindowFlags f )
	: QOpenGLWidget(parent,f)
{
	setFixedSize(200, 200);
}

CMyOpenGlWidget::~CMyOpenGlWidget()
{
}


void	
CMyOpenGlWidget::initializeGL()
{
	QSurfaceFormat theFormat = format();

	int a1 = theFormat.depthBufferSize();
	int a2 = theFormat.stencilBufferSize();
	auto a3 = theFormat.version();
	int a4 = theFormat.redBufferSize();
	int a5 = theFormat.greenBufferSize();
	int a6 = theFormat.blueBufferSize();
	int a7 = theFormat.alphaBufferSize();
	QSurfaceFormat::OpenGLContextProf ile a8 = theFormat.profile();

	int gg = 0;
}

void	
CMyOpenGlWidget::resizeGL(int w, int h)
{
	if( mRenderingCore )
		mRenderingCore->resizeGL(w,h);
}

void	
CMyOpenGlWidget::paintGL()
{
	if( mRenderingCore )
		mRenderingCore->paintGL();
}

