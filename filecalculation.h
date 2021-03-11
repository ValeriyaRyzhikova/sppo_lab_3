#ifndef FILECALCULATION_H
#define FILECALCULATION_H
#include "abstractcalculation.h"
#include <QMap>
#include <QString>
#include <QDir>



class FileCalculation:public AbstractCalculation
{
private:
    unsigned long long returnElementSize(QFileInfo);
public:
    FileCalculation();
    ~FileCalculation();
public slots:
    void execute(QDir);
};

#endif // FILECALCULATION_H
