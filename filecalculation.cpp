#include "filecalculation.h"

FileCalculation::FileCalculation(){}

FileCalculation::~FileCalculation(){}

QMap<QString, float> FileCalculation::execute(QDir dir)
{
    QMap<QString, float> result;
    QFileInfoList dirElements = dir.entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries);
    int sumSize=0;
    int elementSize;
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

    return result;
}


int FileCalculation::returnElementSize(QFileInfo element)
{
    if(element.isDir()){
        int elementSize=0;
        QDir dir(element.absoluteFilePath());
        QFileInfoList dirElements = dir.entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries);

        for(const auto &elementInsideElement: dirElements)
            elementSize+=returnElementSize(elementInsideElement);

        return elementSize;
    }
    return element.size();
}
