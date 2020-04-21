#include <CreationWindow.h>

#include <QtSquid/core/page/creation/ItemCreationPage.h>
//

CreationWindow::CreationWindow(QtSquid* parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.pagination, SIGNAL(currentChanged(int)), this, SLOT(setCurrentPage(int)));
	connect(ui.okButton, &QPushButton::pressed, [this]() { if (currentPage != nullptr) currentPage->pressOkButton(); });

	allPages.append(new ItemCreationPage(parent, this));
	//

	setCurrentPage(ui.pagination->currentIndex());
}

CreationWindow::~CreationWindow()
{
	if (currentPage != nullptr)
		delete currentPage;
	foreach(CreationPage * page, allPages)
		delete page;
}

void CreationWindow::setCurrentPage(int pageID)
{
	if (pageID < 0 || pageID >= allPages.length())
		currentPage = nullptr;
	else currentPage = allPages.at(pageID);
}