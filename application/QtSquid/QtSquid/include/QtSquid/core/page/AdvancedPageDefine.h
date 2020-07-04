#pragma once
#include <AdvancedWindow.h>

/**
* CreationPage class
*
* Handle page meant for creating item in MySQL database.
*/
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

/**
* CreationPage class
*
* Handle page meant for changing local application settings.
*/
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