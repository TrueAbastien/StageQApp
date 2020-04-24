#include <QtSquid/tool/QStringHelper.h>

QString QStringHelper::formatAtColor(QString text, QString color)
{
	return "<html><head/><body><p><span style = 'font-weight:600; color:#" + color + ";'>" + text + "</span></p></body></html>";
}

QString QStringHelper::Unchanged(QString str)
{
	int index = str.lastIndexOf("*");
	if (index == str.size() - 1)
		return str.remove("*");
	return str;
}

QString QStringHelper::Changed(QString str)
{
	return Unchanged(str).append("*");
}

QString QStringHelper::Error(QString str)
{
	return formatAtColor("ERROR: " + str, "c5220d");
}

QString QStringHelper::Success(QString str)
{
	return formatAtColor(str, "82d642");
}

QString QStringHelper::Info(QString str)
{
	return formatAtColor(str, "4692b0");
}

QString QStringHelper::BarcodeToInt(QString barcode)
{
	if (barcode.isEmpty())
		return barcode;

	while (barcode.at(0) == '0')
	{
		barcode = barcode.right(1);
		if (barcode.isEmpty())
			return barcode;
	}

	return barcode;
}

QString QStringHelper::IntToBarcode(QString integer)
{
	if (integer.isEmpty())
		return integer;

	while (integer.length() < 8)
		integer.push_front('0');

	return integer;
}
