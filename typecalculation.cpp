#include "typecalculation.h"

TypeCalculation::TypeCalculation(){}

TypeCalculation::~TypeCalculation(){}

unsigned long long TypeCalculation::calculateMapOfType(QFileInfo element, QMap<QString, float>& map)
{
    unsigned long long elementSize=0;
    if(element.isDir()){
        QDir dir(element.absoluteFilePath());
        QFileInfoList dirElements = dir.entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries);

        for(const auto &elementInsideElement: dirElements)
            elementSize+=calculateMapOfType(elementInsideElement, map);

        return elementSize;
    }

    elementSize=element.size();
    QString elementSuffix=element.suffix();
    if (map.contains(elementSuffix))
        map[element.suffix()]+=elementSize;
    else{
        map[element.suffix()]=elementSize;
    }

    return elementSize;
}

void TypeCalculation::execute(QDir dir)
{
    QMap<QString, float> result;

    unsigned long long sumSize=calculateMapOfType(QFileInfo(dir.absolutePath()), result);

    if(sumSize){
        QMapIterator<QString, float> iter(result);
        while (iter.hasNext()) {
            iter.next();
            result[iter.key()] /= sumSize;
        }
    }
    else{
        QMapIterator<QString, float> iter(result);
        while (iter.hasNext()) {
            iter.next();
            result[iter.key()] = 1;
        }
    }
    previousCalculation_=result;
    bringUpSentAdapter();
}


