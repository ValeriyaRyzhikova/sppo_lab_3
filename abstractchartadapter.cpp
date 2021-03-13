#include "abstractchartadapter.h"

AbstractChartAdapter::AbstractChartAdapter()
{
    view = new QtCharts::QChartView();
    model = new QtCharts::QChart();
    view->setRenderHint(QPainter::Antialiasing);
    view->setChart(model);
    showLegend();
}

AbstractChartAdapter::~AbstractChartAdapter()
{
    delete view;
    //delete model; - модель не нужно удалять т.к. QChartView - родительский класс QChart
}

void AbstractChartAdapter::updateAdapter(QMap<QString,float> m)
{
    model->removeAllSeries();
    model->addSeries(putDataInSeries(makeMapToVector(m)));
    model->setAnimationOptions(QtCharts::QChart::SeriesAnimations);
    emit sentMainwindow(view);
}

void AbstractChartAdapter::showLegend()
{
    model->legend()->setVisible(true);
    model->legend()->setAlignment(Qt::AlignRight);
}

QVector<QPair<QString,float>> AbstractChartAdapter::makeMapToVector(const QMap<QString, float> &m)
{
    QVector<QPair<QString,float>> result;
    QMapIterator<QString, float> iter(m);
    while (iter.hasNext()) {
        iter.next();
        result.push_back(QPair(iter.key(),iter.value()));
    }
    return result;
}


