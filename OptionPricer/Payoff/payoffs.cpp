#include "payoff.h"
#include "payoffs.h"

// Call payoff
PayoffCall::PayoffCall(double Strike_) : Strike(Strike_)
{ }

double PayoffCall::operator () (double Spot) const
{
    return (Spot - Strike) >0 ? (Spot - Strike) : 0;
}

// Put payoff
PayoffPut::PayoffPut(double Strike_) : Strike(Strike_)
{ }

double PayoffPut::operator () (double Spot) const
{
    return (Strike - Spot) >0 ? (Strike - Spot) : 0;
}