#include "contentfortableview.h"

void ContentForTableView::updateContent(const QMap<QString,float> &m){
    beginRemoveRows(QModelIndex(), 0, elements_.size()-1);
    elements_ = makeMapToVector(m);
    endRemoveRows();
    endInsertRows();
}


QVector<QPair<QString,QString>> ContentForTableView::makeMapToVector(const QMap<QString, float> &m)
{
    QVector<QPair<QString,QString>> result;
    QMapIterator<QString, float> iter(m);
    while (iter.hasNext()) {
        iter.next();
        result.push_back(QPair(iter.key(),transleteFloatToQString(iter.value())));
    }
    return result;
}

QString ContentForTableView::transleteFloatToQString(float size)
{
    size*=100;
    if (size < 0.01 && size!=0)
        return"<0.01%";
    return QString::number(size, 'f', 2)+"%";
}

QVariant ContentForTableView::data(const QModelIndex& index, int role) const{
    if (role == Qt::DisplayRole){
        int column = index.column();
        int row = index.row();

        if (column == NAME_COLUMN)
            return elements_[row].first;
        else if (column == SIZE_COLUMN)
            return elements_[row].second;
        else return QVariant();
    } else return QVariant();
}

QVariant ContentForTableView::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole){
        if (Qt::Vertical == orientation)
            return section;

        else{
            if (section == SIZE_COLUMN) {
                return "Size";
            }
            else {
                if (section == NAME_COLUMN)
                return "Name";

                return QVariant();
            }
        }
    }
    else {
        if (role == Qt::TextAlignmentRole)
        return Qt::AlignLeft;

        else {
            return QVariant();
        }
    }
}

int ContentForTableView::rowCount(const QModelIndex&) const{
    return elements_.size();
}

int ContentForTableView::columnCount(const QModelIndex&) const{
    return NUMBER_OF_COLUMNS;
}
