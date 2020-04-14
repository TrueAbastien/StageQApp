#include "MySQLTable.h"


bool MySQLTable::input(Database* db)
{
	if (db == nullptr)
		return false;
	content.clear();

	QStringList rawContent = db->CSVresults().split("\n"), row;
	if (rawContent.isEmpty())
		return false;

	int rows = rawContent.size() - 1,
		cols = rawContent[0].split(";").size() - 1;

	for (int ii = 0; ii < rows; ++ii)
	{
		row = rawContent[ii].split(";");
		content.push_back(QList<QTableWidgetItem>());
		for (int jj = 0; jj < cols; ++jj)
			content[ii].push_back(QTableWidgetItem(row[jj]));
	}

	nRows = rows; nCols = cols;
	isProcessed = true;
	return true;
}

bool MySQLTable::output(QTableWidget* table)
{
	if (table == nullptr || content.isEmpty() || !isProcessed)
		return false;

	table->clear();
	table->setRowCount(nRows);
	table->setColumnCount(nCols);

	for (int row = 0; row < nRows; ++row)
		for (int col = 0; col < nCols; ++col)
			table->setItem(row, col, &content[row][col]);

	return true;
}