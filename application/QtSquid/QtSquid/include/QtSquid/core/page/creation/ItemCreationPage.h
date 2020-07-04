#pragma once
#include <QtSquid/core/page/AdvancedPageDefine.h>
#include <QtSquid/sql/Query.h>

/**
* ItemCreationPage class
*
* Creation page used to add a new item to the database whenever necessary.
* Called in Edit Page when a new item barcode is specified.
*/
class ItemCreationPage : public CreationPage
{
	Q_OBJECT

public:
	ItemCreationPage(QtSquid* ref, CreationWindow* wnd);
	~ItemCreationPage();

	void handle() override { }
	void pressOkButton() override;

private:
	Query* insertItem, * insertEquipment, * selectItemID;
};