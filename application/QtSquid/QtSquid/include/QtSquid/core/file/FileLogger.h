#pragma once
#include <QFile>

class FileLogger : public QFile
{
public:
	explicit FileLogger(QString file);
	~FileLogger();

	void log(QString content);
	void clear();
};