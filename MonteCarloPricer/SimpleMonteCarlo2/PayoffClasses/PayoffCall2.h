#ifndef PAYOFFCALL2_H
#define PAYOFFCALL2_H

#include "Payoff2.h"

class PayOffCall : public PayOff
{
public:
    PayOffCall(double Strike );
    virtual double operator()(double Spot) const;
    // virtual ~PayOffCall(){}
private:
    double Strike;
};

#endif