#include <iostream>
#include "Payoff/payoff.h"
#include "Payoff/payoffs.h"
#include "OptionPricer/option.h"
#include "NumericSchemes/numericSchemes.h"

using namespace std;

int main()
{
    // Parameters
    double Expiry;
    double Strike;
    double Strike1;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    // General parameters
    Expiry = 1;
    Strike = 10;
    Spot = 9.8;
    Vol = 0.1;
    r=0.01;
    // MC params
    NumberOfPaths = 100000;
    // Scheme params
    double max_stock_price = 14, dS = 0.01, dt= 0.01;

    
    // Creation of different option payoff types to test various classes
    PayoffCall callPayoff(Strike); PayoffPut putPayoff(Strike);
    // Creation of two options call and put to test
    Option callOption(Strike, Vol, r, Expiry, callPayoff);
    Option putOption(Strike, Vol, r, Expiry, putPayoff);

    cout << "################# PRICING WITH MONTE CARLO ############### \n";
    cout << "the call option price is: " << callOption.MCGetPrice(Spot, NumberOfPaths) << "\n";
    cout << "the put option price is: " << putOption.MCGetPrice(Spot, NumberOfPaths) << "\n";
    
    
    double price = putOption.CNGetPrice(Spot, max_stock_price, dS, dt);
    
    cout << "################# PRICING WITH NUMERIC SCHEMES ############# \n";
    cout << "the put option price with numeric scheme is: " << price << "\n";

    price = callOption.CNGetPrice(Spot, max_stock_price, dS, dt);
    cout << "the call option price with numeric scheme is: " << price << "\n";

    return 0;
}