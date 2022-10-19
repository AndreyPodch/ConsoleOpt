#include "BasicDef.h"
#include "LinearOptimizator.h"
#include "LlnearOptimizeMethods.h"
#include "StochasticOptimizator.h"
#include "GradOptFR.h"

std::mt19937 defaultGen(1512);
std::uniform_real_distribution<> inSqrDist(-1, 1);

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
	return pow(x[0]-sqrt(2),2)+pow(x[1]-sqrt(2),2);
}
vector<double> gf2(vector<double> x)
{
	vector<double> vr(x.size());
	vr[0] = 2 * x[0] - sqrt(2);
	vr[1] = 2 * x[1] - sqrt(2);
	return vr;
}
bool circleArea(vector<double> x)
{
	return (x[0] * x[0] + x[1] * x[1] < 1);
}
bool closeCr(vector<double> x0, double f0, vector<double> x1, double f1)
{
	return (abs(f0 - f1) < 1e-9);
}
vector<double> randomInSquare()
{
	vector<double> rv(2);
	rv[0] = inSqrDist(defaultGen);
	rv[1] = inSqrDist(defaultGen);
	return rv;
}

int main()
{
	LinearOptimizator w(linearSearch);
	GradOptFR pw(f2, gf2, closeCr, w, circleArea);
	vector<double> testv(2);
	testv[0] = 0;
	testv[1] = 0;
	std::cout << pw.optimize(testv).second<<std::endl<<"STOCHASTIC:"<<std::endl;
	StochasticOptimizator s(f2, circleArea, randomInSquare, 1e-5, 100);
	std::cout << s.optimize().second;
}