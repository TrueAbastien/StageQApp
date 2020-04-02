#pragma once
#include <QStringList>
#include <QString>
#include <QMap>
#include <vector>

class Query
{
private:

	// Action Class
	class Action
	{
	public:

		bool processed;

		Action(Query* ref);
		QString get();

	protected:

		Query* reference;
		QStringList content;

		virtual void process();
		virtual bool processing() = 0;
	};


	// Select Class
	class Select : public Action
	{
	public:
		
		Select(Query* ref, QList<QPair<QString, QString>> fields);
		Select* from(const char* tables...);
		Select* join(QString table, QString alias, const char* conditions...);
		Select* group(QString field, QString table);
		Select* order(QString field, QString table);

	protected:

		bool processing() override;
	};

	//


public:

	Action* current;
	QMap<QString, QString> tables;								// Alias, Table
	QList<QStringList> fields;									// Field, TableAlias, Alias
	QMap<QString, QPair<QString, QStringList>> jointures;		// TableAlias, (Table, Conditions)
	QStringList conditions;										// Conditions
	QList<QPair<QString, QString>> orders;						// (Field, TableAlias)
	QList<QPair<QString, QString>> groups;						// (Field, TableAlias)

	Query();
	~Query();
	QString get() const;
	Select* select(const char* fields...);
	// insert
	// update
	// requireFieldFrom
	// requireTable

private:

	void clear();
};