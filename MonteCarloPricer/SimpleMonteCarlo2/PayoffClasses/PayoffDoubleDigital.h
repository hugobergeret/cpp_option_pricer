#ifndef PAYOFFDOUBLEDIGITAL_H
#define PAYOFFDOUBLEDIGITAL_H

#include "Payoff2.h"

class PayoffDoubleDigital : public PayOff
{
public:
    PayoffDoubleDigital(double Strike1, double Strike2);
    virtual double operator()(double Spot) const;
private:
    double Strike1;
    double Strike2;
};


#endif