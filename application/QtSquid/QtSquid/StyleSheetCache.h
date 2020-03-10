#pragma once
#include <QCache>
#include <QDir>
#include <QMainWindow>

class StyleSheetCache : public QCache<QString, QString>
{
public:
	StyleSheetCache(QString dir = QString(""));
	void LoadAt(QString dir);

	QStringList AllStyleSheets() const;
	void Set(QMainWindow* wnd, QString styleName);

private:
	QDir stylesheetDirectory;
	QStringList allStyleSheets;
};