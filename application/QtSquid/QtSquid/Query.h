#pragma once
#include <QStringList>

class Query
{
private:
	enum Type { SELECT, INSERT, UPDATE };

public:
	static Query* Select(QString view);
	static Query* Insert(QString table);
	static Query* Update(QString table);
	
	Query* set(QStringList fields);
	Query* add(QStringList fields);
	Query* remove(QStringList fields);

	Query* where(QStringList conditions);
	Query* free();

	Query* addValues(QStringList values);
	Query* setValues(QStringList values);
	Query* removeValues(QStringList values);

	QString get(QString order = "");

	static QString toValue(QString& str);

private:
	Query(Type type, QString content = "");

	QStringList fields;
	QStringList conditions;
	QStringList values;
	QString content;

	Type type;
};