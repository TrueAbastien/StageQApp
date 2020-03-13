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
		QFile temporaryFile("Ressources/stylesheet/" + file);
		temporaryFile.open(QFile::ReadOnly);
		this->insert(file, new QString(QLatin1String(temporaryFile.readAll())));
	}
}

QStringList StyleSheetCache::AllStyleSheets() const
{
	return allStyleSheets;
}

void StyleSheetCache::Set(QWidget* wdg, QString styleName)
{
	if (this->contains(styleName))
		wdg->setStyleSheet(*this->object(styleName));
	else if (styleName.isEmpty())
		wdg->setStyleSheet("");
}
