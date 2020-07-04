#pragma once
#include <QFile>
#include <QMap>
#include <QDir>

#include <SimpleCrypt/SimpleCrypt.h>

/**
* SettingFile class
*
* File object used to write local setting file (.setting).
* Encryption looks like YAML format but doesn't allow structures.
*/
class SettingFile : public QFile
{
public:
	explicit SettingFile(QString file);
	~SettingFile();

	void setRules(QStringList rules, bool crypted = false);
	void addRules(QStringList rules, bool crypted = false);
	void readFile();
	void writeFile();

	void set(QString key, QString data);
	QString& get(QString key);

	QString Debug() const;

private:
	SimpleCrypt crypto;

	QMap<QString, QString> content;
	QList<QPair<QString, bool>> rules;
};