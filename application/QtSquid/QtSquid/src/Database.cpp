#include <QtSquid/sql/Database.h>
#include <QtSquid/sql/MySQLTable.h>


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

bool Database::runQuery(Query* query, QString order)
{
	return runRawQuery(query->get(order), query->getType() == Query::Type::SELECT);
}

bool Database::runRawQuery(QString query, bool compute)
{
	if (!isConnected)
		return false;
	qstate = mysql_query(conn, query.toStdString().c_str());

	if (!qstate)
	{
		res = mysql_store_result(conn);

		if (compute)
		{
			latestCSVResults = "";
			int size = 0;
			while (field = mysql_fetch_field(res))
			{
				latestCSVResults += QString(field->name) + ";";
				size++;
			}
			latestCSVResults += "\n";
			while (row = mysql_fetch_row(res))
			{
				for (int ii = 0; ii < size; ++ii)
					latestCSVResults += QString(row[ii] == NULL ? "- none -" : row[ii]) + ";";
				latestCSVResults += "\n";
			}
			processedTable = false;
		}

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

QMap<QString, QStringList> Database::result()
{
	if (!processedTable)
	{
		QList<QStringList> listContent;
		foreach(QString row, CSVresults().split("\n"))
			listContent.append(row.left(row.size() - 1).split(";"));
		listContent.removeLast();

		latestTableResults.clear();
		QStringList values;
		int size = listContent.size(), count = 0;
		foreach(QString key, listContent[0])
		{
			values.clear();
			for (int ii = 1; ii < size; ++ii)
				values.push_back(listContent[ii][count]);
			latestTableResults.insert(key, values);
			count++;
		}

		processedTable = true;
	}
	return latestTableResults;

	
}

QString Database::CSVresults()
{
	return latestCSVResults;
}

bool Database::connect(QString ip, int port, QString username, QString password, QString dbName)
{
	if (isConnected)
		return false;
	conn = mysql_real_connect(conn, ip.toStdString().c_str(), username.toStdString().c_str(),
		password.toStdString().c_str(), dbName.toStdString().c_str(), port, NULL, 0);
	isConnected = (conn != nullptr);
	emit successfulConnection();
	return isConnected;
}