#pragma once
#include <QDialog>
#include "ui_Creation.h"
#include <QtSquid/sql/Query.h>
#include <QtSquid.h>

class CreationPage;

class CreationWindow : public QDialog
{
	Q_OBJECT

public:
	explicit CreationWindow(QtSquid* parent = 0);
	~CreationWindow();

	Ui::Creation ui;

private:
	CreationPage* currentPage = nullptr;
	QList<CreationPage*> allPages;

private slots:
	void setCurrentPage(int pageID);
};