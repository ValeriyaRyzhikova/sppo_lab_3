#ifndef TABLEADAPTER_H
#define TABLEADAPTER_H
#include "abstractadapter.h"
#include <QTableView>
#include <QHeaderView>
#include "contentfortableview.h"


class TableAdapter:public AbstractAdapter
{
private:
    QTableView *view;
    ContentForTableView *model;
public:
    TableAdapter();
    ~TableAdapter();
public slots:
    void updateAdapter(QMap<QString,float>);

};

#endif // TABLEADAPTER_H
