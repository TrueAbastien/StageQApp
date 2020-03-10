#pragma once
#include <QObject>
#include <QMessageBox>

#include <mysql.h>
#include <QTableWidget>

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

public:
	Database();
	~Database();

	bool connected() const { return isConnected; }

	bool connect(QString ip, int port, QString username, QString password, QString dbName);
	QString getLastError() const;

	bool runQuery(QString query);
	bool computeModel(QTableWidget* wdg);
	QString debug_result();
};