#include "LlnearOptimizeMethods.h"
std::pair<double, double> linearSearch(double a, double b, std::function <double(double)> f, std::function <double(double)> df)
{
	double lv = f(a), rv = f(b);
	if (lv < rv) return std::make_pair(a, lv);
	else return std::make_pair(b, rv);
}
