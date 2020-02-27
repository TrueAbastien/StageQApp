#pragma once
#include <QMessageBox>

class Debug : public QObject
{
	Q_OBJECT

public:
	static void Log(QString content)
	{
		QMessageBox::information(nullptr, "Log", content);
	}
};