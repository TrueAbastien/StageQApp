#include <AdvancedWindow.h>

// Creation
#include <QtSquid/core/page/creation/ItemCreationPage.h>

// Settings
#include <QtSquid/core/page/settings/StylesheetSettingPage.h>


CreationWindow::CreationWindow(QtSquid* parent)
	: AdvancedWindow(parent)
{
	ui.setupUi(this);

	allPages.append({ new ItemCreationPage(parent, this) });

	connect(ui.pagination, SIGNAL(currentChanged(int)), this, SLOT(setCurrentPage(int)));
	connect(ui.okButton, &QPushButton::pressed, [this]() { if (currentPage != nullptr) currentPage->pressOkButton(); });

	setCurrentPage(ui.pagination->currentIndex());
}

SettingWindow::SettingWindow(QtSquid* parent)
	: AdvancedWindow(parent)
{
	ui.setupUi(this);

	allPages.append({ new StylesheetSettingPage(parent, this) });

	connect(ui.pagination, SIGNAL(currentChanged(int)), this, SLOT(setCurrentPage(int)));
	connect(ui.okButton, &QPushButton::pressed, [this]() { if (currentPage != nullptr) currentPage->pressOkButton(); });

	setCurrentPage(ui.pagination->currentIndex());
}