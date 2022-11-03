#include "ExampleFunctions.h"
double f1(vector<double> x) { return scalarProduct(x, x); }

vector<double> gf1(vector<double> x) { return 2 * x; }

double f2(vector<double> x)
{
	return pow(x[0] - sqrt(2), 2) + pow(x[1] - sqrt(2), 2);
}
vector<double> gf2(vector<double> x)
{
	vector<double> vr(x.size());
	vr[0] = 2 * x[0] - sqrt(2);
	vr[1] = 2 * x[1] - sqrt(2);
	return vr;
}

double f3(vector<double> x)
{
	return x[0] + x[1] * x[0] - x[2];
}
vector<double> gf3(vector<double> x)
{
	vector<double> vr(x.size());
	vr[0] = 1 + x[1];
	vr[1] = x[0];
	vr[2] = -1;
	return vr;
}