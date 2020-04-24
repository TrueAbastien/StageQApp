#pragma once
#include <QtSquid/core/page/AdvancedPageDefine.h>
#include <QtSquid/sql/Query.h>

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