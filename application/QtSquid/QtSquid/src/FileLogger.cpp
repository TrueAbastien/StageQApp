#include <QtSquid/core/file/FileLogger.h>

#include <QTextStream>
#include <QDateTime>


FileLogger::FileLogger(QString file)
	: QFile("logs/" + file + ".log")
{
	this->open(QFile::ReadWrite | QFile::Text | QFile::ExistingOnly | QFile::Append);
}

FileLogger::~FileLogger()
{
	this->close();
}

void FileLogger::log(QString content)
{
	QTextStream out(this);
	QDateTime now = QDateTime::currentDateTime();
	out << "<" << now.toString() << ">: " << content << "\n";
}

void FileLogger::clear()
{
	this->resize(0);
}
