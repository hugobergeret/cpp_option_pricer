#ifndef VANILLAOPTION_H
#define VANILLAOPTION_H

#include "../PayoffClasses/Payoff2.h"

// Vanilla Option Class taking Strike, Vol, rf rate, expiry and payoff as argument
class VanillaOption{
    public:
        // Constructor of Vanilla Option class
        VanillaOption(double Strike, double Vol, double r, double Expiry, const PayOff& ThePayOff);
        // Method to retrieve Option expected payoff
        double OptionPayoff(const double& Spot) const;
        // Method to retrieve Option price
        double GetPrice(const double& Spot) const;
        // Method to retrieve Option Expiry
        double getExpiry() const;
    private:
        const PayOff& ThePayOff;
        double Strike;
        double Vol;
        double r;
        double Expiry;
};
#endif