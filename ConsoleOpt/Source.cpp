#include "BasicDef.h"
#include "LinearOptimizator.h"
#include "LlnearOptimizeMethods.h"
#include "GradOptFR.h"

double f1(vector<double> x)
{
	return scalarProduct(x,x);
}
vector<double> gf1(vector<double> x)
{
	return 2 * x;
}
double f2(vector<double> x)
{
	return x[0]*x[0]*x[0]*x[0]+x[1];
}
vector<double> gf2(vector<double> x)
{
	vector<double> vr(x.size());
	vr[0] = 4 * x[0] * x[0] * x[0];
	vr[1] = 1;
	return vr;
}
bool closeCr(vector<double> x0, double f0, vector<double> x1, double f1)
{
	return (abs(f0 - f1) < 1e-9);
}

int main()
{
	LinearOptimizator w(linearSearch);
	GradOptFR pw(f2, gf2, closeCr, w);
	vector<double> testv(2);
	testv[0] = 12;
	testv[1] = 3;
	std::cout << pw.optimize(testv).second;
}