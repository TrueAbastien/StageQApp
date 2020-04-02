#include "Database.h"
#include "MySQLTable.h"


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
		return true;
	}
	return false;
}

bool Database::computeModel(QTableWidget* wdg)
{
	bool result;
	result = table->input(this);
	if (!result) return false;

	result = table->output(wdg);
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
			result += QString(row[ii] == NULL ? "- none -" : row[ii]) + ";";
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