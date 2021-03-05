#include <QCoreApplication>
#include "filecalculation.h"
#include "abstractcalculation.h"
#include <QMap>
#include <QString>
#include <QDir>
#include<iostream>

QString CreateStringForElement(QString string, float size)
{
    size*=100;
    QString result = string + " ";
    if (size < 0.01)
        result+="<0.01%";
    else{
        result+=QString::number(size, 'f', 2)+"%";
    }
    result+="\n";
    return result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir("C:\\Users\\domaG\\Documents\\sppo_lab\\test");
    AbstractCalculation *b= new FileCalculation;
    QMap<QString,float> result=b->execute(dir);

    QMapIterator<QString, float> iter(result);
    while (iter.hasNext()) {
        iter.next();
        std::cout<< CreateStringForElement(iter.key(), iter.value()).toStdString();
    }
    std::cout<<std::endl;
    return a.exec();
}
