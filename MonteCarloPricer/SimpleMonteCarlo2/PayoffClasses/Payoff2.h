#ifndef PAYOFF2_H
#define PAYOFF2_H
class PayOff
{
public:
    PayOff(){};
    virtual double operator()(double Spot) const=0;
private:
};
#endif

