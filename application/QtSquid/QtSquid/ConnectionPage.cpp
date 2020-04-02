#include "ConnectionPage.h"

ConnectionPage::ConnectionPage(QtSquid* ref)
	: Page(ref), databaseData("database")
{
	connect(wndRef->ui.conn_runBtn, SIGNAL(clicked()), this, SLOT(connectDatabase()));

	databaseData.setRules({ "address","port","username","$password","database","db_silent_connect" });
	databaseData.readFile();

	bind("address", wndRef->ui.conn_editAddress, wndRef->ui.conn_labelAddress);
	bind("port", wndRef->ui.conn_editPort, wndRef->ui.conn_labelPort);
	bind("username", wndRef->ui.conn_editUsername, wndRef->ui.conn_labelUsername);
	bind("password", wndRef->ui.conn_editPassword, wndRef->ui.conn_labelPassword);

	connect(wndRef->ui.conn_editAddress, &QLineEdit::textChanged, [this]() { writeEditData("address"); });
	connect(wndRef->ui.conn_editPort, &QLineEdit::textChanged, [this]() { writeEditData("port"); });
	connect(wndRef->ui.conn_editUsername, &QLineEdit::textChanged, [this]() { writeEditData("username"); });
	connect(wndRef->ui.conn_editPassword, &QLineEdit::textChanged, [this]() { writeEditData("password"); });

	connect(wndRef->ui.conn_btnSaveDatabase, SIGNAL(clicked()), this, SLOT(saveDatabaseData()));
	connect(wndRef->ui.conn_btnSaveUser, SIGNAL(clicked()), this, SLOT(saveUserData()));

	connect(wndRef->ui.actionSilentConnect, SIGNAL(triggered()), this, SLOT(setSilentConnect()));
	wndRef->ui.actionSilentConnect->setChecked(databaseData.get("db_silent_connect").toLower() == "true");
	if (databaseData.get("db_silent_connect").toLower() == "true")
		connectDatabase();
}

void ConnectionPage::bind(QString key, QLineEdit* wdg, QLabel* lab)
{
	wdg->setText(databaseData.get(key));
	binds.insert(key, { wdg,lab });
}

void ConnectionPage::saveDatabaseData()
{
	setSaved({ "address","port" });
	writeValue({ "address","port" });
	databaseData.writeFile();
}

void ConnectionPage::saveUserData()
{
	setSaved({ "username","password" });
	writeValue({ "username","password" });
	databaseData.writeFile();
}

void ConnectionPage::writeEditData(QString key)
{
	setSaved({ key }, false);
}

void ConnectionPage::setSilentConnect()
{
	databaseData.set("db_silent_connect", wndRef->ui.actionSilentConnect->isChecked() ? "true" : "false");
	databaseData.writeFile();
}

void ConnectionPage::writeValue(QStringList keys)
{
	foreach (QString key, keys)
		databaseData.set(key, binds[key].first->text());
}

void ConnectionPage::setSaved(QStringList keys, bool isSaved)
{
	QString str;
	foreach(QString key, keys)
	{
		str = binds[key].second->text().remove('*');
		if (!isSaved)
			str.append('*');
		binds[key].second->setText(str);
	}
}

void ConnectionPage::connectDatabase()
{
	if (wndRef->database.connect(databaseData.get("address"), databaseData.get("port").toInt(),
		databaseData.get("username"), databaseData.get("password"), databaseData.get("database")))
	{
		wndRef->ui.conn_outputLabel->setText("Connection Successfull !");
	}
	else
	{
		QString errorMsg = wndRef->database.getLastError();
		if (errorMsg.isEmpty())
			wndRef->ui.conn_outputLabel->setText("You are already connected...");
		else wndRef->ui.conn_outputLabel->setText("Error: Connection Failed, " + wndRef->database.getLastError() + ".");
	}
}
