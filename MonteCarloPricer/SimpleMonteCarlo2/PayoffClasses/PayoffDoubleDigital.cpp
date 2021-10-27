#include "PayoffDoubleDigital.h"

PayoffDoubleDigital::PayoffDoubleDigital(double Strike1_, double Strike2_): Strike1(Strike1_), Strike2(Strike2_)
{
    if (Strike1 > Strike2) {
    double tmp = Strike2;
    Strike2 = Strike1;
    Strike1 = tmp;
    }
}

double PayoffDoubleDigital::operator () (double Spot) const
{
    return (Spot> Strike1) && (Spot<Strike2) ? 1: 0;
}