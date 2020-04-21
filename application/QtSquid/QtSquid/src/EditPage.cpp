#include <QtSquid/core/page/main/EditPage.h>

EditPage::EditPage(QtSquid* ref)
	: Page(ref), createWindow(nullptr)
{
	selectItemID = Query::Select("item")->add({ "id" });
	updateEquipmentQty = Query::Update("equipment")->add({ "quantity" });
	selectEquipmentQty = Query::Select("equipment")->add({ "id", "quantity" });

	selectConfigID = Query::Select("configuration")->add({ "id" });
	insertEquipment = Query::Insert("equipment")->add({ "quantity","item_id","config_id" });
	deleteEquipment = Query::Delete("equipment");

	connect(wndRef->ui.edit_addBtn, SIGNAL(pressed()), this, SLOT(AddElement()));
	connect(wndRef->ui.edit_removeBtn, SIGNAL(pressed()), this, SLOT(RemoveElement()));

	connect(wndRef->ui.edit_storeBtn, SIGNAL(pressed()), this, SLOT(StoreElement()));
	connect(wndRef->ui.edit_takeBtn, SIGNAL(pressed()), this, SLOT(TakeElement()));
	
	selectTypeName = Query::Select("type")->add({ "name" });
	wndRef->ui.edit_form_typeCB->addItem("---");

	selectRoomName = Query::Select("room")->add({ "name" });
	wndRef->ui.edit_form_roomCB->addItem("---");
}

bool EditPage::isItemUpdatable()
{
	return !wndRef->ui.edit_form_barcodeEdit->text().isEmpty()
		&& wndRef->ui.edit_form_qtySpinbox->value() > 0;
}

bool EditPage::isItemSetable()
{
	return wndRef->ui.edit_form_roomCB->currentIndex() > 0
		&& wndRef->ui.edit_form_typeCB->currentIndex() > 0;
}

void EditPage::OpenCreationWindow()
{
	createWindow = new CreationWindow(wndRef);
	createWindow->exec();
}

void EditPage::AddElement()
{
	if (isItemUpdatable())
	{
		// Search Item ID
		selectItemID->free()->where({ "barcode = " + wndRef->ui.edit_form_barcodeEdit->text() });
		wndRef->database.runQuery(selectItemID);
		auto result = wndRef->database.result();
		if (result.value("id").length() != 0)
		{
			// Search Free Equipment
			selectEquipmentQty->free()
				->where({ "item_id = " + result.value("id")[0], "config_id IS NULL" });
			wndRef->database.runQuery(selectEquipmentQty);

			// Add item copies in Free Equipment
			updateEquipmentQty->free()
				->where({ "item_id = " + result.value("id")[0], "config_id IS NULL" })
				->setValues({ QString::number(wndRef->database.result().value("quantity")[0].toInt() + wndRef->ui.edit_form_qtySpinbox->value()) });
			wndRef->database.runQuery(updateEquipmentQty);

			wndRef->ui.edit_outputLabel->setText(QStringHelper::Success("Item successfully added !"));
		}
		else OpenCreationWindow();
	}
	else
	{
		//
	}
}

void EditPage::RemoveElement()
{
	if (isItemUpdatable())
	{
		// Search Item ID
		selectItemID->free()->where({ "barcode = " + wndRef->ui.edit_form_barcodeEdit->text() });
		wndRef->database.runQuery(selectItemID);
		auto result = wndRef->database.result();
		if (result.value("id").length() != 0)
		{
			// Search Free Equipment
			selectEquipmentQty->free()
				->where({ "item_id = " + result.value("id")[0], "config_id IS NULL" });
			wndRef->database.runQuery(selectEquipmentQty);

			// Verify Specified Quantity is Viable
			int qty = wndRef->database.result().value("quantity")[0].toInt();
			if (qty >= wndRef->ui.edit_form_qtySpinbox->value())
			{
				// Remove item copies from Free Equipment
				updateEquipmentQty->free()
					->where({ "item_id = " + result.value("id")[0], "config_id IS NULL" })
					->setValues({ QString::number(qty - wndRef->ui.edit_form_qtySpinbox->value()) });
				wndRef->database.runQuery(updateEquipmentQty);

				wndRef->ui.edit_outputLabel->setText(QStringHelper::Success("Item successfully removed."));
			}
			else wndRef->ui.edit_outputLabel->setText(QStringHelper::Error("Not enough copy of item left..."));
		}
		else wndRef->ui.edit_outputLabel->setText(QStringHelper::Error("No item was found..."));
	}
	else
	{
		//
	}
}

void EditPage::TakeElement()
{
	if (isItemUpdatable())
	{
		if (isItemSetable())
		{
			// Search Item ID
			selectItemID->free()->where({ "barcode = " + wndRef->ui.edit_form_barcodeEdit->text() });
			wndRef->database.runQuery(selectItemID);
			auto result = wndRef->database.result();
			if (result.value("id").length() != 0)
			{
				// Search Free Equipment
				selectEquipmentQty->free()
					->where({ "item_id = " + result.value("id")[0], "config_id IS NULL" });
				wndRef->database.runQuery(selectEquipmentQty);

				// Verify Specified Quantity is Viable
				int qty = wndRef->database.result().value("quantity")[0].toInt();
				if (qty >= wndRef->ui.edit_form_qtySpinbox->value())
				{
					// Search Specific Configuration
					selectConfigID->free()->where(
						{
							"number " + (wndRef->ui.edit_form_numberSpinbox->value() <= 0 ? "is NULL" :
							("= " + QString::number(wndRef->ui.edit_form_numberSpinbox->value()))),
							"type_id = " + QString::number(wndRef->ui.edit_form_typeCB->currentIndex()),
							"room_id = " + QString::number(wndRef->ui.edit_form_roomCB->currentIndex())
						});
					wndRef->database.runQuery(selectConfigID);

					// If Configuration Exists
					if (wndRef->database.result().value("id").length() == 1)
					{
						QString configIDstr = wndRef->database.result().value("id")[0];

						// Remove item copies from Free Equipment
						updateEquipmentQty->free()
							->where({ "item_id = " + result.value("id")[0], "config_id IS NULL" })
							->setValues({ QString::number(qty - wndRef->ui.edit_form_qtySpinbox->value()) });
						wndRef->database.runQuery(updateEquipmentQty);

						// Search Specific Equipment
						wndRef->database.runQuery(selectEquipmentQty->free()->where
							({ "config_id = " + configIDstr, "item_id = " + result.value("id")[0] }));
						if (wndRef->database.result().value("id").length() == 0)
						{
							// If inexistant, get created
							insertEquipment->setValues({
								QString::number(wndRef->ui.edit_form_qtySpinbox->value()),
								result.value("id")[0], configIDstr });
							wndRef->database.runQuery(insertEquipment);
						}
						else
						{
							// If existant, get updated
							updateEquipmentQty->free()
								->where({ "id = " + wndRef->database.result().value("id")[0] })
								->setValues({ QString::number(wndRef->database.result().value("quantity")[0].toInt()
									+ wndRef->ui.edit_form_qtySpinbox->value()) });
							wndRef->database.runQuery(updateEquipmentQty);
						}

						wndRef->ui.edit_outputLabel->setText(QStringHelper::Success("Item successfully taken !"));
					}
					else wndRef->ui.edit_outputLabel->setText(QStringHelper::Error("Specific configuration couldn't be found !"));
				}
				else wndRef->ui.edit_outputLabel->setText(QStringHelper::Error("Not enough copy of item left..."));
			}
			else wndRef->ui.edit_outputLabel->setText(QStringHelper::Error("No item was found..."));
		}
		else
		{
			//
		}
	}
	else
	{
		//
	}
}

void EditPage::StoreElement()
{
	if (isItemUpdatable())
	{
		if (isItemSetable())
		{
			// Search Item ID
			selectItemID->free()->where({ "barcode = " + wndRef->ui.edit_form_barcodeEdit->text() });
			wndRef->database.runQuery(selectItemID);
			auto result = wndRef->database.result();
			if (result.value("id").length() != 0)
			{
				// Search Specific Configuration
				selectConfigID->free()->where(
					{
						"number " + (wndRef->ui.edit_form_numberSpinbox->value() <= 0 ? "is NULL" :
						("= " + QString::number(wndRef->ui.edit_form_numberSpinbox->value()))),
						"type_id = " + QString::number(wndRef->ui.edit_form_typeCB->currentIndex()),
						"room_id = " + QString::number(wndRef->ui.edit_form_roomCB->currentIndex())
					});
				wndRef->database.runQuery(selectConfigID);

				// If Configuration Exists
				if (wndRef->database.result().value("id").length() == 1)
				{
					QString configIDstr = wndRef->database.result().value("id")[0];

					// Search Specific Equipment
					wndRef->database.runQuery(selectEquipmentQty->free()->where
						({ "config_id = " + configIDstr, "item_id = " + result.value("id")[0] }));
					if (wndRef->database.result().value("id").length() > 0)
					{
						int qty = wndRef->database.result().value("quantity")[0].toInt();

						// Verify if Specific Equipment Quantity is enough
						if (qty >= wndRef->ui.edit_form_qtySpinbox->value())
						{
							// Delete row if everything is taken (= 0 item copies remaining)
							if (qty == wndRef->ui.edit_form_qtySpinbox->value())
							{
								deleteEquipment->free()
									->where({ "id = " + wndRef->database.result().value("id")[0] });
								QMessageBox::information(wndRef, "YIIISSS BREAD CRUMBS", deleteEquipment->get()); //DEBUG
								wndRef->database.runQuery(deleteEquipment);
							}

							// Remove item copies from Specific Equipment
							else
							{
								updateEquipmentQty->free()
									->where({ "id = " + wndRef->database.result().value("id")[0] })
									->setValues({ QString::number(qty - wndRef->ui.edit_form_qtySpinbox->value()) });
								wndRef->database.runQuery(updateEquipmentQty);
							}

							// Search Free Equipment
							selectEquipmentQty->free()
								->where({ "item_id = " + result.value("id")[0], "config_id IS NULL" });
							wndRef->database.runQuery(selectEquipmentQty);

							// Add item copies in Free Equipment
							updateEquipmentQty->free()
								->where({ "item_id = " + result.value("id")[0], "config_id IS NULL" })
								->setValues({ QString::number(wndRef->database.result().value("quantity")[0].toInt()
									+ wndRef->ui.edit_form_qtySpinbox->value()) });
							wndRef->database.runQuery(updateEquipmentQty);

							wndRef->ui.edit_outputLabel->setText(QStringHelper::Success("Item successfully stored !"));
						}
						else wndRef->ui.edit_outputLabel->setText(QStringHelper::Error("Quantity is too high to be stored !"));
					}
					else wndRef->ui.edit_outputLabel->setText(QStringHelper::Error("Specific equipment doesn't exist..."));
				}
				else wndRef->ui.edit_outputLabel->setText(QStringHelper::Error("Specific configuration couldn't be found !"));
			}
			else wndRef->ui.edit_outputLabel->setText(QStringHelper::Error("No item was found..."));
		}
		else
		{
			//
		}
	}
	else
	{
		//
	}
}

void EditPage::onDatabaseConnect()
{
	if (wndRef->database.runQuery(selectTypeName, "id"))
	{
		wndRef->ui.edit_form_typeCB->clear();
		wndRef->ui.edit_form_typeCB->addItem("---");
		foreach(QString type, wndRef->database.result().value("name"))
			wndRef->ui.edit_form_typeCB->addItem(type);
	}

	if (wndRef->database.runQuery(selectRoomName, "id"))
	{
		wndRef->ui.edit_form_roomCB->clear();
		wndRef->ui.edit_form_roomCB->addItem("---");
		foreach(QString room, wndRef->database.result().value("name"))
			wndRef->ui.edit_form_roomCB->addItem(room);
	}
}
