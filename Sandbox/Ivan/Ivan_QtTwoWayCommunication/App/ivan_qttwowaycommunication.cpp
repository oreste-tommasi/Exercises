#include <QLabel>
#include <QMessageBox>

#include "ivan_qttwowaycommunication.h"

#include <QWindow>

#include "CMyClass.h"
#include "CMyOpenGlWidget.h"




Ivan_QtTwoWayCommunication::Ivan_QtTwoWayCommunication(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	mDllObj = CMyClass::CMyClassFactory( this );

	ui.mLabel->setText( QString("ciao")  );

	ui.mLabel->setText( QString(mDllObj->GetString())  );

	connect( ui.mShowDialogButton, &QPushButton::clicked, this, &Ivan_QtTwoWayCommunication::CallDllToShowDialog );

	connect( ui.mFullScreenButton, &QPushButton::toggled, this, &Ivan_QtTwoWayCommunication::SwitchFullScreen );


/*	QSurfaceFormat format;
	format.setDepthBufferSize(24);
	format.setStencilBufferSize(0);
	format.setVersion(3, 0);
	format.setRedBufferSize(8);
	format.setGreenBufferSize(8);
	format.setBlueBufferSize(8);
	format.setAlphaBufferSize(0);
	format.setProfile(QSurfaceFormat::NoProfile);*/


	CMyOpenGlWidget* mGlWidget = new CMyOpenGlWidget( this );

	QWindow* mFooWin = new QWindow();
	//mGlWidget->createWindowContainer( mFooWin );

	mGlWidget->lower();

	ui.mGridLayout->addWidget( mGlWidget, 0, 1, -1, -1 );

	//mGlWidget->setFormat(format); // must be called before the widget or its parent window gets shown

	//CMyOpenGlWidget* mGlWidget2 = new CMyOpenGlWidget( this );
	//ui.mGridLayout->addWidget( mGlWidget2, 0, 2 );

}

Ivan_QtTwoWayCommunication::~Ivan_QtTwoWayCommunication()
{
	CMyClass::DestroyObj( mDllObj );
}

bool		
Ivan_QtTwoWayCommunication::ShowDialog( char* inMsg )
{
	QMessageBox::StandardButton	button = QMessageBox::warning( this, "dialog", inMsg );
	return button == QMessageBox::Ok;

	/*QMessageBox* msgBox = new QMessageBox;
	msgBox->addButton( "ok", QMessageBox::AcceptRole );
	msgBox->setText( "prova dialog " );

	msgBox->*/

}

void
Ivan_QtTwoWayCommunication::CallDllToShowDialog()
{
	mDllObj->ShowDialog();
}

void
Ivan_QtTwoWayCommunication::SwitchFullScreen( bool inVal )
{
	if( inVal )
	{
		//setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | windowFlags() );
		showFullScreen();
	}
	else
	{
		/*flags

		setWindowFlags( Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | windowFlags() );*/
		showNormal();
	}
}


