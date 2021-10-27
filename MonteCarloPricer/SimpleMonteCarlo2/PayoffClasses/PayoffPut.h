#ifndef PAYOFFPUT_H
#define PAYOFFPUT_H

#include "Payoff2.h"

class PayoffPut : public PayOff
{
public:
    PayoffPut(double Strike );
    virtual double operator()(double Spot) const;
    // virtual ~PayOffCall(){}
private:
    double Strike;
};

#endif