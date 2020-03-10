#pragma once
#include "Page.h"

class SearchPage : public Page
{
public:
	explicit SearchPage(QtSquid* ref);

	void handle() override { }

private slots:
	void ComputeScan(const QString& val);
};