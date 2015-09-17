#include "qt_stackwidget.h"

Qt_Stackwidget::Qt_Stackwidget(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	back = NULL;
	stack = new QStackedWidget();
	QObject::connect(stack, SIGNAL(currentChanged(int)), this, SLOT(activeWidgetChanged(int)));
	stack->addWidget(new Homewidget(stack));
	setCentralWidget(stack);
}

Qt_Stackwidget::~Qt_Stackwidget()
{

}
//when new widget is inserted to stack
void Qt_Stackwidget::activeWidgetChanged(int index)
{
	// Current widget changed, we use menubar of the new widget
	QBaseWidget* current = static_cast<QBaseWidget*>(stack->widget(index));
	//changeCBA(current);
	if (current)
	{
		// NOTE: need to set focus for the active widget. 
		// Enviroment search CBA buttons from the active widget and use these.
		// CBA buttons for the active focused widget is set in changeCBA()
		current->setFocus();
		// Update menubar of the QMainWindow
		QMenuBar* menubar = this->menuBar();
		menubar->clear();
		for (int i = 0; i < current->GetMenuBar()->actions().count(); i++)
		{
			QAction *act = current->GetMenuBar()->actions()[i];

			menubar->addAction(act);
		}
		createBaseMenu();
	}
	// Set correct CBA buttons for the active widget
	changeCBA(current);
}
//Qt-articles.blogspot.com
void Qt_Stackwidget::createBaseMenu()
{
	// All widgets in QStackedWidget have this exit menu item
	menuBar()->addAction("Exit", this, SLOT(close()));
}

void Qt_Stackwidget::changeCBA(QBaseWidget* current)
{
	if (current)
	{
		QString classname = current->metaObject()->className();
		if (back != NULL)
		{
			this->menuBar()->removeAction(back);
			delete back;
			back = NULL;
			
		}
		if (classname == "Firstwidget" || classname == "Secwidget" || classname == "Thiredwidget")
		{
			// Change Back left softkey for QMyWidget2 and QMyWidget3
			createOptionsBackCBA(current);
		}
		else
		{
			// rest have Exit left softkey
			//createOptionsExitCBA(current);
		}
	}
}

void Qt_Stackwidget::createOptionsExitCBA(QWidget* current)
{

	back = new QAction("Exit", this);
	//back->setSoftKeyRole(QAction::NegativeSoftKey);
	QObject::connect(back, SIGNAL(triggered()), this, SLOT(close()));
	this->menuBar()->addAction(back);

}
//Qt-articles.blogspot.com
void Qt_Stackwidget::createOptionsBackCBA(QBaseWidget* current)
{
	// Create exit right CBA
	back = new QAction("Back", this);
	//back->setSoftKeyRole(QAction::NegativeSoftKey);
	QObject::connect(back, SIGNAL(triggered()), this, SLOT(activatePerviousView()));
	this->menuBar()->addAction(back);
}

int Qt_Stackwidget::activatePerviousView()
{
	int ret = -1;
	QString currentName = stack->currentWidget()->metaObject()->className();
	QString previous;

	int count = stack->count();
	for (int i = stack->count() - 1; i >= 0; i--)
	{
		QWidget* w = stack->widget(i);
		if (w->metaObject()->className() == currentName)
		{

			{
				i--;
				previous = stack->widget(i)->metaObject()->className();
				ret = 0;
				stack->setCurrentWidget(stack->widget(i));
				stack->removeWidget(w);
				delete w;
				// Activate prevous widget
				//activateWidget(previous);
			}
			break;
		}
	}
	return ret;
}

Homewidget::Homewidget(QStackedWidget* stackedWidget, QWidget *parent)
	: QBaseWidget(parent)
{
	//Create 3 Buttonss
	BaseStackwidget = stackedWidget;
	widget1 = new QPushButton("Create message");
	QObject::connect(widget1, SIGNAL(clicked()), this, SLOT(CreateFirstwidget()));
	widget2 = new QPushButton("Inbox");
	QObject::connect(widget2, SIGNAL(clicked()), this, SLOT(CreateSecwidget()));
	widget3 = new QPushButton("Outbox");
	QObject::connect(widget3, SIGNAL(clicked()), this, SLOT(CreateThiredwidget()));

	createMenus();
	//Add the widget to layouts
	layout = new QVBoxLayout();
	layout->addWidget(widget1);
	layout->addWidget(widget2);
	layout->addWidget(widget3);
	setLayout(layout);
}

Homewidget::~Homewidget()
{
	int gg = 0;
}
//Create the first widget
void Homewidget::CreateFirstwidget()
{
	Firstwidget *first = new Firstwidget(BaseStackwidget);
	BaseStackwidget->addWidget(first);
	BaseStackwidget->setCurrentWidget(first);
}
//Create the sec widget
void Homewidget::CreateSecwidget()
{

	Secwidget *sec = new Secwidget(BaseStackwidget);
	BaseStackwidget->addWidget(sec);
	BaseStackwidget->setCurrentWidget(sec);
}
//Create the thired widget
void Homewidget::CreateThiredwidget()
{
	Thiredwidget *thiredwid = new Thiredwidget(BaseStackwidget);
	BaseStackwidget->addWidget(thiredwid);
	BaseStackwidget->setCurrentWidget(thiredwid);
}

QMenuBar* Homewidget::GetMenuBar() const
{
	return menuBar;
}
//Qt-articles.blogspot.com
void Homewidget::createMenus()
{
	// Create menubar for this widget
	// We sets these menu items into into QMainWindow menu when this widget is active
	menuBar = new QMenuBar();

	FirstwidgetAction = new QAction("Create message", menuBar);
	menuBar->addAction(FirstwidgetAction);
	connect(FirstwidgetAction, SIGNAL(triggered()), this, SLOT(CreateFirstwidget()));

	SecwidgetAction = new QAction("Inbox", menuBar);
	menuBar->addAction(SecwidgetAction);
	connect(SecwidgetAction, SIGNAL(triggered()), this, SLOT(CreateSecwidget()));

	ThiredwidgetAction = new QAction("Outbox", menuBar);
	menuBar->addAction(ThiredwidgetAction);
	connect(ThiredwidgetAction, SIGNAL(triggered()), this, SLOT(CreateThiredwidget()));
}

Firstwidget::Firstwidget(QStackedWidget* stackedWidget, QWidget *parent)
	:QBaseWidget(parent)
{
	BaseStackwidget = stackedWidget;
	widget2 = new QPushButton("Text Message");
	bool val = QObject::connect(widget2, SIGNAL(clicked()), this, SLOT(CreateSecwidget()));
	widget3 = new QPushButton("Multimedia Message");
	QObject::connect(widget3, SIGNAL(clicked()), this, SLOT(CreateThiredwidget()));

	createMenus();

	layout = new QVBoxLayout();
	layout->addWidget(widget2);
	layout->addWidget(widget3);

	setLayout(layout);
}

void Firstwidget::CreateSecwidget()
{
	Secwidget *sec = new Secwidget(BaseStackwidget);
	BaseStackwidget->addWidget(sec);
	BaseStackwidget->setCurrentWidget(sec);
}
//Qt-articles.blogspot.com
void Firstwidget::CreateThiredwidget()
{
	Thiredwidget *thired = new Thiredwidget(BaseStackwidget);
	BaseStackwidget->addWidget(thired);
	BaseStackwidget->setCurrentWidget(thired);
}

void Firstwidget::createMenus()
{
	menuBar = new QMenuBar();

	SecwidgetAction = new QAction("Text Message", menuBar);
	menuBar->addAction(SecwidgetAction);
	connect(SecwidgetAction, SIGNAL(triggered()), this, SLOT(CreateSecwidget()));

	ThiredwidgetAction = new QAction("Multimedia Message", menuBar);
	menuBar->addAction(ThiredwidgetAction);
	connect(ThiredwidgetAction, SIGNAL(triggered()), this, SLOT(CreateThiredwidget()));
}

QMenuBar* Firstwidget::GetMenuBar() const
{
	return menuBar;
}

Secwidget::Secwidget(QStackedWidget* stackedWidget, QWidget *parent)
	:QBaseWidget(parent)
{
	BaseStackwidget = stackedWidget;
	widget3 = new QLabel("You are in the last screen, plese press back to go to previous screen");

	bool val = QObject::connect(widget3, SIGNAL(clicked()), this, SLOT(CreateThiredwidget()));

	createMenus();
	layout = new QVBoxLayout();
	layout->addWidget(widget3);
	setLayout(layout);

}
//Qt-articles.blogspot.com
void Secwidget::CreateThiredwidget()
{
	Thiredwidget *thired = new Thiredwidget(BaseStackwidget);
	BaseStackwidget->addWidget(thired);
	BaseStackwidget->setCurrentWidget(thired);
	//add the code to create thired widget, and with menu exit and right back
}

void Secwidget::createMenus()
{
	menuBar = new QMenuBar();
	//connect(menuBar, SIGNAL(triggered()),this, SLOT(CreateThiredwidget()));
	//ThiredwidgetAction = new QAction("Thired Widget",menuBar);
	//menuBar->addAction(ThiredwidgetAction);

}

QMenuBar* Secwidget::GetMenuBar() const
{
	return menuBar;
}

Thiredwidget::Thiredwidget(QStackedWidget* stackedWidget, QWidget *parent)
	:QBaseWidget(parent)
{
	BaseStackwidget = stackedWidget;
	thiredwidgetLabel = new QLabel("You are in the last screen, plese press back to go to previous screen");
	createMenus();
	layout = new QVBoxLayout();
	layout->addWidget(thiredwidgetLabel);
	setLayout(layout);
}

void Thiredwidget::createMenus()
{
	menuBar = new QMenuBar();
	//connect(menuAction2, SIGNAL(triggered()),this, SLOT(createWidget2()));
}

QMenuBar* Thiredwidget::GetMenuBar() const
{
	return menuBar;
}
