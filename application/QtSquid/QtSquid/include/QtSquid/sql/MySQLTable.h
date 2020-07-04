#pragma once
#include <QtSquid/sql/Database.h>
#include <QTableWidget>

/**
* MySQLTable class
*
* Graphic object used to draw database latest result in a TableWidget.
* Will display in a table every successful SELECT query output regarding the Search Page.
*/
class MySQLTable : public QObject
{
	Q_OBJECT

public:
	bool input(Database* db);
	bool output(QTableWidget* table);

private:
	QList<QList<QTableWidgetItem>> content;
	int nRows, nCols;
	bool isProcessed = false;
};