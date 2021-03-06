#ifndef ABSTRACTCALCULATION_H
#define ABSTRACTCALCULATION_H
#include <QMap>
#include <QString>
#include <QDir>


class AbstractCalculation
{
public:
    AbstractCalculation();
    virtual ~AbstractCalculation();
    virtual QMap<QString, float> execute(QDir) = 0;

};

#endif // ABSTRACTCALCULATION_H
