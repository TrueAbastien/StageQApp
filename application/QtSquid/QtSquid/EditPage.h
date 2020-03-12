#pragma once
#include "Page.h"

class EditPage : public Page
{
	Q_OBJECT

public:
	explicit EditPage(QtSquid* ref);

	void handle() override { }
};