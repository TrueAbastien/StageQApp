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
	return new Query(Type::SELECT, "SELECT /fields FROM " + view + " WHERE (/conditions)");
}

Query* Query::Insert(QString table)
{
	return new Query(Type::INSERT, "INSERT INTO " + table + " (/fields) VALUES /values");
}

Query* Query::Update(QString table)
{
	return new Query(Type::UPDATE, "UPDATE " + table + " SET /fieldValues WHERE (/conditions)");
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

Query* Query::addValues(QStringList values)
{
	values.append(values);
	return this;
}

Query* Query::setValues(QStringList values)
{
	values.clear();
	return addValues(values);
}

Query* Query::removeValues(QStringList values)
{
	foreach(QString val, values)
		values.removeOne(val);
	return this;
}

QString Query::get(QString order)
{
	if (fields.isEmpty())
		return "";
	QString result = QString(content), pValues = "";
	QStringList parseValues;

	switch (type)
	{
	case SELECT: // SELECT Command
		result.replace("/fields", fields.join(", "))
			.replace("/conditions", conditions.join(" AND "));
		return result + (order.isEmpty() ? "" : (" ORDER BY " + order));
		break;

	case INSERT: // INSERT Command
		if (values.isEmpty() || values.size() % fields.size())
			return "";
		result.replace("/fields", fields.join(", "));
		for (int ii = 0; ii < values.size(); ii += fields.size())
		{
			parseValues.clear();
			for (int jj = ii; jj < ii + fields.size(); ++jj)
				parseValues.push_back(values[jj]);
			pValues.push_back("(/vals), ");
			pValues.replace("/vals", parseValues.join(", "));
		}
		pValues.resize(pValues.size() - 2);
		return content.replace("/values", pValues);
		break;

	case UPDATE: // UPDATE Command
		if (values.isEmpty() || values.size() != fields.size())
			return "";
		for (int ii = 0; ii < fields.size(); ++ii)
			parseValues.push_back(fields[ii] + " = " + values[ii]);
		return result.replace("/fieldValues", parseValues.join(", "))
			.replace("/conditions", conditions.join(" AND "));
		break;

	default: return "";
	}
}

QString Query::toValue(QString& str)
{
	return "'" + str + "'";
}

Query::Query(Type _type, QString _content)
	: type(_type), content(_content), fields(0), conditions({ "1=1" }), values(0)
{
}