#ifndef IVAN_QTTWOWAYCOMMUNICATION_H
#define IVAN_QTTWOWAYCOMMUNICATION_H

#include <QtWidgets/QMainWindow>
#include "ui_ivan_qttwowaycommunication.h"
#include "CInterfaceForDll.h"

class CMyClass;

class Ivan_QtTwoWayCommunication : public QMainWindow, public CInterfaceForDll
{
	Q_OBJECT

public:
	Ivan_QtTwoWayCommunication(QWidget *parent = 0);
	~Ivan_QtTwoWayCommunication();

	bool		ShowDialog( char* inMsg );
	void		CallDllToShowDialog();
	void		SwitchFullScreen( bool inVal );

private:
	Ui::Ivan_QtTwoWayCommunicationClass ui;

	CMyClass* mDllObj;
};

#endif // IVAN_QTTWOWAYCOMMUNICATION_H
