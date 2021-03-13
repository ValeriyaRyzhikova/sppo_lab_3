#include "filecalculation.h"

FileCalculation::FileCalculation(){}

FileCalculation::~FileCalculation(){}

void FileCalculation::execute(QDir dir)
{
    QMap<QString, float> result;
    QFileInfoList dirElements = dir.entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries);
    unsigned long long sumSize=0;
    unsigned long long elementSize;
    QString elementName;

    for(const auto &element: dirElements){
        elementName=element.fileName();
        elementSize=returnElementSize(element);
        sumSize+=elementSize;
        result[elementName]=elementSize;
    }

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


unsigned long long FileCalculation::returnElementSize(QFileInfo element)
{
    if(element.isDir()){
        unsigned long long elementSize=0;
        QDir dir(element.absoluteFilePath());
        QFileInfoList dirElements = dir.entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries);

        for(const auto &elementInsideElement: dirElements)
            elementSize+=returnElementSize(elementInsideElement);

        return elementSize;
    }
    return element.size();
}
