#include "tableadapter.h"

TableAdapter::TableAdapter()
{
    model = new ContentForTable();
    view = new QTableView();
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    view->setModel(model);
}

TableAdapter::~TableAdapter()
{
    delete view;
    delete model;
}

void TableAdapter::updateAdapter(QMap<QString, float> data)
{
    model->updateContent(makeMapToVector(data));
    emit sentMainwindow(view);
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
