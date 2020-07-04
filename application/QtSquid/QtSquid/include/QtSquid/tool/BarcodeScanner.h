#pragma once
#include <QObject>
#include <QTimer>
#include <QMessageBox>

class QtSquid;

/**
* BarcodeScanner class
*
* Object used to handle to Barcode Scanner input (succession of keyboard input).
* Will send out a String data scanned when activated by waiting until no input is sent.
*/
class BarcodeScanner : public QObject
{
	Q_OBJECT

public:
	explicit BarcodeScanner(QtSquid* wnd);

	bool isActivated;

	QString get();

public slots:
	void activate();
	void scan(QString);

signals:
	void print();

private slots:
	void terminate();

private:
	QtSquid* app;

	QTimer* mTimer;
	QString buffer;
	const int msSequenceBreaker = 50;

	void Reset();
};