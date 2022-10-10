#include "BasicDef.h"
#include "LinearOptimizator.h"
#include "LlnearOptimizeMethods.h"
#include "GradOptFR.h"

double f1(double x)
{
	return x *x - 0.5;
}
double fexp(vector<double> x)
{
	return scalarProduct(x,x);
}
vector<double> gfexp(vector<double> x)
{
	return 2 * x;
}
bool closeCr(vector<double> x0, double f0, vector<double> x1, double f1)
{
	return (abs(f0 - f1) < 1e-4);
}

int main()
{
	LinearOptimizator w(linearSearch);
	GradOptFR pw(fexp, gfexp, closeCr, w);
	vector<double> testv(2);
	testv[0] = 125;
	testv[1] = 33;
	std::cout << pw.optimize(testv).second;
}