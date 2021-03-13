#ifndef ABSTRACTCHARTADAPTER_H
#define ABSTRACTCHARTADAPTER_H
#include<QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include<QString>
#include<QPair>
#include "abstractadapter.h"

class AbstractChartAdapter : public AbstractAdapter
{
protected:
    QtCharts::QChart *model;
    QtCharts::QChartView *view;
    virtual QtCharts::QAbstractSeries* putDataInSeries(const QVector<QPair<QString,float>> &)=0;
    void showLegend();
    QVector<QPair<QString,float>> makeMapToVector(const QMap<QString, float> &);
public:
    AbstractChartAdapter();
    ~AbstractChartAdapter();
public slots:
    void updateAdapter(QMap<QString,float>);
};

#endif // ABSTRACTCHARTADAPTER_H
