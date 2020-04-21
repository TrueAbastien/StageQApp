#pragma once
#include <QtSquid/core/page/Page.h>
#include <QtSquid/sql/Query.h>
#include <QtSquid/core/file/FileLogger.h>

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