#pragma once
#include <QtSquid/core/page/Page.h>

class AdvancedPage : public Page
{
	Q_OBJECT

public:
	AdvancedPage(QtSquid* ref)
		: Page(ref)
	{ }

	virtual void pressOkButton() = 0;
};