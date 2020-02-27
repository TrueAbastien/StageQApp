#include "BarcodeScanner.h"
#include "ApplicationWnd.h"

#include "LocalDebugging.h"

BarcodeScanner::BarcodeScanner(ApplicationWnd* wnd)
	: _parent(wnd), isActivated(false)
{
	buffer = "";
	mTimer = new QTimer();

	//Debug::Log("Instantiated !"); //DEBUG

	connect(wnd, SIGNAL(key_press()), this, SLOT(scan()));
	connect(mTimer, SIGNAL(timeout()), this, SLOT(terminate()));
}

QString BarcodeScanner::get()
{
	QString res = buffer;
	buffer = "";
	isActivated = false;
	return res;
}

void BarcodeScanner::scan()
{
	if (isActivated)
	{
		buffer += _parent->__latest_key_pressed;
		Reset();
	}
}

void BarcodeScanner::Reset()
{
	mTimer->start(msSequenceBreaker);
}

void BarcodeScanner::activate()
{
	_parent->grabKeyboard();

	isActivated = true;
	QMessageBox::information(nullptr, "Barcode", "Scanning Activated...");
}

void BarcodeScanner::terminate()
{
	_parent->releaseKeyboard();

	isActivated = false;
	mTimer->stop();
	emit print();
}