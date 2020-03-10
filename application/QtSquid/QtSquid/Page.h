#pragma once
#include <QObject>
#include "QtSquid.h"

class Page : public QObject
{
	Q_OBJECT

public:
	explicit Page(QtSquid* ref) : wndRef(ref) { }

	virtual void handle() = 0;

protected:
	QtSquid* wndRef;
};