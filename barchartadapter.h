#ifndef BARCHARTADAPTER_H
#define BARCHARTADAPTER_H

#include "abstractchartadapter.h"

class BarChartAdapter : public AbstractChartAdapter
{
public:
    BarChartAdapter();
    ~BarChartAdapter();
private:
    QtCharts::QAbstractSeries* putDataInSeries (const QVector<QPair<QString,float>>&);
    QtCharts::QValueAxis *axisY;
};

#endif // BARCHARTADAPTER_H
