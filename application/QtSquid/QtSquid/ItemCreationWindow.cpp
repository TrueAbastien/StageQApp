#include "ItemCreationWindow.h"

ItemCreationWindow::ItemCreationWindow(QtSquid* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	app = parent;

	insertItem = Query::Insert("item");
	insertEquipment = Query::Insert("equipment");
	selectItemID = Query::Select("item")->set({ "id" });

	connect(ui.okButton, SIGNAL(pressed()), this, SLOT(CreateItem()));

	// Contact Setup
	app->database.runQuery(Query::Select("contact")->set({ "name" }));
	ui.form_contactCB->addItem("---");
	foreach(QString contact, app->database.result().value("name"))
		ui.form_contactCB->addItem(contact);

	// Category Setup
	app->database.runQuery(Query::Select("category")->set({ "name" }));
	ui.form_categoryCB->addItem("---");
	foreach(QString category, app->database.result().value("name"))
		ui.form_categoryCB->addItem(category);

	// Default Values
	ui.form_barcodeEdit->setText(app->ui.edit_form_barcodeEdit->text());
	ui.form_quantitySpinbox->setValue(app->ui.edit_form_qtySpinbox->value());
}

ItemCreationWindow::~ItemCreationWindow()
{
	delete insertItem;
	delete insertEquipment;
	delete selectItemID;
}

void ItemCreationWindow::CreateItem()
{
	insertItem->set({ "name","barcode","restock","category_id" })->clearValues();
	insertEquipment->set({ "quantity", "item_id" })->clearValues();
	selectItemID->free();

	if (ui.form_nameEdit->text().isEmpty())
		ui.outputLabel->setText(QStringHelper::Error("Name is required."));
	else if (ui.form_barcodeEdit->text().isEmpty())
		ui.outputLabel->setText(QStringHelper::Error("Barcode is missing !"));
	else if (ui.form_quantitySpinbox->value() < ui.form_restockSpinbox->value())
		ui.outputLabel->setText(QStringHelper::Error("Quantity is lower than Restock..."));
	else if (ui.form_categoryCB->currentIndex() <= 0)
		ui.outputLabel->setText(QStringHelper::Error("You have to pick a Category !"));
	else
	{
		insertItem->addValues({
			Query::toValue(ui.form_nameEdit->text()),
			Query::toValue(ui.form_barcodeEdit->text()),
			QString::number(ui.form_restockSpinbox->value()),
			QString::number(ui.form_categoryCB->currentIndex()) });

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
		if (ui.form_contactCB->currentIndex() > 0)
		{
			insertItem->add({ "contact_id" });
			insertItem->addValues({ QString::number(ui.form_contactCB->currentIndex()) });
		}

		if (app->database.runQuery(insertItem))
		{
			selectItemID->where({ "barcode = " + Query::toValue(ui.form_barcodeEdit->text()) });
			if (app->database.runQuery(selectItemID))
			{
				insertEquipment->addValues({ QString::number(ui.form_quantitySpinbox->value()), app->database.result().value("id")[0] });
				if (app->database.runQuery(insertEquipment))
				{
					this->close();
				}
			}
		}
	}
}