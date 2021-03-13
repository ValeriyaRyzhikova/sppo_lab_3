#include "abstractcalculation.h"

AbstractCalculation::AbstractCalculation(){}

void AbstractCalculation::bringUpSentAdapter()
{
    emit sentAdapter(previousCalculation_);
}
