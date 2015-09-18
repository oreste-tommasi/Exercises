#ifndef CMYOPENGLWIDGET_H
#define CMYOPENGLWIDGET_H

#include <QOpenGLWidget>

#include "CMyClass.h"

class CMyOpenGlWidget : public QOpenGLWidget
{
	Q_OBJECT

public:
	CMyOpenGlWidget(QWidget * parent = 0, Qt::WindowFlags f = 0);
	~CMyOpenGlWidget();

	void	SetRenderingCore( CMyClass* inRenderingCore ) { mRenderingCore = inRenderingCore; }

	virtual void	initializeGL();
	virtual void	resizeGL(int w, int h);
	virtual void	paintGL();

private:
	CMyClass*  mRenderingCore;
};

#endif // CMYOPENGLWIDGET_H
