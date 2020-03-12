#pragma once
#include <QFile>
#include <QMap>
#include <QDir>

class SettingFile : public QFile
{
public:
	explicit SettingFile(QString file);
	~SettingFile();

	void setRules(QStringList rules);
	void readFile();
	void writeFile();

	void set(QString key, QString data);
	QString& get(QString key);

	QString Debug() const;

private:
	QMap<QString, QString> content;
	QStringList rules;
};