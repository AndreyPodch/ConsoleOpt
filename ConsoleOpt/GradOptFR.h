#pragma once
#include "BasicDef.h"
class GradOptFR
{
private:
	smoothFunction f;
	gradientFunction gf;
	stopCriteria st;
	linearOptimizeMethod lopt;
public:
	GradOptFR(smoothFunction f_, gradientFunction g_, stopCriteria st_, linearOptimizeMethod lopt_) :  f(f_), gf(g_), st(st), lopt(lopt_) {};
	~GradOptFR() {};
	std::pair<double, vector<double> > optimize(vector<double> x0) const;
	void changeStopCriteria(stopCriteria st_) { st = st_; };
	void changeFunction(smoothFunction f_, gradientFunction g_) { f = f_; gf = g_; };
	void changelinearOptimizeMethod(linearOptimizeMethod lopt_) { lopt = lopt_; };
};

