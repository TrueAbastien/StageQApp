#pragma once
#include <QObject>
#include "QtSquid.h"

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