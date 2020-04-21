#pragma once
#include <QObject>
#include <QMessageBox>

#include <mysql.h>
#include <QTableWidget>

#include <QtSquid/sql/Query.h>

class MySQLTable;

class Database : public QObject
{
	Q_OBJECT

private:
	bool isConnected;
	int qstate;

	MYSQL* conn;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL_FIELD* field;

	MySQLTable* table;

	QString latestCSVResults;
	QMap<QString, QStringList> latestTableResults;
	bool processedTable = false;

public:
	Database();
	~Database();

	bool connected() const { return isConnected; }

	bool connect(QString ip, int port, QString username, QString password, QString dbName);
	QString getLastError() const;

	bool runQuery(Query* query, QString order = "");
	bool runRawQuery(QString query, bool compute = true);
	bool computeModel(QTableWidget* wdg);

	QMap<QString, QStringList> result();
	QString CSVresults();

signals:
	void successfulConnection();
};