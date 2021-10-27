#include "PayoffPut.h"

PayoffPut::PayoffPut(double Strike_) : Strike(Strike_)
{ }

double PayoffPut::operator () (double Spot) const
{
    return (Strike - Spot) >0 ? (Strike - Spot) : 0;
}