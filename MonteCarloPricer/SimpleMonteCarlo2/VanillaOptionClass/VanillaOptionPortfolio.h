#ifndef VANILLAOPTIONPTF_H
#define VANILLAOPTIONPTF_H

#include <iostream>
#include <vector>
#include "VanillaOption.h"

// Vanilla Option Portfolio Class
class VanillaOptionPortfolio{
    public:
        // Constructor taking a vector of Vanilla Options as arguments
        VanillaOptionPortfolio(const std::vector <VanillaOption>& OptionsVector);
        // Vanilla Option Portfolio method to get global payoff of the portfolio
        double getTotalPayoff(const double& Spot) const;
        // Vanilla Option Portfolio method to get global price of the portfolio
        double getTotalPrice(const double& Spot) const;
    private:
        const std::vector <VanillaOption>& OptionsVector;
};


#endif