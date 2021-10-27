
#include <iostream>
#include <vector>
#include "VanillaOption.h"
#include "VanillaOptionPortfolio.h"

// Vanilla Option Portfolio Constructor
VanillaOptionPortfolio::VanillaOptionPortfolio(const std::vector <VanillaOption>& OptionsVector_ ): OptionsVector(OptionsVector_){
}
// Vanilla Option Portfolio method to retrieve total Payoff
double VanillaOptionPortfolio::getTotalPayoff(const double& Spot) const{
    double payoff=0;
    for(auto& i : OptionsVector){
        payoff+=i.OptionPayoff(Spot);
    }
    return payoff;
}
// Vanilla Option Portfolio method to retrieve total price
double VanillaOptionPortfolio::getTotalPrice(const double& Spot) const{
    double price=0;
    for(auto& i : OptionsVector){
        price+=i.GetPrice(Spot);
    }
    return price;
}