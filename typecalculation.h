#ifndef TYPECALCULATION_H
#define TYPECALCULATION_H
#include "abstractcalculation.h"
#include <QMap>
#include <QString>
#include <QDir>


class TypeCalculation:public AbstractCalculation
{
private:
    int calculateMapOfType(QFileInfo, QMap<QString, float>&);
public:
    TypeCalculation();
    ~TypeCalculation();
    QMap<QString, float> execute(QDir);
};

#endif // TYPECALCULATION_H
