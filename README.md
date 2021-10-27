# cpp_option_pricer
Option pricer in C++ for european options

This project is about a C++ European Option Pricer, it was a University exercise.

It is designed to price european call, put, strangle and digital option.
Coding has emphasized on object oriented programing with classes corresponding to each payoff type inheriting from a theoretical payoff class.
Vanilla option class has been created to gather all information about the option and takes payoff as argument.
Vanilla Option Portfolio class is designed to gather several Vanilla Options and has some methods to calculate the price of the portfolio.
