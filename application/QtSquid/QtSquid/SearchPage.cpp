#include "SearchPage.h"
#include "QStringHelper.h"

SearchPage::SearchPage(QtSquid* ref)
	: Page(ref)
{
	connect(ref->ui.search_scanBtn, SIGNAL(clicked()), &ref->barcodeScanner, SLOT(activate()));
	connect(&ref->barcodeScanner, &BarcodeScanner::print, [this]() {
		wndRef->ui.search_scanEdit->setText((wndRef->barcodeScanner.get())); });

	connect(ref->ui.search_runBtn, &QPushButton::pressed, this, &SearchPage::ComputeScan);
	searching = Query::Select("result");
}

void SearchPage::ComputeScan()
{
	searching->set({ "name", "quantity", "description" })->free();
	if (!wndRef->ui.search_scanEdit->text().isEmpty())
		searching->where({ "barcode = " + wndRef->ui.search_scanEdit->text() });
	else searching->add({ "barcode" });

	// Devlopement
	if (wndRef->ui.search_item_devCheckbox->isChecked())
		searching->add({ "manufacturer", "provider", "restock" });

	// Availibility
	switch (wndRef->ui.search_item_availabilityDropdown->currentIndex())
	{
	case 1: searching->where({ "stock = 1" });  break; // Free Only
	case 2: searching->where({ "stock = 0" })->add({ "type", "room" }); break; // Used Only
	default: break; // All
	}

	if (wndRef->database.runQuery(searching))
	{
		wndRef->database.computeModel(wndRef->ui.search_resultTable);
		wndRef->ui.search_outputLabel->setText(QStringHelper::Success("Query Successfull !"));
	}
	else wndRef->ui.search_outputLabel->setText(QStringHelper::Error("Query Failed..."));
}

SearchPage::~SearchPage()
{
	delete searching;
}
