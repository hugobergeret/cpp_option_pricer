#ifndef PRICER2_H
#define PRICER2_H
#include "PayoffClasses/Payoff2.h"

double SimpleMonteCarlo2(const PayOff& thePayOff,
                        double T,
                        double S0,
                        double Sigma,
                        double r,
                        unsigned long NumberOfPaths);
#endif