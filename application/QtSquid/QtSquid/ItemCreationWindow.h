#pragma once
#include <QDialog>
#include "ui_Creation.h"
#include <QtSquid/sql/Query.h>
#include <QtSquid.h>
#include <QtSquid/tool/QStringHelper.h>

class ItemCreationWindow : public QDialog
{
	Q_OBJECT

public:
	explicit ItemCreationWindow(QtSquid* parent = 0);
	~ItemCreationWindow();

private:
	Ui::Creation ui;
	QtSquid* app;
	Query* insertItem, * insertEquipment, * selectItemID;

private slots:
	void CreateItem();
};