#include "ApplicationWnd.h"
#include <QtWidgets/QApplication>

#include <QtSql>
#include <QSqlDatabase>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ApplicationWnd w;

	/*auto res = QSqlDatabase::drivers();
	w.connectDatabase();*/

	/*MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "192.168.56.1", "root", "", "testing", 0, NULL, 0);
	if (conn)
	{
		QMessageBox::information(&w, "Connection", "Successfull !");
	}
	else
	{
		QMessageBox::information(&w, "Connection", "Failed...");
	}*/

	w.show();
	return a.exec();
}
