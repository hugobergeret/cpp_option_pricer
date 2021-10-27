#include "PayoffStrangle.h"
#include "PayoffCall2.h"
#include "PayoffPut.h"

PayoffStrangle::PayoffStrangle(double Strike1_, double Strike2_): Strike1(Strike1_), Strike2(Strike2_)
{
    if (Strike1 > Strike2) {
    double tmp = Strike2;
    Strike2 = Strike1;
    Strike1 = tmp;
    }
}

double PayoffStrangle::operator () (double Spot) const
{
    PayOffCall CallOption(Strike1);
    PayoffPut PutOption(Strike2);
    return CallOption(Spot) + PutOption(Spot);
}