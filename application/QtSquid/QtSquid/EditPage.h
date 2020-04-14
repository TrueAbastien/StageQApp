#pragma once
#include "Page.h"
#include "ItemCreationWindow.h"
#include "Query.h"
#include "QStringHelper.h"

class EditPage : public Page
{
	Q_OBJECT

public:
	explicit EditPage(QtSquid* ref);

	void handle() override { }

private:
	ItemCreationWindow* createWindow;
	Query* selectItemID, *updateEquipmentQty, *selectEquipmentQty;

	bool isItemUpdatable();
	void OpenCreationWindow();

private slots:
	void AddElements();
	void RemoveElements();
};