#pragma once
#include <QtSquid/core/page/Page.h>

/**
* AdvancedPage class
*
* Inehrits Page class in order to handle stacked widget page and its interactions.
* Is especially used to handle Setting & Creation Pages.
*/
class AdvancedPage : public Page
{
	Q_OBJECT

public:
	AdvancedPage(QtSquid* ref)
		: Page(ref)
	{ }

	virtual void pressOkButton() = 0;
};