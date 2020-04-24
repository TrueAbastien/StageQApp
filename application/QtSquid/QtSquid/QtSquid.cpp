#include <QtSquid.h>

#include <QtSquid/core/page/main/SearchPage.h>
#include <QtSquid/core/page/main/EditPage.h>
#include <QtSquid/core/page/main/ConnectionPage.h>
#include <QtSquid/core/page/main/PermissionPage.h>

#include <AdvancedWindow.h>

#include <QDesktopServices>


QtSquid::QtSquid(QWidget* parent)
	: QMainWindow(parent), barcodeScanner(this), styleSheetCache("Ressources/stylesheet"),
	preferenceData("preferences"), quickLinksData("quicklinks")
	
{
	ui.setupUi(this);

	pages.append(new SearchPage(this));
	pages.append(new EditPage(this));
	pages.append(new ConnectionPage(this));
	pages.append(new PermissionPage(this));

	settingWindow = new SettingWindow(this);
	createWindow = new CreationWindow(this);

	connect(ui.actionStyleSheet, SIGNAL(triggered()), this, SLOT(OpenSettingWindow()));

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

void QtSquid::OpenCreationWindow()
{
	createWindow->open();
}

void QtSquid::OpenSettingWindow()
{
	settingWindow->open();
}

