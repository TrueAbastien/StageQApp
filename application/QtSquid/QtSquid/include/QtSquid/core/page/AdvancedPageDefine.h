#pragma once
#include <AdvancedWindow.h>

class CreationPage : public AdvancedPage
{
	Q_OBJECT

public:
	CreationPage(QtSquid* ref, CreationWindow* wnd)
		: AdvancedPage(ref), advWndRef(wnd)
	{ }

protected:
	CreationWindow* advWndRef;
};

class SettingPage : public AdvancedPage
{
	Q_OBJECT

public:
	SettingPage(QtSquid* ref, SettingWindow* wnd)
		: AdvancedPage(ref), advWndRef(wnd)
	{ }

protected:
	SettingWindow* advWndRef;
};