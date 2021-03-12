#include "barchartadapter.h"

BarChartAdapter::BarChartAdapter()
{
    axisY = new QtCharts::QValueAxis();
    axisY->setRange(0,100);
    model->addAxis(axisY, Qt::AlignLeft);
}

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
