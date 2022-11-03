#include "AreasAndCovers.h"
std::mt19937 defaultGen(time(0));
std::uniform_real_distribution<> inSqrDist(-1, 1);

bool boxArea(vector<double> x)
{
	for (double el : x) if (abs(el) > 1) return false;
	else return true;
}
bool circleArea(vector<double> x) { return (scalarProduct(x, x) < 1); }

vector<double> coverCircleAreaRG()
{
	vector<double> v(2);
	v[0] = inSqrDist(defaultGen);
	v[1] = inSqrDist(defaultGen);
	return v;
}
vector<double> coverSphereAreaRG()
{
	vector<double> v(3);
	v[0] = inSqrDist(defaultGen);
	v[1] = inSqrDist(defaultGen);
	v[2] = inSqrDist(defaultGen);
	return v;
}