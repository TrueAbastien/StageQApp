#include "ItemCreationWindow.h"

ItemCreationWindow::ItemCreationWindow(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	insertItem = Query::Insert("item");

	connect(ui.okButton, SIGNAL(pressed()), this, SLOT(CreateItem()));

	// TODO: SETUP COMBOBOXES (contact + category)
}

ItemCreationWindow::~ItemCreationWindow()
{
	delete insertItem;
}

void ItemCreationWindow::CreateItem()
{
	insertItem->set({ "name","barcode","restock","category_id" });

	// TODO: process quantity
	
	if (ui.form_nameEdit->text().isEmpty())
		ui.form_nameEdit->setText("ERROR: Name is recquiered.");
	else if (ui.form_barcodeEdit->text().isEmpty())
		ui.outputLabel->setText("ERROR: Barcode is missing !");
	/*else if (ui.form_restockSpinbox->value() > 0)
		ui.outputLabel->setText("ERROR: Restock must be above 0.");*/
	else if (ui.form_categoryCB->currentIndex() == 0)
		ui.outputLabel->setText("ERROR: You have to pick a Category !");
	else
	{
		insertItem->addValues({
			Query::toValue(ui.form_nameEdit->text()),
			Query::toValue(ui.form_barcodeEdit->text()),
			QString(ui.form_restockSpinbox->value()),
			QString(ui.form_categoryCB->currentIndex()) });

		if (!ui.form_manufacturerEdit->text().isEmpty())
		{
			insertItem->add({ "manufacturer" });
			insertItem->addValues({ Query::toValue(ui.form_manufacturerEdit->text()) });
		}
		if (!ui.form_providerEdit->text().isEmpty())
		{
			insertItem->add({ "provider" });
			insertItem->addValues({ Query::toValue(ui.form_providerEdit->text()) });
		}
		if (!ui.form_descriptionEdit->toPlainText().isEmpty())
		{
			insertItem->add({ "description" });
			insertItem->addValues({ Query::toValue(ui.form_descriptionEdit->toPlainText()) });
		}
		if (ui.form_contactCB->currentIndex() != 0)
		{
			insertItem->add({ "contact_id" });
			insertItem->addValues({ QString(ui.form_contactCB->currentIndex()) });
		}

		// TODO:
		// Run query
		// ADD QTTY AND EQUIPMENT
		// close window
	}
}