#pragma once
#include <QObject>
#include <QtSquid.h>

/**
* Page class
*
* Abstract class used to handle every Stacked Widget page change.
* Especially used in main window and inherited by Advanced Pages in secondary windows.
*/
class Page : public QObject
{
	Q_OBJECT

public:
	explicit Page(QtSquid* ref) : wndRef(ref)
	{
		connect(&ref->database, SIGNAL(successfulConnection()), this, SLOT(onDatabaseConnect()));
	}

	virtual void handle() = 0;

protected:
	QtSquid* wndRef;

protected slots:
	virtual void onDatabaseConnect() { }
};