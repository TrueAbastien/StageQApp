#pragma once
#include <QtSquid/core/page/CreationPage.h>
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