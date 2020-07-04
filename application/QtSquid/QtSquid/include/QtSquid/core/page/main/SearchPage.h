#pragma once
#include <QtSquid/core/page/Page.h>
#include <QtSquid/sql/Query.h>
#include <QtSquid/core/file/FileLogger.h>

/**
* SearchPage class
*
* Handle search query through keyboard or barcode scanner input.
* Allow for easy input which run SELECT command accordingly.
*
* Results will be printed out in same page Table Widget.
*/
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