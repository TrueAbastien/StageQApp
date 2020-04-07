#pragma once
#include "Page.h"
#include "ItemCreationWindow.h"

class EditPage : public Page
{
	Q_OBJECT

public:
	explicit EditPage(QtSquid* ref);

	void handle() override { }

private:
	ItemCreationWindow* createWindow;

private slots:
	void OpenCreationWindow();
};