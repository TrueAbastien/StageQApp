#include "Query.h"

#include <QString>
#include <cstdarg>

//QStringList __processingVariadicArgumentsAsStringList(const char* content ...)
//{
//	QStringList result;
//	va_list args;
//	va_start(args, content);
//	while (*content != '\0')
//	{
//		if (*content == 'c')
//			result.append(va_arg(args, char*));
//		++content;
//	}
//	va_end(args);
//	return result;
//}


// --------------------------------------------------------------------------------------------- //


Query* Query::Select(QString view)
{
	return new Query("SELECT /fields FROM " + view + " WHERE /conditions");
}

Query* Query::set(QStringList fields)
{
	this->fields = fields;
	return this;
}

Query* Query::add(QStringList fields)
{
	foreach(QString field, fields)
		if (!this->fields.contains(field))
			this->fields.push_back(field);
	return this;
}

Query* Query::remove(QStringList fields)
{
	foreach(QString field, fields)
		this->fields.removeOne(field);
	return this;
}

Query* Query::where(QStringList conditions)
{
	foreach(QString condition, conditions)
		if (!this->conditions.contains(condition))
			this->conditions.push_back(condition);
	return this;
}

Query* Query::free()
{
	this->conditions.clear();
	this->conditions.push_back("1=1");
	return this;
}

QString Query::get(QString order)
{
	if (fields.isEmpty())
		return "";

	QString result = QString(content);
	result.replace("/fields", fields.join(", ")).replace("/conditions", conditions.join(" AND "));
	return result + (order.isEmpty() ? "" : (" ORDER BY " + order));
}

Query::Query(QString content)
	: content(content), fields(0), conditions({ "1=1" })
{
}