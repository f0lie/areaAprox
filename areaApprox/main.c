#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

double func(double);
double LRAM(double(*funcPtr)(double), double a, double b, int n);
double RRAM(double(*funcPtr)(double), double a, double b, int n);
double simpson(double(*funcPtr)(double), double a, double b);
double simpsonStrips(double(*funcPtr)(double), double a, double b, int strips);

int main(void)
{
	double(*funcPtr)(double) = func;

	double a = 0,
		b = 10,
		lram = LRAM(funcPtr, a, b, 10),
		rram = RRAM(funcPtr, a, b, 10),
		sim = simpson(funcPtr, a, b),
		simSum = simpsonStrips(funcPtr, a, b, 10);

	printf("LRAM = %lf\nRRAM = %lf\nsim = %lf\nsimSum = %lf",
		lram, rram, sim, simSum);

	getchar();
	return 0;
}

//define a math function here
double func(double x)
{
	return pow(x, 2.0);
}

//uses left rectangles to estimate the area under a curve from [a,b]
//n is the number of rectangles to use
double LRAM(double(*funcPtr)(double), double a, double b, int n)
{
	double width = (b - a) / n,
		height = 0;

	for (int i = 0; i < n; i++)
	{
		height += (*funcPtr)(a + i * width);
	}

	return width*height;
}

//uses right rectangles to estimate the area under a curve from [a,b]
//n is the number of rectangles to use
double RRAM(double(*funcPtr)(double), double a, double b, int n)
{
	double width = (b - a) / n,
		height = 0;

	for (int i = 1; i <= n; i++)
	{
		height += (*funcPtr)(a + i * width);
	}

	return width*height;
}

//uses simpson rule to estimate the area under the curve from [a,b]
double simpson(double(*funcPtr)(double), double a, double b)
{
	double float1 = (*funcPtr)(a)+4 * (*funcPtr)((a + b) / 2) + (*funcPtr)(b);
	double float2 = (b - a) / 6;
	return float1 * float2;
}

//uses many simpson rules to estimate the area under the curve from [a,b]
//strips is the number of simpson rules to use
double simpsonStrips(double(*funcPtr)(double), double a, double b, int strips)
{
	double simpSum = 0,
		width = (b - a) / strips;

	for (int i = 0; i < strips; i++)
	{
		simpSum += simpson(funcPtr, a + i * width, a + (i + 1) * width);
	}

	return simpSum;
}