#pragma once

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>
#include "ui_QtSquid.h"
#include "Database.h"
#include "BarcodeScanner.h"

class Page;

class QtSquid : public QMainWindow
{
	Q_OBJECT

public:
	QtSquid(QWidget *parent = Q_NULLPTR);

	Ui::QtSquidClass ui;
	QList<Page*> pages;

	QString __latest_key_pressed;
	QString __currentQuery = "";

private:
	Database db;
	BarcodeScanner bs;

protected:
	void keyPressEvent(QKeyEvent* evt) override;

private slots:

	void connectDatabase();
	void runCurrentQuery();

	void writeInEdit();

signals:
	void key_press();
};
