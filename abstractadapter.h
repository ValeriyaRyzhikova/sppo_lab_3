#ifndef ABSTRACTADAPTER_H
#define ABSTRACTADAPTER_H
#include<QWidget>
#include<QMap>
#include<QString>


class AbstractAdapter: public QObject
{
    Q_OBJECT
protected:
    QString transleteFloatToQString(float);
public:
    AbstractAdapter();
    virtual ~AbstractAdapter();
public slots:
    virtual void updateAdapter(QMap<QString,float>)=0;
signals:
    void sentMainwindow(QWidget *);
};

#endif // ABSTRACTADAPTER_H
