#include <QtSquid/core/page/creation/ItemCreationPage.h>
#include <QtSquid/tool/QStringHelper.h>


ItemCreationPage::ItemCreationPage(QtSquid* ref, CreationWindow* wnd)
	: CreationPage(ref, wnd)
{
	insertItem = Query::Insert("item");
	insertEquipment = Query::Insert("equipment");
	selectItemID = Query::Select("item")->set({ "id" });

	// Contact Setup
	ref->database.runQuery(Query::Select("contact")->set({ "name" }));
	wnd->ui.item_form_contactCB->addItem("---");
	foreach(QString contact, ref->database.result().value("name"))
		wnd->ui.item_form_contactCB->addItem(contact);

	// Category Setup
	ref->database.runQuery(Query::Select("category")->set({ "name" }));
	wnd->ui.item_form_categoryCB->addItem("---");
	foreach(QString category, ref->database.result().value("name"))
		wnd->ui.item_form_categoryCB->addItem(category);

	// Default Values
	wnd->ui.item_form_barcodeEdit->setText(ref->ui.edit_form_barcodeEdit->text());
	wnd->ui.item_form_quantitySpinbox->setValue(ref->ui.edit_form_qtySpinbox->value());
}

ItemCreationPage::~ItemCreationPage()
{
	delete insertItem;
	delete insertEquipment;
	delete selectItemID;
}

void ItemCreationPage::pressOkButton()
{
	insertItem->set({ "name","barcode","restock","category_id" })->clearValues();
	insertEquipment->set({ "quantity", "item_id" })->clearValues();
	selectItemID->free();

	if (advWndRef->ui.item_form_nameEdit->text().isEmpty())
		advWndRef->ui.item_outputLabel->setText(QStringHelper::Error("Name is required."));
	else if (advWndRef->ui.item_form_barcodeEdit->text().isEmpty())
		advWndRef->ui.item_outputLabel->setText(QStringHelper::Error("Barcode is missing !"));
	else if (advWndRef->ui.item_form_quantitySpinbox->value() < advWndRef->ui.item_form_restockSpinbox->value())
		advWndRef->ui.item_outputLabel->setText(QStringHelper::Error("Quantity is lower than Restock..."));
	else if (advWndRef->ui.item_form_categoryCB->currentIndex() <= 0)
		advWndRef->ui.item_outputLabel->setText(QStringHelper::Error("You have to pick a Category !"));
	else
	{
		insertItem->addValues({
			Query::toValue(advWndRef->ui.item_form_nameEdit->text()),
			Query::toValue(advWndRef->ui.item_form_barcodeEdit->text()),
			QString::number(advWndRef->ui.item_form_restockSpinbox->value()),
			QString::number(advWndRef->ui.item_form_categoryCB->currentIndex()) });

		if (!advWndRef->ui.item_form_manufacturerEdit->text().isEmpty())
		{
			insertItem->add({ "manufacturer" });
			insertItem->addValues({ Query::toValue(advWndRef->ui.item_form_manufacturerEdit->text()) });
		}
		if (!advWndRef->ui.item_form_providerEdit->text().isEmpty())
		{
			insertItem->add({ "provider" });
			insertItem->addValues({ Query::toValue(advWndRef->ui.item_form_providerEdit->text()) });
		}
		if (!advWndRef->ui.item_form_descriptionEdit->toPlainText().isEmpty())
		{
			insertItem->add({ "description" });
			insertItem->addValues({ Query::toValue(advWndRef->ui.item_form_descriptionEdit->toPlainText()) });
		}
		if (advWndRef->ui.item_form_contactCB->currentIndex() > 0)
		{
			insertItem->add({ "contact_id" });
			insertItem->addValues({ QString::number(advWndRef->ui.item_form_contactCB->currentIndex()) });
		}

		if (wndRef->database.runQuery(insertItem))
		{
			selectItemID->where({ "barcode = " + Query::toValue(advWndRef->ui.item_form_barcodeEdit->text()) });
			if (wndRef->database.runQuery(selectItemID))
			{
				insertEquipment->addValues
					({ QString::number(advWndRef->ui.item_form_quantitySpinbox->value()), wndRef->database.result().value("id")[0] });
				if (wndRef->database.runQuery(insertEquipment))
				{
					advWndRef->close();
				}
			}
		}
	}
}
