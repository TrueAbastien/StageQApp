#pragma once

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>
#include "ui_ApplicationWnd.h"
#include "Database.h"
#include "BarcodeScanner.h"

class ApplicationWnd : public QMainWindow
{
	Q_OBJECT

public:
	ApplicationWnd(QWidget *parent = Q_NULLPTR);

	QString __latest_key_pressed;

private:
	Ui::ApplicationWndClass ui;

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
