#include "SettingFile.h"

#include <QTextStream>
#include <sstream>


SettingFile::SettingFile(QString file)
	: QFile("settings/" + file + ".settings")
{
	this->open(QFile::ReadWrite | QFile::Text | QFile::ExistingOnly);
}

SettingFile::~SettingFile()
{
	this->close();
}

void SettingFile::setRules(QStringList _rules)
{
	rules.clear();
	for (QString& rule : _rules)
		rules.append(rule);
}

void SettingFile::readFile()
{
	std::string line, value;
	QTextStream in(this);
	while (!in.atEnd())
	{
		line = in.readLine().toStdString();

		for (QString rule : rules)
		{
			if (line.find(rule.toStdString() + "=") == 0)
			{
				if (line.size() == rule.size() + 1)
				{
					value = "";
				}
				else
				{
					std::stringstream ss(line.c_str() + rule.length() + 1);
					ss >> value;
				}
				this->set(rule, QString(value.c_str()));
			}
		}
	}
}

void SettingFile::writeFile()
{
	this->resize(0);
	QTextStream out(this);
	for (QString ele : rules)
		out << ele << "=" << content[ele] << '\n';
}

void SettingFile::set(QString key, QString data)
{
	this->content[key] = data;
}

QString& SettingFile::get(QString key)
{
	return this->content[key];
}

QString SettingFile::Debug() const
{
	QString res = "";
	foreach(QString key, content.keys())
		res += key + "->" + content[key] + " - ";
	return res;
}
