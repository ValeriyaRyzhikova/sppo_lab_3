#include "tableadapter.h"

TableAdapter::TableAdapter()
{
    model_ = new ContentForTable();
    view_ = new QTableView();
    widget_=view_;
    view_->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    view_->setModel(model_);
}

TableAdapter::~TableAdapter()
{
    delete view_;
    delete model_;
}

void TableAdapter::updateAdapter(QMap<QString, float> data)
{
    model_->updateContent(makeMapToVector(data));
}

QVector<QPair<QString,QString>> TableAdapter::makeMapToVector(const QMap<QString, float> &m)
{
    QVector<QPair<QString,QString>> result;
    QMapIterator<QString, float> iter(m);
    while (iter.hasNext()) {
        iter.next();
        result.push_back(QPair(iter.key(),transleteFloatToQString(iter.value())));
    }
    return result;
}
