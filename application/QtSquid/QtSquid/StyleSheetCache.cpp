#include "StyleSheetCache.h"

StyleSheetCache::StyleSheetCache(QString dir)
{
	if (!dir.isEmpty())
		LoadAt(dir);
}

void StyleSheetCache::LoadAt(QString dir)
{
	this->clear();
	stylesheetDirectory = QDir(dir);
	allStyleSheets = stylesheetDirectory.entryList(QStringList() << "*.qss" << "*.QSS", QDir::Files);

	foreach(QString file, allStyleSheets)
	{
		QFile temporaryFile("Ressources/stylesheet/ManjaroMix.qss");
		temporaryFile.open(QFile::ReadOnly);
		this->insert(file, new QString(QLatin1String(temporaryFile.readAll())));
	}
}

QStringList StyleSheetCache::AllStyleSheets() const
{
	return allStyleSheets;
}

void StyleSheetCache::Set(QMainWindow* wnd, QString styleName)
{
	if (this->contains(styleName))
		wnd->setStyleSheet(*this->object(styleName));
}
