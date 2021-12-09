#ifndef NUMERIC_SCHEMES_H
#define NUMERIC_SCHEMES_H

double max(double a, double b);
double getSolution(double initial_stock_price, double strike_price, double rate, double time_of_maturity, double volatility, double max_stock_price, double dS, double dt, const Payoff& ThePayoff);


#endif