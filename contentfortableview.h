#ifndef CONTENTFORTABLEVIEW_H
#define CONTENTFORTABLEVIEW_H
#include<QMap>
#include<QVector>
#include<QString>
#include <QVariant>
#include <QAbstractTableModel>

class ContentForTableView: public QAbstractTableModel
{
private:
    enum COLUMNS{
        NAME_COLUMN,
        SIZE_COLUMN,
        NUMBER_OF_COLUMNS
    };
    QVector<QPair<QString,QString>> elements_;
public:
    ContentForTableView(){};
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    void updateContent(const QVector<QPair<QString,QString>> &);
};

#endif // CONTENTFORTABLEVIEW_H
