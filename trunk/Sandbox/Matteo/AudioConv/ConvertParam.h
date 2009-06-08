#ifndef CONVERTPARAM_H
#define CONVERTPARAM_H

#include <QDialog>
#include "ui_ConvertParam.h"

using namespace Ui;

class ConvertParam : public QDialog, public ConvertParamClass
{
	Q_OBJECT

public:
	ConvertParam(QWidget *parent = 0);
	~ConvertParam();

	double	GetFreq();
	int		GetBps();
	int		GetChanCount();
};

#endif // CONVERTPARAM_H
