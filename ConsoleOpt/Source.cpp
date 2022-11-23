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
	smoothFunction<double, vector<double>> f;
	smoothFunction<vector<double>, vector<double>> gf;
	linearOptimizeMethod lom;
	stopCriteria<vector<double>> stopCr;
	inAreaCheck<vector<double>> inArea;
	randomPointInCoveringArea coverArea;
	LinearOptimizeParameters lp(0,0,0);
	size_t maxIterations;
	size_t fdim;
	try
	{
		std::cout << "Select a function and enter its number:" << std::endl;
		std::cout << "1) (x-sqrt(2))^2+(y-sqrt(2))^2" << std::endl;
		std::cout << "2) (1-x)^2+100(y-x^2)^2" << std::endl;
		std::cout << "3) x^4+(y-0.5)^2+z^2*w^2" << std::endl;
		std::cout << "4) x^2+y^2+z^2" << std::endl;
		int a;
		std::cin >> a;
		switch (a)
		{
		case 1:
			f = f1;
			gf = gf1;
			fdim = 2;
			break;
		case 2:
			f = f2;
			gf = gf2;
			fdim = 2;
			break;
		case 3:
			f = f3;
			gf = gf3;
			fdim = 4;
			break;
		case 4:
			f = f4;
			gf = gf4;
			fdim = 3;
			break;
		default:
			throw("Wrong number");
		}
	}
	catch (...)
	{
		std::cout << "Wrong function number" << std::endl;
		return -1;
	}
	try
	{
		std::cout << "Select an area and enter its number:" << std::endl;
		std::cout << "1) Symmetrical box area" << std::endl;
		std::cout << "2) Ball area" << std::endl;
		int a;
		std::cin >> a;
		vector<double> sidesSizes(fdim);
		switch (a)
		{
		case 1:
			std::cout << "Please enter " << fdim << " numbers -- sides of box:" << std::endl;
			for (size_t i = 0; i < fdim; ++i)
			{
				std::cin >> sidesSizes[i];
			}
			inArea = [sidesSizes](vector<double> x)->bool {return boxArea(x, sidesSizes); };
			coverArea = [sidesSizes]()->vector<double> {return coverBallBoxAreaRG(sidesSizes); };
			break;
		case 2:
			std::cout << "Please enter radius of ball: " << std::endl;
			double r;
			std::cin >> r;
			for (double el : sidesSizes) el = r;
			inArea = [r](vector<double> x)->bool {return ballArea(x, r); };
			coverArea = [sidesSizes]()->vector<double> {return coverBallBoxAreaRG(sidesSizes); };
			break;
		default:
			throw("Wrong number");
		}
	}
	catch (...)
	{
		std::cout << "Wrong function number" << std::endl;
		return -1;
	}
	try
	{
		std::cout << "Select a linear optimization method and enter its number:" << std::endl;
		std::cout << "1) Linear search" << std::endl;
		std::cout << "2) Ternary search" << std::endl;
		std::cout << "3) Golden section search" << std::endl;
		std::cout << "4) Binary search" << std::endl;
		int a;
		std::cin >> a;
		vector<double> sidesSizes(fdim);
		switch (a)
		{
		case 1:
			lom = linearSearch;
			break;
		case 2:
			lom = ternarySearch;
			break;
		case 3:
			lom = goldenSectionSearch;
			break;
		case 4:
			lom = binarySearch;
			break;
		default:
			throw("Wrong number");
		}

	}
	catch (...)
	{
		std::cout << "Wrong function number" << std::endl;
		return -1;
	}
	try
	{
		std::cout << "Select a stop criteria and enter its number:" << std::endl;
		std::cout << "1) Absolute value difference" << std::endl;
		std::cout << "2) Absolute point difference" << std::endl;
		std::cout << "3) Relative value difference" << std::endl;
		std::cout << "4) Relative point difference" << std::endl;
		int a;
		std::cin >> a;
		vector<double> sidesSizes(fdim);
		switch (a)
		{
		case 1:
			stopCr = absValueDiffStop;
			break;
		case 2:
			stopCr = absCoordDiffStop;
			break;
		case 3:
			stopCr = relValueDiffStop;
			break;
		case 4:
			stopCr = relCoordDiffStop;
			break;
		default:
			throw("Wrong number");
		}
	}
	catch (...)
	{
		std::cout << "Wrong function number" << std::endl;
		return -1;
	}
	try
	{
		std::cout << "Enter linear search parameters: searchPrecision, indent and searchStep: " << std::endl;
		double a, b, c;
		std::cin >> a >> b >> c;
		lp=LinearOptimizeParameters(a, b, c);
		std::cout << "Enter maximum of iterations: " << std::endl;
		std::cin >> maxIterations;
	}
	catch (...)
	{
		std::cout << "Wrong enter parameters" << std::endl;
		return -1;
	}
	LinearOptimizator lo(nullptr, nullptr, lom, lp, maxIterations);
	GradOptFR frOpt(f, gf, stopCr, lo, maxIterations);
	StochasticOptimizator stOpt(f, stopCr, coverArea);
	while (true)
	{
		std::cout << "Enter " << fdim << " coordinates of start point:" << std::endl;
		vector<double> x0(fdim);
		for (double el : x0) std::cin >> el;
		std::cout << "Fisher-Rieves method:" << std::endl;
		std::cout << "Optimal value: " << frOpt.optimize(x0, inArea).second << std::endl;
		std::cout << "Number of iterations: " << frOpt.getNumberOfIterations() << std::endl;
		std::cout << "Stochastic method:" << std::endl;
		std::cout << "Optimal value: " << stOpt.optimize(x0, inArea).second << std::endl;
		std::cout << "Number of iterations: " << stOpt.getNumberOfIterations() << std::endl;
		while (true)
		{
			std::cout << "Do you want to repeat at another start point? Y/N";
			char ch;
			std::cin >> ch;
			if ((ch == 'y') || (ch == 'Y')) break;
			if ((ch == 'n') || (ch == 'N')) return 0;
		}
	}
}