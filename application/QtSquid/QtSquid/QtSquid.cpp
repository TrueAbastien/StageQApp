#include <QtSquid.h>

#include <QtSquid/core/page/main/SearchPage.h>
#include <QtSquid/core/page/main/EditPage.h>
#include <QtSquid/core/page/main/ConnectionPage.h>
#include <QtSquid/core/page/main/PermissionPage.h>

#include <QDesktopServices>


QtSquid::QtSquid(QWidget *parent)
	: QMainWindow(parent), barcodeScanner(this), styleSheetCache("Ressources/stylesheet"),
	styleSheetWindow(nullptr), preferenceData("preferences"), quickLinksData("quicklinks")
{
	ui.setupUi(this);

	pages.append(new SearchPage(this));
	pages.append(new EditPage(this));
	pages.append(new ConnectionPage(this));
	pages.append(new PermissionPage(this));

	connect(ui.actionStyleSheet, SIGNAL(triggered()), this, SLOT(openStyleSheetMenu()));

	quickLinksData.setRules({ "stylesheet","email" });
	quickLinksData.readFile();
	connect(ui.actionLink_StyleSheet, &QAction::triggered, [this]() { QDesktopServices::openUrl(QUrl(quickLinksData.get("stylesheet"))); });
	connect(ui.actionLink_Email, &QAction::triggered, [this]() { QDesktopServices::openUrl(QUrl(quickLinksData.get("email"))); });


	preferenceData.setRules({ "style" });
	preferenceData.readFile();
	styleSheetCache.Set(this, preferenceData.get("style"));
}

void QtSquid::keyPressEvent(QKeyEvent* evt)
{
	emit key_press(evt->text());
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

