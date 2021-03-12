#ifndef TABLEADAPTER_H
#define TABLEADAPTER_H
#include "abstractadapter.h"
#include <QTableView>
#include <QHeaderView>
#include "contentfortable.h"


class TableAdapter:public AbstractAdapter
{
private:
    QTableView *view;
    ContentForTable *model;
    QVector<QPair<QString,QString>> makeMapToVector(const QMap<QString, float> &);
public:
    TableAdapter();
    ~TableAdapter();
public slots:
    void updateAdapter(QMap<QString,float>);

};

#endif // TABLEADAPTER_H
