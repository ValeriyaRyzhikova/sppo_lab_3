#ifndef ABSTRACTCALCULATION_H
#define ABSTRACTCALCULATION_H
#include <QMap>
#include <QString>
#include <QDir>


class AbstractCalculation: public QObject
{
    Q_OBJECT
protected:
    QMap<QString, float> previousCalculation_;
public:
    AbstractCalculation();
    void bringUpSentAdapter();
public slots:
    virtual void execute(QDir) = 0;
signals:
    void sentAdapter(QMap<QString, float>);
};

#endif // ABSTRACTCALCULATION_H
