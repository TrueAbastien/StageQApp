#pragma once

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>
#include "ui_QtSquid.h"

#include "Database.h"
#include "BarcodeScanner.h"
#include "StyleSheetCache.h"
#include "StyleSheetWindow.h"
#include "SettingFile.h"


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

	Database database;
	BarcodeScanner barcodeScanner;
	StyleSheetCache styleSheetCache;

private:
	StyleSheetWindow* styleSheetWindow;
	SettingFile preferenceData, quickLinksData;

protected:
	void keyPressEvent(QKeyEvent* evt) override;

private slots:

	void runCurrentQuery();

	void writeInEdit();

	void openStyleSheetMenu();
	void changeStyleSheet(QString styleSheet);

signals:
	void key_press();
};
