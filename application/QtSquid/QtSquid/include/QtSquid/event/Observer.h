#pragma once
#include <QtSquid/event/EventSystem.h>

class Observer
{
private:
	EventSystem* instance;

public:
	explicit Observer(EventSystem* system)
		: instance(system)
	{ }

protected:
	template <typename L> bool handle(const QObject* obj, const QMetaMethod& signal, L func)
	{
		return instance->join(obj, signal, func);
	}
};