#pragma once
#include <QtSquid/core/page/Page.h>
#include <QtSquid/sql/Query.h>
#include <QtSquid/tool/QStringHelper.h>

/**
* EditPage class
*
* Page used to handle equipment and item related data in MySQL database.
* Allow to perform 4 basic actions:
* - Add equipement to the database
* - Remove equipement from the database
* - Take equipement if available
* - Store equipement if existant
*/
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