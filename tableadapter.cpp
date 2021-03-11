#include "tableadapter.h"

TableAdapter::TableAdapter()
{
    model = new ContentForTableView();
    view = new QTableView();
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    view->setModel(model);
}

TableAdapter::~TableAdapter()
{
    delete view;
    delete model;
}

void TableAdapter::updateAdapter(QMap<QString, float> map)
{
    model->updateContent(map);
    emit sentMainwindow(view);
}

