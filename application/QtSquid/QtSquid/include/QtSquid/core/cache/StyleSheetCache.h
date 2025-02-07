#pragma once
#include <QCache>
#include <QDir>
#include <QMainWindow>

/**
* StyleSheetCache class
*
* Cache object preloading existing QSS file to change the application windows style.
*/
class StyleSheetCache : public QCache<QString, QString>
{
public:
	StyleSheetCache(QString dir = QString(""));
	void LoadAt(QString dir);

	QStringList AllStyleSheets() const;
	void Set(QWidget* wdg, QString styleName);

private:
	QDir stylesheetDirectory;
	QStringList allStyleSheets;
};