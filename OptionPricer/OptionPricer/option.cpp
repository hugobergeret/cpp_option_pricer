#include "option.h"
#include "../Payoff/payoff.h"
#include "../Payoff/payoffs.h"
#include "../MonteCarlo/random.h"
#include "../NumericSchemes/numericSchemes.h"
#include <cmath>

// Vanilla Option constructor
Option::Option(double Strike_, double Vol_, double r_, double Expiry_, const Payoff& ThePayoff_ ): Strike(Strike_), Vol(Vol_), r(r_), Expiry(Expiry_), ThePayoff(ThePayoff_){
}

// Method to retrieve expected payoff by MC
double Option::MCOptionPayoff(const double& Spot, const long& NumSim) const{
    double movedSpot = Spot*exp( (r - 0.5*Vol*Vol) * Expiry);
    double runningSum = 0;
    for (unsigned long i=0; i < NumSim; i++)
    {
        double OneGaussian = GetGaussian();
        double ST = movedSpot*exp( Vol*OneGaussian*sqrt(Expiry));
        double PF = ThePayoff(ST);
        runningSum += PF;
    }
    return double (runningSum/NumSim);
}
// Method to retrieve price of the option by MC
double Option::MCGetPrice(const double& Spot, const long& NumSim) const{
    return double (exp(-r*Expiry)*Option::MCOptionPayoff(Spot, NumSim));
}
// Method to retrieve price of the option by CN
double Option::CNGetPrice(const double& Spot, const double& max_stock_price, const double& ds, const double& dt) const{
    return getSolution(Spot, Strike, r, Expiry, Vol, max_stock_price, ds, dt, ThePayoff);
}