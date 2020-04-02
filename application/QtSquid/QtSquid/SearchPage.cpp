#include "SearchPage.h"

SearchPage::SearchPage(QtSquid* ref)
	: Page(ref)
{
	connect(wndRef->ui.search_runBtn, &QPushButton::pressed, this, &SearchPage::ComputeScan);
	searching = Query::Select("result");
}

void SearchPage::ComputeScan()
{
	searching->set({ "name", "description", "quantity" })->free();
	if (!wndRef->ui.search_scanEdit->text().isEmpty())
		searching->where({ "barcode = " + wndRef->ui.search_scanEdit->text() });

	// Devlopement
	if (wndRef->ui.search_item_devCheckbox->isChecked())
		searching->add({ "manufacturer" });

	// Availibility
	switch (wndRef->ui.search_item_availabilityDropdown->currentIndex())
	{
	case 1: searching->where({ "stock = 1" });  break; // Free Only
	case 2: searching->where({ "stock = 0" })->add({ "type", "room" }); break; // Used Only
	default: break; // All
	}

	wndRef->__currentQuery = searching->get();
}

SearchPage::~SearchPage()
{
	delete searching;
}
