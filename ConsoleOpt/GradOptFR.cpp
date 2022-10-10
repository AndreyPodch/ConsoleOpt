#include "GradOptFR.h"
std::pair<double, vector<double>> GradOptFR::optimize(vector<double> x0) const
{
	vector<double> p = -gf(x0);
	vector<double> x1;
	do
	{
		double alpha = lo.optimize([x0, this, p](double x)->double {return f(x0 + x * p); },
									[x0, this, p](double x)->double {return scalarProduct(gf(x0 + x * p), p); });
	//	x1 = x0 + alpha * p;
		vector<double> nextGrad = gf(x1);
		double beta = scalarProduct(nextGrad, nextGrad) / scalarProduct(p, p);
		p = beta * p - gf(x0);
	} while (!st(x0,f(x0),x1,f(x1)));
}
