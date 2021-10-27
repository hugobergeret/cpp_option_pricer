#include "VanillaOption.h"
#include "../PayoffClasses/Payoff2.h"
#include "../../Random/Random1.h"
#include <cmath>

// Vanilla Option constructor
VanillaOption::VanillaOption(double Strike_, double Vol_, double r_, double Expiry_, const PayOff& ThePayOff_ ): Strike(Strike_), Vol(Vol_), r(r_), Expiry(Expiry_), ThePayOff(ThePayOff_){
}
// Method to retrieve expiry
double VanillaOption::getExpiry() const{
    return Expiry;
}
// Method to retrieve expected payoff
double VanillaOption::OptionPayoff(const double& Spot) const{
    double movedSpot = Spot*exp( (r - 0.5*Vol*Vol) * Expiry);
    double runningSum = 0;
    for (unsigned long i=0; i < 1000000; i++)
    {
        double OneGaussian = GetOneGaussianByBoxMuller();
        double ST = movedSpot*exp( Vol*OneGaussian*sqrt(Expiry));
        double PF = ThePayOff(ST);
        runningSum += PF;
    }
    return double (runningSum/1000000);
}
// Method to retrieve price of the option
double VanillaOption::GetPrice(const double& Spot) const{
    return double (exp(-r*Expiry)*VanillaOption::OptionPayoff(Spot));
}