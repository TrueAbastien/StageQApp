#include "EditPage.h"

EditPage::EditPage(QtSquid* ref)
	: Page(ref), createWindow(nullptr)
{
	selectItemID = Query::Select("item")->add({ "id" });
	updateEquipmentQty = Query::Update("equipment")->add({ "quantity" });
	selectEquipmentQty = Query::Select("equipment")->add({ "quantity" });

	connect(wndRef->ui.edit_addBtn, SIGNAL(pressed()), this, SLOT(AddElements()));
	connect(wndRef->ui.edit_removeBtn, SIGNAL(pressed()), this, SLOT(RemoveElements()));
}

bool EditPage::isItemUpdatable()
{
	return !wndRef->ui.edit_form_barcodeEdit->text().isEmpty()
		&& wndRef->ui.edit_form_qtySpinbox->value() > 0;
}

void EditPage::OpenCreationWindow()
{
	createWindow = new ItemCreationWindow(wndRef);
	createWindow->exec();
}

void EditPage::AddElements()
{
	if (isItemUpdatable())
	{
		selectItemID->free()->where({ "barcode = " + wndRef->ui.edit_form_barcodeEdit->text() });
		wndRef->database.runQuery(selectItemID->get());
		auto result = wndRef->database.result();
		if (result.value("id").length() != 0)
		{
			selectEquipmentQty->free()
				->where({ "item_id = " + result.value("id")[0], "config_id IS NULL" });
			wndRef->database.runQuery(selectEquipmentQty->get());

			updateEquipmentQty->free()
				->where({ "item_id = " + result.value("id")[0], "config_id IS NULL" })
				->setValues({ QString::number(wndRef->database.result().value("quantity")[0].toInt() + wndRef->ui.edit_form_qtySpinbox->value()) });
			wndRef->database.runQuery(updateEquipmentQty->get());

			wndRef->ui.edit_outputLabel->setText(QStringHelper::Success("Item successfully added !"));
		}
		else OpenCreationWindow();
	}
	else
	{
		//
	}
}

void EditPage::RemoveElements()
{
	if (isItemUpdatable())
	{
		selectItemID->free()->where({ "barcode = " + wndRef->ui.edit_form_barcodeEdit->text() });
		wndRef->database.runQuery(selectItemID->get());
		auto result = wndRef->database.result();
		if (result.value("id").length() != 0)
		{
			selectEquipmentQty->free()
				->where({ "item_id = " + result.value("id")[0], "config_id IS NULL" });
			wndRef->database.runQuery(selectEquipmentQty->get());

			int qty = wndRef->database.result().value("quantity")[0].toInt();
			if (qty >= wndRef->ui.edit_form_qtySpinbox->value())
			{
				updateEquipmentQty->free()
					->where({ "item_id = " + result.value("id")[0], "config_id IS NULL" })
					->setValues({ QString::number(qty - wndRef->ui.edit_form_qtySpinbox->value()) });
				wndRef->database.runQuery(updateEquipmentQty->get());
			}

			wndRef->ui.edit_outputLabel->setText(QStringHelper::Success("Item successfully removed."));
		}
		else wndRef->ui.edit_outputLabel->setText(QStringHelper::Error("No item was found..."));
	}
	else
	{
		//
	}
}
