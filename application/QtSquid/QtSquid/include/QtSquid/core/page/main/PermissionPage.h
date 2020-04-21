#pragma once
#include <QtSquid/core/page/Page.h>

class PermissionPage : public Page
{
	Q_OBJECT

public:
	explicit PermissionPage(QtSquid* ref);

	void handle() override { }
};