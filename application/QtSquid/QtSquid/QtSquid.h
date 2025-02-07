#pragma once
#include <QtWidgets/QMainWindow>
#include <QKeyEvent>
#include "ui_QtSquid.h"

#include <QtSquid/sql/Database.h>
#include <QtSquid/tool/BarcodeScanner.h>
#include <QtSquid/core/cache/StyleSheetCache.h>
#include <QtSquid/core/file/SettingFile.h>

class Page;
class SettingWindow;
class CreationWindow;

/**
* QtSquid class
*
* Main Window class used to store and handle the most important propreties.
* Used as a main class object for the whole application.
*
* Will handle every secondary windows and each primary page.
*/
class QtSquid : public QMainWindow
{
	Q_OBJECT

public:
	QtSquid(QWidget *parent = Q_NULLPTR);

	Ui::QtSquidClass ui;
	QList<Page*> pages;

	Database database;
	BarcodeScanner barcodeScanner;
	StyleSheetCache styleSheetCache;

	SettingFile preferenceData, quickLinksData;

private:
	CreationWindow* createWindow;
	SettingWindow* settingWindow;

protected:
	void keyPressEvent(QKeyEvent* evt) override;

public slots:
	void OpenSettingWindow();
	void OpenCreationWindow();

signals:
	void key_press(QString);
};
