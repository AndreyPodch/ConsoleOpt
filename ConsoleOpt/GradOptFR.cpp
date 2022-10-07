#include "GradOptFR.h"
std::pair<double, vector<double>> GradOptFR::optimize(vector<double> x0) const
{
	vector<double> p = -g(x0);
	vector<double> x1;
	do
	{
		double alpha = lopt(x0, p).second;
		x1 = x0 + alpha * p;
		vector<double> nextGrad = g(x1);
		double numer = 0, denom = 0;
		for (double el : nextGrad) numer += el * el;
		for (double el : p) denom = el * el;
		double beta = numer / denom;
		p = beta * p - g(x0);
	} while (!st(x0,f(x0),x1,f(x1)));
}
