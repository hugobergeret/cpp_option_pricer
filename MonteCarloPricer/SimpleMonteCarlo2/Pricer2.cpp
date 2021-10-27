#include "../Random/Random1.h"
#include "Pricer2.h"
#include <cmath>

using namespace std;

// the basic math functions should be in
// namespace std but aren’t in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

// Used for Call and Put basic option 
double SimpleMonteCarlo2(const PayOff& thePayOff,
                        double T, 
                        double S0,
                        double Sigma, 
                        double r, 
                        unsigned long NumberOfPaths)
{
    double movedSpot = S0*exp( (r - 0.5*Sigma*Sigma) * T);
    double runningSum = 0;
    for (unsigned long i=0; i < NumberOfPaths; i++)
    {
        double OneGaussian = GetOneGaussianByBoxMuller();
        double ST = movedSpot*exp( Sigma*OneGaussian*sqrt(T));
        double CallPayoff = thePayOff(ST);
        runningSum += CallPayoff;
    }
    double avg = runningSum / NumberOfPaths;
    return avg * exp(-r*T);
}