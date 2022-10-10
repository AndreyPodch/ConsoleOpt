#pragma once
#include "BasicDef.h"
#include "LinearOptimizator.h"
class GradOptFR
{
private:
	smoothFunction f;
	gradientFunction gf;
	stopCriteria st;
	LinearOptimizator lo;
public:
	GradOptFR(smoothFunction f_, gradientFunction g_, stopCriteria st_, LinearOptimizator lo_) :  f(f_), gf(g_), st(st), lo(lo_) {};
	~GradOptFR() {};
	std::pair<double, vector<double> > optimize(vector<double> x0) const;
	void changeStopCriteria(stopCriteria st_) { st = st_; };
	void changeFunction(smoothFunction f_, gradientFunction g_) { f = f_; gf = g_; };
	void changeLinearOptimizator(linearOptimizeMethod lo_) { lo = lo_; };
};

