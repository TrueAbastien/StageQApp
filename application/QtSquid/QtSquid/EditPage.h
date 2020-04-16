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
	Query* selectItemID, *updateEquipmentQty, *selectEquipmentQty,
		*selectConfigID, *insertEquipment, *deleteEquipment,
		*selectTypeName, *selectRoomName;

	bool isItemUpdatable();
	bool isItemSetable();

	void OpenCreationWindow();

private slots:
	void AddElement();
	void RemoveElement();

	void TakeElement();
	void StoreElement();

	void onDatabaseConnect() override;
};