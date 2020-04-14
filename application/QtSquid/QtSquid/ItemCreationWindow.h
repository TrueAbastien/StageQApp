#pragma once
#include <QDialog>
#include "ui_ItemCreation.h"
#include "Query.h"
#include "QtSquid.h"
#include "QStringHelper.h"

class ItemCreationWindow : public QDialog
{
	Q_OBJECT

public:
	explicit ItemCreationWindow(QtSquid* parent = 0);
	~ItemCreationWindow();

private:
	Ui::ItemCreation ui;
	QtSquid* app;
	Query* insertItem, * insertEquipment, * selectItemID;

private slots:
	void CreateItem();
};