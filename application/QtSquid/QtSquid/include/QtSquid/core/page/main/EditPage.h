#pragma once
#include <QtSquid/core/page/Page.h>
#include <QtSquid/sql/Query.h>
#include <QtSquid/tool/QStringHelper.h>

class EditPage : public Page
{
	Q_OBJECT

public:
	explicit EditPage(QtSquid* ref);

	void handle() override { }

private:
	Query* selectItemID, *updateEquipmentQty, *selectEquipmentQty,
		*selectConfigID, *insertEquipment, *deleteEquipment,
		*selectTypeName, *selectRoomName;

	bool isItemUpdatable();
	bool isItemSetable();

private slots:
	void AddElement();
	void RemoveElement();

	void TakeElement();
	void StoreElement();

	void onDatabaseConnect() override;

signals:
	void OpenCreationMenu();
};