#include "QtSquid.h"

#include "SearchPage.h"
#include "EditPage.h"
#include "ConnectionPage.h"
#include "PermissionPage.h"


QtSquid::QtSquid(QWidget *parent)
	: QMainWindow(parent), barcodeScanner(this), styleSheetCache("Ressources/stylesheet"),
	styleSheetWindow(nullptr), preferenceData("preferences")
{
	ui.setupUi(this);

	pages.append(new SearchPage(this));
	pages.append(new EditPage(this));
	pages.append(new ConnectionPage(this));
	pages.append(new PermissionPage(this));

	connect(ui.search_runBtn, SIGNAL(released()), this, SLOT(runCurrentQuery()));

	connect(ui.search_scanBtn, SIGNAL(clicked()), &barcodeScanner, SLOT(activate()));
	connect(&barcodeScanner, SIGNAL(print()), this, SLOT(writeInEdit()));

	connect(ui.actionStyleSheet, SIGNAL(triggered()), this, SLOT(openStyleSheetMenu()));


	preferenceData.setRules({ "style" });
	preferenceData.readFile();
	styleSheetCache.Set(this, preferenceData.get("style"));
}

void QtSquid::keyPressEvent(QKeyEvent* evt)
{
	__latest_key_pressed = evt->text();
	emit key_press();
}

void QtSquid::runCurrentQuery()
{
	if (!database.connected())
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

	bool call = database.runQuery(__currentQuery);
	if (!call) return;

	database.computeModel(ui.search_resultTable);
}

void QtSquid::writeInEdit()
{
	ui.search_scanEdit->setText(barcodeScanner.get());
}

void QtSquid::openStyleSheetMenu()
{
	styleSheetWindow = new StyleSheetWindow(this);
	connect(styleSheetWindow, SIGNAL(pickStyleSheet(QString)), this, SLOT(changeStyleSheet(QString)));

	styleSheetWindow->setContent(&styleSheetCache);
	styleSheetWindow->setStyleSheet(preferenceData.get("style"));
	styleSheetWindow->exec();
}

void QtSquid::changeStyleSheet(QString styleSheet)
{
	preferenceData.set("style", styleSheet);
	styleSheetCache.Set(this, styleSheet);

	preferenceData.writeFile();
}

