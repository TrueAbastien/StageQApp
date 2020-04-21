#pragma once
#include <QtSquid/core/page/Page.h>
#include <CreationWindow.h>

class CreationPage : public Page
{
	Q_OBJECT

public:
	CreationPage(QtSquid* ref, CreationWindow* wnd)
		: Page(ref), creationWndRef(wnd)
	{ }

	virtual void pressOkButton() = 0;

protected:
	CreationWindow* creationWndRef;
};