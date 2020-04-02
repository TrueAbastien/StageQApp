#pragma once
#include "Page.h"
#include "Query.h"
#include "FileLogger.h"

class SearchPage : public Page
{
	Q_OBJECT

public:
	explicit SearchPage(QtSquid* ref);

	void handle() override { }

	~SearchPage();

private:
	Query* searching = nullptr;

private slots:
	void ComputeScan();
};