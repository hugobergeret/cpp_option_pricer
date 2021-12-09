#ifndef PAYOFF_H
#define PAYOFF_H

enum class Type {Base, Call, Put};


class Payoff
{
public:
    Payoff(){};
    virtual double operator()(double Spot) const=0;
    virtual Type type() const {
        return Type::Base;
    }
private:
};

#endif