#pragma once
#include <QStringList>

class Query
{

public:
	static Query* Select(QString view);
	
	Query* set(QStringList fields);
	Query* add(QStringList fields);
	Query* remove(QStringList fields);

	Query* where(QStringList conditions);
	Query* free();

	QString get(QString order = "");

private:
	Query(QString content = "");

	QStringList fields;
	QStringList conditions;
	QString content;
};