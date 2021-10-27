#include "PayoffCall2.h"

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{ }

double PayOffCall::operator () (double Spot) const
{
    return (Spot - Strike) >0 ? (Spot - Strike) : 0;
}