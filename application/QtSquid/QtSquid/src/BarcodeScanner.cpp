#include <QtSquid/tool/BarcodeScanner.h>
#include <QtSquid.h>


BarcodeScanner::BarcodeScanner(QtSquid* wnd)
	: app(wnd), isActivated(false)
{
	buffer = "";
	mTimer = new QTimer();

	connect(wnd, SIGNAL(key_press(QString)), this, SLOT(scan(QString)));
	connect(mTimer, SIGNAL(timeout()), this, SLOT(terminate()));
}

QString BarcodeScanner::get()
{
	QString res = buffer;
	buffer = "";
	isActivated = false;
	return res;
}

void BarcodeScanner::scan(QString str)
{
	if (isActivated)
	{
		buffer.append(str);
		Reset();
	}
}

void BarcodeScanner::Reset()
{
	mTimer->start(msSequenceBreaker);
}

void BarcodeScanner::activate()
{
	app->grabKeyboard();

	isActivated = true;
	QMessageBox::information(nullptr, "Barcode", "Scanning Activated...");
}

void BarcodeScanner::terminate()
{
	app->releaseKeyboard();

	isActivated = false;
	mTimer->stop();
	emit print();
}