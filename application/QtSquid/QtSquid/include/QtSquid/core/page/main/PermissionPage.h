#pragma once
#include <QtSquid/core/page/Page.h>

/**
* Permission Page (undefined)
*
* Should handle permission add and change for any user or user group.
*/
class PermissionPage : public Page
{
	Q_OBJECT

public:
	explicit PermissionPage(QtSquid* ref);

	void handle() override { }
};