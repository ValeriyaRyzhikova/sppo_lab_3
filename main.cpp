#include <QCoreApplication>
#include "abstractcalculation.h"
#include "filecalculation.h"
#include "typecalculation.h"
#include <QMap>
#include <QString>
#include <QDir>
#include<iostream>


QString CreateStringForElement(QString string, float size)
{
    size*=100;
    QString result = string + " ";
    if (size < 0.01 && size!=0)
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

    std::cout<<"Directory's name does't exist or is not name directory"<<std::endl;
    QDir dir1("..\\sppo_lab\\test\\name.txt");
    if (dir1.exists()){
        AbstractCalculation *s= new TypeCalculation;
        QMap<QString,float> result=s->execute(dir1);

        QMapIterator<QString, float> iter(result);
        while (iter.hasNext()) {
            iter.next();
            std::cout<< CreateStringForElement(iter.key(), iter.value()).toStdString();
        }
        std::cout<<std::endl;
        delete s;
    }
    else{
        std::cout<<"Directory does't exist"<<std::endl;
    }

    std::cout<<"\nDirectory with files and other directoryes"<<std::endl;
    std::cout<<"Stratege file:"<<std::endl;
    QDir dir2("..\\sppo_lab\\test");
    if (dir2.exists()){
        AbstractCalculation *s= new FileCalculation;
        QMap<QString,float> result=s->execute(dir2);

        QMapIterator<QString, float> iter(result);
        while (iter.hasNext()) {
            iter.next();
            std::cout<< CreateStringForElement(iter.key(), iter.value()).toStdString();
        }
        std::cout<<std::endl;
        delete s;
    }
    else{
        std::cout<<"Directory does't exist"<<std::endl;
    }
    std::cout<<"Stratege type:"<<std::endl;
    QDir dir3("..\\sppo_lab\\test");
    if (dir3.exists()){
        AbstractCalculation *s= new TypeCalculation;
        QMap<QString,float> result=s->execute(dir3);

        QMapIterator<QString, float> iter(result);
        while (iter.hasNext()) {
            iter.next();
            std::cout<< CreateStringForElement(iter.key(), iter.value()).toStdString();
        }
        std::cout<<std::endl;
        delete s;
    }
    else{
        std::cout<<"Directory does't exist"<<std::endl;
    }

    std::cout<<"\nEmpty directory"<<std::endl;
    std::cout<<"Stratege file:"<<std::endl;
    QDir dir4("..\\sppo_lab\\test\\empty");
    if (dir4.exists()){
        AbstractCalculation *s= new FileCalculation;
        QMap<QString,float> result=s->execute(dir4);

        QMapIterator<QString, float> iter(result);
        while (iter.hasNext()) {
            iter.next();
            std::cout<< CreateStringForElement(iter.key(), iter.value()).toStdString();
        }
        std::cout<<std::endl;
        delete s;
    }
    else{
        std::cout<<"Directory does't exist"<<std::endl;
    }
    std::cout<<"Stratege type:"<<std::endl;
    QDir dir5("..\\sppo_lab\\test\\empty");
    if (dir5.exists()){
        AbstractCalculation *s= new TypeCalculation;
        QMap<QString,float> result=s->execute(dir5);

        QMapIterator<QString, float> iter(result);
        while (iter.hasNext()) {
            iter.next();
            std::cout<< CreateStringForElement(iter.key(), iter.value()).toStdString();
        }
        std::cout<<std::endl;
        delete s;
    }
    else{
        std::cout<<"Directory does't exist"<<std::endl;
    }


    std::cout<<"\nDirectory with empty files"<<std::endl;
    std::cout<<"Stratege file:"<<std::endl;
    QDir dir6("..\\sppo_lab\\test\\zeroSize");
    if (dir6.exists()){
        AbstractCalculation *s= new FileCalculation;
        QMap<QString,float> result=s->execute(dir6);

        QMapIterator<QString, float> iter(result);
        while (iter.hasNext()) {
            iter.next();
            std::cout<< CreateStringForElement(iter.key(), iter.value()).toStdString();
        }
        std::cout<<std::endl;
        delete s;
    }
    else{
        std::cout<<"Directory does't exist"<<std::endl;
    }
    std::cout<<"Stratege type:"<<std::endl;
    QDir dir7("..\\sppo_lab\\test\\zeroSize");
    if (dir7.exists()){
        AbstractCalculation *s= new TypeCalculation;
        QMap<QString,float> result=s->execute(dir7);

        QMapIterator<QString, float> iter(result);
        while (iter.hasNext()) {
            iter.next();
            std::cout<< CreateStringForElement(iter.key(), iter.value()).toStdString();
        }
        std::cout<<std::endl;
        delete s;
    }
    else{
        std::cout<<"Directory does't exist"<<std::endl;
    }
    return a.exec();
}
