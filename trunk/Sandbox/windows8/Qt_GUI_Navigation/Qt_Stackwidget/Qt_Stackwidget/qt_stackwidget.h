#ifndef QT_STACKWIDGET_H
#define QT_STACKWIDGET_H

#include <QtWidgets/QMainWindow>
#include "ui_qt_stackwidget.h"
#include <QtGui>
#include <QtWidgets>

class QBaseWidget;

class Qt_Stackwidget : public QMainWindow
{
	Q_OBJECT

public:
	Qt_Stackwidget(QWidget *parent = 0);
	~Qt_Stackwidget();
	void createBaseMenu();
	void changeCBA(QBaseWidget* current);
	void createOptionsBackCBA(QBaseWidget* current);
	void createOptionsExitCBA(QWidget* current);
	QAction* back;

	public slots:
	int activatePerviousView();



public:
	Ui::Qt_StackwidgetClass ui;
	QStackedWidget *stack;

	private slots:
	void activeWidgetChanged(int index);
};

class QBaseWidget : public QWidget
{
	Q_OBJECT

public:
	QBaseWidget(QWidget *parent = 0)
	{

	}
	virtual ~QBaseWidget()
	{

	}

public:

	// Returns widget menu
	virtual QMenuBar* GetMenuBar() const = 0;

	// Exit from the app        
protected:
	// Widget own menubar
	QMenuBar*           menuBar;

	// Pointer to QStackedWidget where all views exists
	QStackedWidget*     BaseStackwidget;
};

class Homewidget : public QBaseWidget
{
	Q_OBJECT

public:
	Homewidget(QStackedWidget* stackedWidget, QWidget *parent = 0);
	~Homewidget();

	QMenuBar* GetMenuBar() const;
	void createMenus();


	public slots:
	void CreateFirstwidget();
	void CreateSecwidget();
	void CreateThiredwidget();

private:
	QMenuBar *menuBar;
	QPushButton *widget1;
	QPushButton *widget2;
	QPushButton *widget3;
	QVBoxLayout *layout;

	QAction *FirstwidgetAction;
	QAction *SecwidgetAction;
	QAction *ThiredwidgetAction;


};
//First widget class
class Firstwidget : public QBaseWidget
{
	Q_OBJECT

public:
	Firstwidget(QStackedWidget* stackedWidget, QWidget *parent = 0);
	~Firstwidget()
	{
		int gg = 0;
	}

	QMenuBar* GetMenuBar() const;
	void createMenus();

	public slots:
	void CreateSecwidget();
	void CreateThiredwidget();

private:
	QMenuBar *menuBar;

	QPushButton *widget2;
	QPushButton *widget3;
	QVBoxLayout *layout;

	QAction *SecwidgetAction;
	QAction *ThiredwidgetAction;

};
//Second widget class
class Secwidget : public QBaseWidget
{
	Q_OBJECT

public:
	Secwidget(QStackedWidget* stackedWidget, QWidget *parent = 0);
	~Secwidget()
	{
		int gg = 0;
	}

	QMenuBar* GetMenuBar() const;
	void createMenus();

	public slots:
	//void CreateSecwidget();
	void CreateThiredwidget();

private:
	QMenuBar *menuBar;

	QLabel *widget3;
	QVBoxLayout *layout;
	QLabel *thiredwidgetlabel;

	QAction *ThiredwidgetAction;

};

class Thiredwidget : public QBaseWidget
{
	Q_OBJECT

public:
	Thiredwidget(QStackedWidget* stackedWidget, QWidget *parent = 0);
	~Thiredwidget()
	{
		int gg = 0;
	}
	QMenuBar* GetMenuBar() const;
	void createMenus();

private:
	QMenuBar *menuBar;
	QVBoxLayout *layout;
	QLabel *thiredwidgetLabel;
};

#endif // QT_STACKWIDGET_H
