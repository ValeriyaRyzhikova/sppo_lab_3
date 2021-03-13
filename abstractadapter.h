#ifndef ABSTRACTADAPTER_H
#define ABSTRACTADAPTER_H
#include<QWidget>
#include<QMap>
#include<QString>


class AbstractAdapter: public QObject
{
    Q_OBJECT
protected:
    QWidget *widget_;
    QString transleteFloatToQString(float);
public:
    AbstractAdapter();
    virtual ~AbstractAdapter();
    QWidget *giveWidget();
public slots:
    virtual void updateAdapter(QMap<QString,float>)=0;\
};

#endif // ABSTRACTADAPTER_H
