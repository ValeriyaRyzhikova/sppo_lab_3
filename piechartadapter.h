#ifndef PIECHARTADAPTER_H
#define PIECHARTADAPTER_H

#include "abstractchartadapter.h"

class PieChartAdapter: public AbstractChartAdapter
{
public:
    PieChartAdapter(){};
    ~PieChartAdapter(){};
private:
    QtCharts::QAbstractSeries* putDataInSeries (const QVector<QPair<QString,float>>&);

};


#endif // PIECHARTADAPTER_H
