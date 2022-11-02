#include "GradOptFR.h"
std::pair<vector<double>, double> GradOptFR::optimize(vector<double> x0, inAreaCheck<vector<double>> inArea)
{
	vector<double> p = -fDiff(x0);
	vector<double> x1 = x0;
	size_t curIter = 0;
	do
	{
		x0 = x1;
		lo.DerivativeOptimizatorInterface::setFunctionAndDifferential(
			[x0, this, p](double x)->double {return f(x0 + x * p); },
			[x0, this, p](double x)->double {return scalarProduct(fDiff(x0 + x * p), -p); }
		);
		double alpha = lo.optimize(0,[x0, inArea, this, p](double x)->bool {return inArea(x0 + x * p); }).first;
		x1 = x0 + alpha * p;
		vector<double> nextGrad = fDiff(x1);
		double beta = scalarProduct(nextGrad, nextGrad) / scalarProduct(p, p);
		p = beta * p - fDiff(x0);
		std::cout << x0[0] << " " << x0[1] << std::endl;
		std::cout << fDiff(x0)[0] << " " << fDiff(x0)[1] << std::endl;
		std::cout << x1[0] << " " << x1[1] << std::endl;
		std::cout << fDiff(x1)[0] << " " << fDiff(x1)[1] << std::endl;
		if (curIter++ > maxIterations) break;
	} while (!Stop(x0,f(x0),x1,f(x1)));
	return std::make_pair(x1, f(x1));
}