#include "MySQLModel.h"

MySQLModel::MySQLModel(QObject* parent) : QAbstractTableModel(parent)
{
}

int MySQLModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_headerData.size();
}

int MySQLModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_data.size();
}

QPair<int, int> MySQLModel::dims() const
{
	return QPair<int, int>(m_headerData.size(), m_data.size());
}

Qt::ItemFlags MySQLModel::flags(const QModelIndex& index) const
{
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QVariant MySQLModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() >= m_data.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole)
        return m_data.at(index.row()).at(index.column());
    return QVariant();
}

bool MySQLModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (!index.isValid() || role != Qt::EditRole || index.row() < 0 || index.row() >= m_data.count())
        return false;
    m_data[index.row()][index.column()] = value;
    emit dataChanged(index, index);
    return true;
}

QVariant MySQLModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || section < 0 || section >= m_headerData.count())
        return QVariant();

    if (orientation == Qt::Horizontal)
        return m_headerData[section];
    return section + 1;
}

bool MySQLModel::setHeaderData(int section, const QVariant& value, int role)
{
    if (section < 0 || section >= m_headerData.count() || role != Qt::EditRole)
        return false;
    m_headerData[section] = value;
    return true;
}

bool MySQLModel::insertRows(int row, int count, const QModelIndex&)
{
    beginInsertRows(QModelIndex(), row, row + count - 1);
    for (auto i = 0; i < count; ++i)
        m_data.insert(row, QVariantList());
    endInsertRows();
    return true;
}

bool MySQLModel::removeRows(int row, int count, const QModelIndex&)
{
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    for (auto i = 0; i < count; ++i)
        m_data.removeAt(row);
    endRemoveRows();
    return true;
}

void MySQLModel::addData(const QVariantList& data)
{
    this->m_data.append(data);
}

bool MySQLModel::resizeCols(int size)
{
    if (size < 0 || size > COL_LIMIT)
        return false;

    int deltaSize = size - m_headerData.size();
    if (deltaSize < 0)
    {
        for (int ii = 0; ii > deltaSize; --ii)
        {
            m_headerData.pop_back();
            for (auto& row : m_data)
                row.pop_back();
        }
    }
    else if (deltaSize > 0)
    {
        for (int ii = 0; ii < deltaSize; ++ii)
        {
            m_headerData.append("NULL");
            for (auto& row : m_data)
                row.append("NULL");
        }
    }
    return true;
}
