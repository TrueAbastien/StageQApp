#pragma once
#include <QObject>
#include <QTimer>
#include <QMessageBox>

class QtSquid;

class BarcodeScanner : public QObject
{
	Q_OBJECT

public:
	explicit BarcodeScanner(QtSquid* wnd);

	bool isActivated;

	QString get();

public slots:
	void activate();
	void scan();

signals:
	void print();

private slots:
	void terminate();

private:
	QtSquid* _parent;

	QTimer* mTimer;
	QString buffer;
	const int msSequenceBreaker = 50;

	void Reset();
};