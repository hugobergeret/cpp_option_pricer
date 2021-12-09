#ifndef OPTION_H
#define OPTION_H

#include "../Payoff/payoff.h"
#include "../Payoff/payoffs.h"

// Vanilla Option Class taking Strike, Vol, rf rate, expiry and payoff as argument
class Option{
    public:
        // Constructor of Vanilla Option class
        Option(double Strike, double Vol, double r, double Expiry, const Payoff& ThePayoff);
        // Method to retrieve Option expected payoff by MC
        double MCOptionPayoff(const double& Spot, const long& NumSim) const;
        // Method to retrieve Option price by MC
        double MCGetPrice(const double& Spot, const long& NumSim) const;
        // Method to retrieve Option price by Crank-Nicolson
        double CNGetPrice(const double& Spot, const double& max_stock_price, const double& ds, const double& dt) const;
    private:
        const Payoff& ThePayoff;
        double Strike;
        double Vol;
        double r;
        double Expiry;
};
#endif