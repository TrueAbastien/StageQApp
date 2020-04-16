#pragma once
#include <QStringList>

class Query
{
public:
	enum Type { SELECT, INSERT, UPDATE, qDELETE };

public:
	static Query* Select(QString view);
	static Query* Insert(QString table);
	static Query* Update(QString table);
	static Query* Delete(QString table);
	
	Query* set(QStringList fields);
	Query* add(QStringList fields);
	Query* remove(QStringList fields);

	Query* where(QStringList conditions);
	Query* free();

	Query* clearValues();
	Query* addValues(QStringList values);
	Query* setValues(QStringList values);
	Query* removeValues(QStringList values);

	QString get(QString order = "");

	Type getType() const;

	static QString toValue(QString& str);

private:
	Query(Type type, QString content = "");

	QStringList fields;
	QStringList conditions;
	QStringList values;
	QString content;

	Type type;
};