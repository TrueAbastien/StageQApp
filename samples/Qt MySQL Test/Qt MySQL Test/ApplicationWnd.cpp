#include "ApplicationWnd.h"

#include "LocalDebugging.h"

ApplicationWnd::ApplicationWnd(QWidget *parent)
	: QMainWindow(parent), bs(this)
{
	ui.setupUi(this);

	connect(ui.connectBtn, SIGNAL(clicked()), this, SLOT(connectDatabase()));
	connect(ui.runBtn, SIGNAL(clicked()), this, SLOT(runCurrentQuery()));

	connect(ui.actionBarcode, SIGNAL(triggered()), &bs, SLOT(activate()));
	connect(&bs, SIGNAL(print()), this, SLOT(writeInEdit()));

	//ui.resultView->setModel(&db.tableModel);
}

void ApplicationWnd::connectDatabase()
{
	if (db.connect("localhost", 3306, "root", "", "testing"))
	{
		QMessageBox::information(this, "Connection", "Successfull !");
	}
	else
	{
		QMessageBox::information(this, "Connection", "Failed: " + db.getLastError());
	}
}

void ApplicationWnd::keyPressEvent(QKeyEvent* evt)
{
	__latest_key_pressed = evt->text();
	//Debug::Log("Press Sent !"); //DEBUG
	emit key_press();
}

void ApplicationWnd::runCurrentQuery()
{
	//ui.resultText->clear();

	if (!db.connected())
	{
		//ui.resultText->append("Connection hasn't been established yet !");
		return;
	}

	bool call = db.runQuery(ui.queryEdit->text());
	if (!call) return;

	//QStringList res = db.debug_result().split("\n");
	/*
	for (QString row : res)
		ui.resultText->append(row);
	*/
	db.computeModel(ui.resultTable);
}

void ApplicationWnd::writeInEdit()
{
	ui.queryEdit->setText(QString("SELECT * FROM equipment e JOIN item i ON e.item_id = i.id WHERE i.barcode = ") + bs.get());
}
