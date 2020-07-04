#pragma once
#include <QObject>
#include <QMap>

/**
* EventSystem class (deprecated)
*
* Used to connect objects observing each others.
*/
class EventSystem : public QObject
{
	Q_OBJECT

public:
	template <typename L> bool join(const QObject* obj, const QMetaMethod& signal, L func)
	{
		return connect(obj, signal, func);
	}
};
