#pragma once
#include <QString>

/**
* QStringHelper class
*
* Helper class used to return modified QString for any specific use.
*/
class QStringHelper
{
private:
	static QString formatAtColor(QString text, QString color);

public:
	static QString Unchanged(QString str);
	static QString Changed(QString str);

	static QString Error(QString str);
	static QString Success(QString str);
	static QString Info(QString str);

	static QString BarcodeToInt(QString barcode);
	static QString IntToBarcode(QString integer);
};