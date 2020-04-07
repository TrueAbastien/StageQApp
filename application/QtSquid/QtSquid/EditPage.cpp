#include "EditPage.h"

EditPage::EditPage(QtSquid* ref)
	: Page(ref), createWindow(nullptr)
{
	connect(wndRef->ui.edit_addBtn, SIGNAL(pressed()), this, SLOT(OpenCreationWindow())); /// TEMP
}

void EditPage::OpenCreationWindow()
{
	createWindow = new ItemCreationWindow(wndRef);
	createWindow->exec();
}
