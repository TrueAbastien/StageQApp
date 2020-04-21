#include <QtSquid/core/file/SettingFile.h>

#include <QTextStream>
#include <sstream>


SettingFile::SettingFile(QString file)
	: QFile("settings/" + file + ".settings"), crypto(Q_UINT64_C(0x5d6e158c452a1495))
{
	this->open(QFile::ReadWrite | QFile::Text | QFile::ExistingOnly);
}

SettingFile::~SettingFile()
{
	this->close();
}

void SettingFile::setRules(QStringList _rules, bool crypted)
{
	rules.clear();
	addRules(_rules, crypted);
}

void SettingFile::addRules(QStringList _rules, bool crypted)
{
	for (QString& rule : _rules)
	{
		if (rule.contains("$"))
			rules.append({ rule.replace("$", ""), true });
		else rules.append({ rule, crypted });
	}
}

void SettingFile::readFile()
{
	std::string line, value;
	QString processedValue;
	QTextStream in(this);
	while (!in.atEnd())
	{
		line = in.readLine().toStdString();

		for (QPair<QString, bool> rule : rules)
		{
			if (line.find(rule.first.toStdString() + "=") == 0)
			{
				if (line.size() == rule.first.size() + 1)
				{
					value = "";
				}
				else
				{
					std::stringstream ss(line.c_str() + rule.first.length() + 1);
					ss >> value;
				}
				if (rule.second)
					processedValue = crypto.decryptToString(QString(value.c_str()));
				else processedValue = QString(value.c_str());
				this->set(rule.first, processedValue);
			}
		}
	}
}

void SettingFile::writeFile()
{
	this->resize(0);
	QString processedValue;
	QTextStream out(this);
	for (QPair<QString, bool> ele : rules)
	{
		if (ele.second)
			processedValue = crypto.encryptToString(content[ele.first]);
		else processedValue = content[ele.first];
		out << ele.first << "=" << processedValue << '\n';
	}
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
