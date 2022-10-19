#include "GradOptFR.h"
std::pair<vector<double>, double> GradOptFR::optimize(vector<double> x0) const
{
	vector<double> p = -gf(x0);
	vector<double> x1 = x0;
	do
	{
		x0 = x1;
		double alpha = lo.optimize([x0, this, p](double x)->double {return f(x0 + x * p); },
									[x0, this, p](double x)->double {return scalarProduct(gf(x0 + x * p), p); },
									[x0, this, p](double x)->bool {return inArea(x0 + x * p); }).first;
		x1 = x0 + alpha * p;
		vector<double> nextGrad = gf(x1);
		double beta = scalarProduct(nextGrad, nextGrad) / scalarProduct(p, p);
		p = beta * p - gf(x0);
		std::cout << x0[0] << " " << x0[1] << std::endl;
		std::cout << gf(x0)[0] << " " << gf(x0)[1] << std::endl;
		std::cout << x1[0] << " " << x1[1] << std::endl;
		std::cout << gf(x1)[0] << " " << gf(x1)[1] << std::endl;
	} while (!st(x0,f(x0),x1,f(x1)));
	return std::make_pair(x1, f(x1));
}