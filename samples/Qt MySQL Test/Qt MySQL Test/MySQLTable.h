#pragma once
#include "Database.h"
#include <qtablewidget.h>

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