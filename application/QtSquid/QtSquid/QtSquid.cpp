#include "QtSquid.h"

#include "SearchPage.h"
#include "EditPage.h"
#include "ConnectionPage.h"
#include "PermissionPage.h"


QtSquid::QtSquid(QWidget *parent)
	: QMainWindow(parent), bs(this)
{
	ui.setupUi(this);

	pages.append(new SearchPage(this));
	pages.append(new EditPage(this));
	pages.append(new ConnectionPage(this));
	pages.append(new PermissionPage(this));

	connect(ui.conn_runBtn, SIGNAL(clicked()), this, SLOT(connectDatabase()));
	connect(ui.search_runBtn, SIGNAL(clicked()), this, SLOT(runCurrentQuery()));

	connect(ui.search_scanBtn, SIGNAL(clicked()), &bs, SLOT(activate()));
	connect(&bs, SIGNAL(print()), this, SLOT(writeInEdit()));


	// Style Sheet - TEST
	// TODO: Style Sheet Cache
}

void QtSquid::connectDatabase()
{
	if (db.connect("localhost", 3306, "root", "", "testing"))
	{
		QMessageBox::information(this, "Connection", "Successfull !");
	}
	else
	{
		QMessageBox::information(this, "Connection", "Failed: " + db.getLastError());
	}
}

void QtSquid::keyPressEvent(QKeyEvent* evt)
{
	__latest_key_pressed = evt->text();
	emit key_press();
}

void QtSquid::runCurrentQuery()
{
	if (!db.connected())
	{
		ui.search_outputLabel->setText("Erreur: Connectez vous a la Base de Donnees !");
		return;
	}
	else if (__currentQuery.isEmpty())
	{
		ui.search_outputLabel->setText("Erreur: Votre query est entierement vide...");
		return;
	}
	ui.search_outputLabel->setText("Query Successfull !");

	bool call = db.runQuery(__currentQuery);
	if (!call) return;

	db.computeModel(ui.search_resultTable);
}

void QtSquid::writeInEdit()
{
	ui.search_scanEdit->setText(bs.get());
}