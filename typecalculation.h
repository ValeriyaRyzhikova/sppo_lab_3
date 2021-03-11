#ifndef TYPECALCULATION_H
#define TYPECALCULATION_H
#include "abstractcalculation.h"
#include <QMap>
#include <QString>
#include <QDir>


class TypeCalculation:public AbstractCalculation
{
private:
    unsigned long long calculateMapOfType(QFileInfo, QMap<QString, float>&);
public:
    TypeCalculation();
    ~TypeCalculation();
public slots:
    void execute(QDir);
};

#endif // TYPECALCULATION_H
