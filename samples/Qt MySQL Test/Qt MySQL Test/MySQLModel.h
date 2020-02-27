#pragma once
#include <QAbstractTableModel>

#define COL_LIMIT 32

class MySQLModel : public QAbstractTableModel
{
public:
    MySQLModel(QObject* parent = Q_NULLPTR);
    int columnCount(const QModelIndex& parent) const;
    int rowCount(const QModelIndex& parent) const;
    QPair<int, int> dims() const;
    Qt::ItemFlags flags(const QModelIndex& index) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setHeaderData(int section, const QVariant& value, int role = Qt::EditRole);
    bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex());
    void addData(const QVariantList& data);
    bool resizeCols(int size);

private:
    QList<QVariantList> m_data;
    QVariantList m_headerData;
};