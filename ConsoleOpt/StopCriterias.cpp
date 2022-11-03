#include "StopCriterias.h"

bool absValueDiffStop(vector<double> x0, double f0, vector<double> x1, double f1) { return abs(f0 - f1) < STANDARD_STOP_EPSILON; }
bool absCoordDiffStop(vector<double> x0, double f0, vector<double> x1, double f1)
{
	vector<double> v = x0 - x1;
	return scalarProduct(v, v) < pow(STANDARD_STOP_EPSILON, 2);
}
bool relValueDiffStop(vector<double> x0, double f0, vector<double> x1, double f1) { return abs((f0 - f1) / f1) < STANDARD_STOP_EPSILON; }
bool relCoordDiffStop(vector<double> x0, double f0, vector<double> x1, double f1)
{
	vector<double> v = x0 - x1;
	return scalarProduct(v, v) / scalarProduct(x1, x1) < pow(STANDARD_STOP_EPSILON, 2);
}