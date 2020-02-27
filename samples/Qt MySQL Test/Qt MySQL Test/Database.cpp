#include "Database.h"
#include "MySQLTable.h"

#include "LocalDebugging.h"

Database::Database()
	: isConnected(false), qstate(0), res(nullptr), field(nullptr), row(NULL)
{
	conn = mysql_init(0);
	table = new MySQLTable();
}

Database::~Database()
{
	//
}

QString Database::getLastError() const
{
	return mysql_error(conn);
}

bool Database::runQuery(QString query)
{
	if (!isConnected)
		return false;
	qstate = mysql_query(conn, query.toStdString().c_str());

	if (!qstate)
	{
		res = mysql_store_result(conn);
	}
	return true;
}

bool Database::computeModel(QTableWidget* wdg)
{
	/*
	QStringList content = debug_result().split("\n");
	if (content.empty())
		return false;

	// Clear
	tableModel.removeRows(0, tableModel.dims().first);
	tableModel.insertRows(0, content.size() - 1);

	// Header
	tableModel.resizeCols(content[0].size());
	QStringList tRes = content[0].split(";");
	for (int ii = 0; ii < tRes.size(); ++ii)
		tableModel.setHeaderData(ii, tRes[ii]);

	// Data
	for (int ii = 1; ii < content.size(); ++ii)
	{
		tRes = content[ii].split(";");
		if (tRes.size() != content[0].size())
			continue;
		for (int jj = 0; jj < content[ii].size(); ++jj)
			tableModel.setData(tableModel.index(ii, jj), tRes[jj]);
	}
	*/

	bool result;

	//Debug::Log("Going for Input"); //DEBUG

	result = table->input(this);
	//Debug::Log("End of Input"); //DEBUG
	if (!result) return false;

	//Debug::Log("Going for Output"); //DEBUG

	result = table->output(wdg);
	//Debug::Log("End of Output"); //DEBUG
	return result;
}

QString Database::debug_result()
{
	QString result = "";
	int size = 0;
	while (field = mysql_fetch_field(res))
	{
		result += QString(field->name) + ";";
		size++;
	}
	result += "\n";
	while (row = mysql_fetch_row(res))
	{
		for (int ii = 0; ii < size; ++ii)
			result += QString(row[ii] == NULL ? "NULL" : row[ii]) + ";";
		result += "\n";
	}
	return result;
}

bool Database::connect(QString ip, int port, QString username, QString password, QString dbName)
{
	if (isConnected)
		return false;
	conn = mysql_real_connect(conn, ip.toStdString().c_str(), username.toStdString().c_str(),
		password.toStdString().c_str(), dbName.toStdString().c_str(), port, NULL, 0);
	isConnected = (conn != nullptr);
	return isConnected;
}