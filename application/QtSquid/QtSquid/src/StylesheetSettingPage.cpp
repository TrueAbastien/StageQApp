#include <QtSquid\core\page\settings\StylesheetSettingPage.h>

StylesheetSettingPage::StylesheetSettingPage(QtSquid* ref, SettingWindow* wnd)
	: SettingPage(ref, wnd), currentStyleSheet("")
{
	connect(advWndRef->ui.style_dropdownMenu, SIGNAL(activated(int)), this, SLOT(changeStyleSheet(int)));

	setContent(&wndRef->styleSheetCache);
	setStyleSheet(wndRef->preferenceData.get("style"));
}

StylesheetSettingPage::~StylesheetSettingPage()
{
}

void StylesheetSettingPage::pressOkButton()
{
	advWndRef->close();
}

void StylesheetSettingPage::setContent(StyleSheetCache* cache)
{
	this->cache = cache;
	advWndRef->ui.style_dropdownMenu->clear();
	advWndRef->ui.style_dropdownMenu->addItem("- Default -", "");
	foreach(QString styleSheet, cache->AllStyleSheets())
		advWndRef->ui.style_dropdownMenu->addItem(styleSheet.left(styleSheet.lastIndexOf(QChar('.'))), styleSheet);
}

void StylesheetSettingPage::setStyleSheet(QString styleSheet)
{
	QStringList sheets = cache->AllStyleSheets();
	const int size = sheets.size();
	for (int ii = 0; ii < size; ++ii)
		if (sheets[ii] == styleSheet)
		{
			advWndRef->ui.style_dropdownMenu->setCurrentIndex(ii + 1);
			return;
		}
}

void StylesheetSettingPage::changeStyleSheet(int currentIndex)
{
	currentStyleSheet = advWndRef->ui.style_dropdownMenu->itemData(currentIndex).toString();
	cache->Set(advWndRef, currentStyleSheet);

	wndRef->preferenceData.set("style", currentStyleSheet);
	wndRef->styleSheetCache.Set(wndRef, currentStyleSheet);

	wndRef->preferenceData.writeFile();
}