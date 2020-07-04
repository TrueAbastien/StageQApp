#pragma once
#include <QtSquid/core/page/Page.h>

/**
* ConnectionPage class
*
* Page used to handle connection local and database-sided settings.
* Allow user to change its username & password or to change connected
* database IP address & surename.
*/
class ConnectionPage : public Page
{
	Q_OBJECT

public:
	explicit ConnectionPage(QtSquid* ref);

	void handle() override { }

private:
	SettingFile databaseData;

	QMap<QString, QPair<QLineEdit*, QLabel*>> binds;
	void bind(QString key, QLineEdit* wdg, QLabel* lab);

	void writeValue(QStringList keys);
	void setSaved(QStringList keys, bool isSaved = true);

private slots:
	void connectDatabase();

	void saveDatabaseData();
	void saveUserData();

	void writeEditData(QString key);

	void setSilentConnect();
};