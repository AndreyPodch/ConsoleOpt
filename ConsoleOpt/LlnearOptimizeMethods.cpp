#include "LlnearOptimizeMethods.h"
double linearSearch(double a, double b, std::function <double(double)> f, std::function <double(double)> df)
{
	return std::min(f(a), f(b));
}
