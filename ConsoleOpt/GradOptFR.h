#pragma once
#include "BasicDef.h"
class GradOptFR
{
private:
	smoothFunction f;
	gradientFunction g;
	stopCriteria st;
	lineOptimize lopt;
public:
	GradOptFR(smoothFunction f_, gradientFunction g_, stopCriteria st_, lineOptimize lopt_) :  f(f_), g(g_), st(st), lopt(lopt_) {};
	~GradOptFR() {};
	std::pair<double, vector<double> > optimize(vector<double> x0) const;
	void changeStopCriteria(stopCriteria st_) { st = st_; };
	void changeFunction(smoothFunction f_, gradientFunction g_) { f = f_; g = g_; };
	void changeLineOptimize(lineOptimize lopt_) { lopt = lopt_; };
};

