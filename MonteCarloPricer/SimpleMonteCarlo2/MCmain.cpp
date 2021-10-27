#include <iostream>
#include "Pricer2.h"
#include "PayoffClasses/Payoff2.h"
#include "PayoffClasses/PayoffCall2.h"
#include "PayoffClasses/PayoffPut.h"
#include "PayoffClasses/PayoffStrangle.h"
#include "PayoffClasses/PayoffDoubleDigital.h"
#include "VanillaOptionClass/VanillaOption.h"
#include "VanillaOptionClass/VanillaOptionPortfolio.h"

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

    Expiry = 1;
    Strike = 100;
    Strike1 = 110;
    Spot = 98;
    Vol = 0.1;
    r=0.01;
    NumberOfPaths = 100000;
    // Creation of different option types to test various classes
    PayOffCall callPayOff(Strike); PayoffPut putPayoff(Strike);
    PayoffStrangle StranglePayoff(Strike, Strike1); PayoffDoubleDigital DoubleDigitalPayoff(Strike, Strike1);
    // Calculating prices given the Payoff using the old SimpleMonteCarlo2 function
    double resultCall = SimpleMonteCarlo2(callPayOff,
                                            Expiry,
                                            Spot,
                                            Vol,
                                            r,
                                            NumberOfPaths);
    double resultPut = SimpleMonteCarlo2(putPayoff,
                                        Expiry,
                                        Spot,
                                        Vol,
                                        r,
                                        NumberOfPaths);
    double resultStrangle = SimpleMonteCarlo2(StranglePayoff,
                                        Expiry,
                                        Spot,
                                        Vol,
                                        r,
                                        NumberOfPaths);
    double resultDigital = SimpleMonteCarlo2(DoubleDigitalPayoff,
                                        Expiry,
                                        Spot,
                                        Vol,
                                        r,
                                        NumberOfPaths);
    cout << "############################ TEST OF VARIOUS OPTION PRICES USING PAYOFF CLASSES ########################## \n\n";
    cout << "The prices is " 
         << resultCall << " for the call option\n";
    cout << "The price is "
        << resultPut << " for the put option\n";
    cout << "The price is "
        << resultStrangle << " for the strangle strategy\n";
    cout << "The price is "
        << resultDigital << " for the digital option\n\n";
    
    // Test using Vanilla Option Class
    VanillaOption VanillaCall(Strike, Vol, r, Expiry, callPayOff);
    VanillaOption VanillaPut(Strike, Vol, r, Expiry, putPayoff);

    cout << "########################### TEST OF VANILLA OPTION CLASS ########################### \n\n";
    cout << "The expiry of the call option is " << VanillaCall.getExpiry() << " year" << "\n";
    cout << "The expiry of the put option is " << VanillaPut.getExpiry() << " year" << "\n";
    cout << "The vanilla call option payoff is " << VanillaCall.OptionPayoff(Spot) << "\n";
    cout << "The vanilla put option payoff is " << VanillaPut.OptionPayoff(Spot) << "\n";
    cout << "The vanilla call option price is " << VanillaCall.GetPrice(Spot) << "\n";
    cout << "The vanilla put option price is " << VanillaPut.GetPrice(Spot) << "\n\n";

    // Test of Vanilla Option Portfolio class
    std::vector<VanillaOption> PF = {VanillaCall, VanillaPut};  
    VanillaOptionPortfolio VanillaPTF(PF);
    cout << "########################### TEST OF VANILLA OPTION PORTFOLIO CLASS ########################### \n\n";
    cout << "The Payoff of the whole portfolio is " << VanillaPTF.getTotalPayoff(Spot) << "\n";
    cout << "The Price of the whole portfolio is " << VanillaPTF.getTotalPrice(Spot) << "\n";

    return 0;
}