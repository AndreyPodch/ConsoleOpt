#include "BasicDef.h"
#include "LinearOptimizator.h"
#include "LlnearOptimizeMethods.h"
#include "StochasticOptimizator.h"
#include "StopCriterias.h"
#include "ExampleFunctions.h"
#include "AreasAndCovers.h"
#include "StopCriterias.h"
#include "GradOptFR.h"

//std::mt19937 defaultGen(time(0));
//std::uniform_real_distribution<> inSqrDist(-1, 1);
//
//double f1(vector<double> x)
//{
//	return scalarProduct(x,x);
//}
//vector<double> gf1(vector<double> x)
//{
//	return 2 * x;
//}
//double f2(vector<double> x)
//{
//	return pow(x[0]-sqrt(2),2)+pow(x[1]-sqrt(2),2);
//}
//vector<double> gf2(vector<double> x)
//{
//	vector<double> vr(x.size());
//	vr[0] = 2 * x[0] - sqrt(2);
//	vr[1] = 2 * x[1] - sqrt(2);
//	return vr;
//}
//bool circleArea(vector<double> x)
//{
//	return (x[0] * x[0] + x[1] * x[1] < 1);
//}
//bool closeCr(vector<double> x0, double f0, vector<double> x1, double f1)
//{
//	return (abs(f0 - f1) < 1e-9);
//}
//vector<double> randomInSquare()
//{
//	vector<double> rv(2);
//	rv[0] = inSqrDist(defaultGen);
//	rv[1] = inSqrDist(defaultGen);
//	return rv;
//}

int main()
{
	LinearOptimizator w(nullptr, nullptr, 1e-4, ternarySearch);
	GradOptFR pw(f3, gf3, absValueDiffStop, w);
	vector<double> testv(3);
	testv[0] = -0.8;
	testv[1] = 0.9;
	testv[2] = 0.9;
	std::cout << pw.optimize(testv, circleArea).second<<std::endl<<"STOCHASTIC:"<<std::endl;
	StochasticOptimizator s(f3, absValueDiffStop, coverSphereAreaRG, 1e-5, 1000);
//	vector<double> xt = s.optimize(testv, circleArea).first;
//	print(xt);
	std::cout << s.optimize(testv, circleArea).second;
}