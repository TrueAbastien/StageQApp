#pragma once
#include "Page.h"

class ConnectionPage : public Page
{
public:
	explicit ConnectionPage(QtSquid* ref);

	void handle() override { }
};