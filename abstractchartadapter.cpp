#include "abstractchartadapter.h"

AbstractChartAdapter::AbstractChartAdapter()
{
    view_ = new QtCharts::QChartView();
    widget_=view_;
    model_ = new QtCharts::QChart();
    view_->setRenderHint(QPainter::Antialiasing);
    view_->setChart(model_);
    showLegend();
}

AbstractChartAdapter::~AbstractChartAdapter()
{
    delete view_;
    //delete model; - модель не нужно удалять т.к. QChartView - родительский класс QChart
}

void AbstractChartAdapter::updateAdapter(QMap<QString,float> m)
{
    model_->removeAllSeries();
    model_->addSeries(putDataInSeries(makeMapToVector(m)));
    model_->setAnimationOptions(QtCharts::QChart::SeriesAnimations);
}

void AbstractChartAdapter::showLegend()
{
    model_->legend()->setVisible(true);
    model_->legend()->setAlignment(Qt::AlignRight);
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


