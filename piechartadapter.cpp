#include "piechartadapter.h"

QtCharts::QAbstractSeries* PieChartAdapter::putDataInSeries(const QVector<QPair<QString,float>> &data){
    QtCharts::QPieSeries *series = new QtCharts::QPieSeries();
    for (auto i = data.begin(); i != data.end(); i++) {
        series->append(new QtCharts::QPieSlice(i->first, i->second));
    }
return series;
}
