#pragma once
#include "Page.h"

class PermissionPage : public Page
{
	Q_OBJECT

public:
	explicit PermissionPage(QtSquid* ref);

	void handle() override { }
};