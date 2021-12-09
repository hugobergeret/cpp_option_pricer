#ifndef PAYOFFS_H
#define PAYOFFS_H

#include "payoff.h"

// Call payoff
class PayoffCall : public Payoff
{
public:
    PayoffCall(double Strike );
    virtual double operator()(double Spot) const;
    virtual Type type() const {
        return Type::Call;
    }
private:
    double Strike;
};

// Put payoff
class PayoffPut : public Payoff
{
public:
    PayoffPut(double Strike );
    virtual double operator()(double Spot) const;
    virtual Type type() const {
        return Type::Put;
    }
private:
    double Strike;
};

#endif