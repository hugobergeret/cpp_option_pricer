#ifndef PAYOFFSTRANGLE_H
#define PAYOFFSTRANGLE_H

#include "Payoff2.h"

class PayoffStrangle : public PayOff
{
public:
    PayoffStrangle(double Strike1, double Strike2);
    virtual double operator()(double Spot) const;
    // virtual ~PayOffCall(){}
private:
    double Strike1;
    double Strike2;
};


#endif