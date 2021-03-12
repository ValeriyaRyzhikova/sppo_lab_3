#include "abstractadapter.h"

AbstractAdapter::AbstractAdapter(){}
AbstractAdapter::~AbstractAdapter(){}

QString AbstractAdapter::transleteFloatToQString(float size)
{
    size*=100;
    if (size < 0.01 && size!=0)
        return"<0.01%";
    return QString::number(size, 'f', 2)+"%";
}
