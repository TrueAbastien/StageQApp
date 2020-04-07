#pragma once
#include <QDialog>
#include "ui_ItemCreation.h"
#include "Query.h"

class ItemCreationWindow : public QDialog
{
	Q_OBJECT

public:
	explicit ItemCreationWindow(QWidget* parent = 0);
	~ItemCreationWindow();

private:
	Ui::ItemCreation ui;
	Query* insertItem;

private slots:
	void CreateItem();
};