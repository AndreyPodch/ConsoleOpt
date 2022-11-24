#include "AreasAndCovers.h"
std::mt19937 defaultGen(time(0));
std::uniform_real_distribution<> inSqrDist(-1, 1);

bool boxArea(vector<double> x, vector<double> sidesSizes)
{
	for (size_t i = 0; i < sidesSizes.size(); ++i)
	{
		if (abs(x[i]) > sidesSizes[i]) return false;
	}
	return true;
}
bool ballArea(vector<double> x, double radius) { return (innerProduct(x, x) < 1); }

vector<double> coverBallBoxAreaRG(vector<double> sidesSizes)
{
	vector<double> v(sidesSizes.size());
	for (size_t i = 0; i < sidesSizes.size(); ++i) 
	{
		v[i] = inSqrDist(defaultGen) * sidesSizes[i];
	}
	return v;
}