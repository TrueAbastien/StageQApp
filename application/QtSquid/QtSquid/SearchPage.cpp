#include "SearchPage.h"

SearchPage::SearchPage(QtSquid* ref)
	: Page(ref)
{
	connect(wndRef->ui.search_scanEdit, &QLineEdit::textChanged, this, &SearchPage::ComputeScan);
}

void SearchPage::ComputeScan(const QString& val)
{
	wndRef->__currentQuery = "SELECT * FROM equipment e JOIN item i ON e.item_id = i.id WHERE i.barcode = " + val;
}
