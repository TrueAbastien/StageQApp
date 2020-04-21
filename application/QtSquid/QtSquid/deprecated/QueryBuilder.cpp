#include "QueryBuilder.h"

#include <cstdarg>


#define NULL_KEY "_NULL_"


QStringList __processingVariadicArgumentsAsStringList(const char* content ...)
{
	QStringList result;
	va_list args;
	va_start(args, content);
	while (*content != '\0')
	{
		if (*content == 'c')
			result.append(va_arg(args, char*));
		++content;
	}
	va_end(args);
	return result;
}

QList<QStringList> __dismantleStringListBySpace(QStringList content)
{
	QList<QStringList> result;
	unsigned int size = content.size(), count;
	for (int ii = 0; ii < size; ++ii)
	{
		result.append(QStringList());
		count = 0;
		foreach(QString str, content[ii].split(' '))
		{
			if (count >= 2) break;
			if (str.toLower() == "as") continue;
			result[ii].append(str);
			count++;
		}
		if (count == 0)
		{
			result.removeLast();
			ii--;
		}
	}
	return result;
}


// --- //


Query::Action::Action(Query* ref)
	: reference(ref), processed(false), content("")
{
	reference->current = this;
}

void Query::Action::process()
{
	if (processed)
		return;

	processed = processing();
}

Query::Select::Select(Query* ref, QList<QPair<QString, QString>> fields)
	: Action(ref)
{
	foreach(auto field, fields)
	{
		if (field.first.contains('.'))
			reference->fields.append({ field.first.right('.'), field.first.left('.'), field.second });
		else reference->fields.append({ field.first, NULL_KEY, field.second });
	}
}

QString Query::Action::get()
{
	process();
	return content.join(" ");
}

Query::Select* Query::Select::from(const char* tables ...)
{
	processed = false;
	auto res = __dismantleStringListBySpace(__processingVariadicArgumentsAsStringList(tables));

	int count;
	foreach(QStringList table, res)
	{
		if (table.size() == 1)
		{
			for (count = 1; count < table[0].size(); count++)
				if (!reference->tables.contains(table[0].left(count))
					&& !reference->jointures.contains(table[0].left(count)))
					break;
			reference->tables.insert(table[0].left(count), table[0]);
		}
		else if (!reference->tables.contains(table[1])
			&& !reference->jointures.contains(table[1]))
			reference->tables.insert(table[1], table[0]);
	}

	return this;
}

Query::Select* Query::Select::join(QString table, QString alias, const char* conditions ...)
{
	if (!reference->tables.contains(alias))
	{
		processed = false;
		auto res = __processingVariadicArgumentsAsStringList(conditions);

		reference->jointures.insert(alias, { table,res });
	}

	return this;
}

Query::Select* Query::Select::group(QString field, QString table)
{
	QString res = reference->tables.key(table, NULL_KEY);
	if (res != NULL_KEY)
	{
		processed = false;
		reference->groups.append({ field, res });
	}

	return this;
}

Query::Select* Query::Select::order(QString field, QString table)
{
	QString res = reference->tables.key(table, NULL_KEY);
	if (res != NULL_KEY)
	{
		processed = false;
		reference->orders.append({ field, res });
	}

	return this;
}

bool Query::Select::processing()
{
	// TODO:
	// Process Selected Field
	/*foreach(auto field, reference->fields)
		if ((!reference->tables.contains(field[1])
			&& reference->tables.key(field[0], NULL_KEY) == NULL_KEY)
			|| (!reference->jointures.contains(field.first.left('.'))
				&& true))
			return false;*/

	// Verify Integrity of Query Lists


	// Compute/Redact Content

	return true;
}

Query::Query()
	: current(nullptr)
{
	clear();
}

Query::~Query()
{
	if (current != nullptr)
		delete current;
}

QString Query::get() const
{
	return current->get();
}

void Query::clear()
{
	tables.clear();
	fields.clear();
	jointures.clear();
	conditions.clear();
	orders.clear();
	groups.clear();
}

Query::Select* Query::select(const char* fields ...)
{
	clear();

	auto res = __dismantleStringListBySpace(__processingVariadicArgumentsAsStringList(fields));
	QList<QPair<QString, QString>> selectedFields;
	foreach(QStringList field, res)
	{
		if (field.size() == 1)
			selectedFields.append({ field[0], NULL_KEY });
		else selectedFields.append({ field[0], field[1] });
	}

	current = new Select(this, selectedFields);
	return nullptr;
}
