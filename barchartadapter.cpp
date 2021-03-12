#include "barchartadapter.h"

BarChartAdapter::BarChartAdapter(){}

BarChartAdapter::~BarChartAdapter(){}

QtCharts::QAbstractSeries* BarChartAdapter::putDataInSeries(const QVector<QPair<QString,float>> &data){


    QtCharts::QBarSeries *series = new QtCharts::QBarSeries();
    for (auto i = data.begin(); i != data.end(); i++) {
        QtCharts::QBarSet *set = new QtCharts::QBarSet(i->first);
        set->operator<<(i->second);
        series->append(set);
    }
    return series;
}
