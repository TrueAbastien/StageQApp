#pragma once
#include <QDialog>
#include <QtSquid/core/page/AdvancedPage.h>

#include "ui_Settings.h"
#include "ui_Creation.h"


class AdvancedWindow : public QDialog
{
	Q_OBJECT

public:
	AdvancedWindow(QWidget* parent = 0)
		: QDialog(parent)
	{
		//exec();
		close();
	}

	virtual void onOpen(QString pageName) = 0;

protected:
	AdvancedPage* currentPage = nullptr;
	QList<AdvancedPage*> allPages;

protected slots:
	void setCurrentPage(int pageID)
	{
		if (pageID < 0 || pageID >= allPages.size())
			currentPage = nullptr;
		else currentPage = allPages.at(pageID);
	}
};

//-----------------------------------------------------------------------------------------------//

class CreationWindow : public AdvancedWindow
{
	Q_OBJECT

public:
	CreationWindow(QtSquid* parent = 0);
	void onOpen(QString pageName) { }

	Ui::Creation ui;
};

class SettingWindow : public AdvancedWindow
{
	Q_OBJECT

public:
	SettingWindow(QtSquid* parent = 0);
	void onOpen(QString pageName) { }

	Ui::Settings ui;
};