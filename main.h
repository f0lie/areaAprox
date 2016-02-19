#ifndef MAIN_H_HEADER
#define MAIN_H_HEADER

double func(double);
double LRAM(double(*funcPtr)(double), double a, double b, int n);
double RRAM(double(*funcPtr)(double), double a, double b, int n);
double simpson(double(*funcPtr)(double), double a, double b);
double simpsonStrips(double(*funcPtr)(double), double a, double b, int strips);

#endif /* MAIN_H_HEADER */