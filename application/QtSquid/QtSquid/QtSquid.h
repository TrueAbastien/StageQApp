#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Search.h"

class QtSquid : public QMainWindow
{
	Q_OBJECT

public:
	QtSquid(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtSquidClass ui;
};
