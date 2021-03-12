#include "contentfortable.h"

void ContentForTable::updateContent(const QVector<QPair<QString,QString>> &f){
    beginRemoveRows(QModelIndex(), 0, elements_.size()-1);
    elements_ = QVector<QPair<QString,QString>>();
    endRemoveRows();
    beginInsertRows(QModelIndex(), 0, f.size()-1);
    elements_ = f;
    endInsertRows();
}


QVariant ContentForTable::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole){
        int column = index.column();
        int row = index.row();

        if (column == NAME_COLUMN)
            return elements_[row].first;
        else{
            if (column == SIZE_COLUMN)
            return elements_[row].second;
            else{
                return QVariant();
            }
        }
    }
    else{
        return QVariant();
    }
}

QVariant ContentForTable::headerData(int section, Qt::Orientation orientation, int role) const{
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

int ContentForTable::rowCount(const QModelIndex&) const{
    return elements_.size();
}

int ContentForTable::columnCount(const QModelIndex&) const{
    return NUMBER_OF_COLUMNS;
}
