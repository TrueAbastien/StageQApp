#pragma once
#include <QFile>

/**
* FileLogger class
*
* File log system writing data through specified file path.
*/
class FileLogger : public QFile
{
public:
	explicit FileLogger(QString file);
	~FileLogger();

	void log(QString content);
	void clear();
};