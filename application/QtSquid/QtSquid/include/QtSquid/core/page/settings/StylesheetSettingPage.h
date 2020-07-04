#pragma once
#include <QtSquid/core/page/AdvancedPageDefine.h>
#include <QtSquid/sql/Query.h>

/**
* StylesheetSettingPage class
*
* Setting page used to pick a preloaded style sheet file.
*/
class StylesheetSettingPage : public SettingPage
{
	Q_OBJECT

public:
	StylesheetSettingPage(QtSquid* ref, SettingWindow* wnd);
	~StylesheetSettingPage();

	void handle() override { }
	void pressOkButton() override;

	void setContent(StyleSheetCache* cache);
	void setStyleSheet(QString styleSheet);

private:
	StyleSheetCache* cache;
	QString currentStyleSheet;

private slots:
	void changeStyleSheet(int currentIndex);
};