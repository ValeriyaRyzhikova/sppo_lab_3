#include "typecalculation.h"

TypeCalculation::TypeCalculation(){}

TypeCalculation::~TypeCalculation(){}

int TypeCalculation::calculateMapOfType(QFileInfo element, QMap<QString, float>& map)
{
    int elementSize=0;
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

QMap<QString, float> TypeCalculation::execute(QDir dir)
{
    QMap<QString, float> result;

    int sumSize=calculateMapOfType(QFileInfo(dir.absolutePath()), result);

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
    return result;
}


