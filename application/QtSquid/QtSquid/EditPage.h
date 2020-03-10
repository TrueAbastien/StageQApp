#pragma once
#include "Page.h"

class EditPage : public Page
{
public:
	explicit EditPage(QtSquid* ref);

	void handle() override { }
};