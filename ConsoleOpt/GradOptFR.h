#pragma once
#include "BasicDef.h"
#include "LinearOptimizator.h"
class GradOptFR
{
private:
	smoothFunction f;
	LinearOptimizator lo;
	inAreaCheck inArea;
	gradientFunction gf;
	stopCriteria st;
public:
	GradOptFR(smoothFunction f_, gradientFunction g_, stopCriteria st_, 
		linearOptimizeMethod lom_, inAreaCheck inArea_, double step_ = LINEAR_OPTIMIZE_SPLIT_SIZE, double indent_ = LINEAR_OPTIMIZE_INDENT
		) :  f(f_), gf(g_), st(st_), inArea(inArea_), lo(lom_, step_, indent_) {};
	GradOptFR(smoothFunction f_, gradientFunction g_, stopCriteria st_,
		LinearOptimizator lo_, inAreaCheck inArea_) : f(f_), gf(g_), st(st_), inArea(inArea_), lo(lo_) {};
	~GradOptFR() {};
	std::pair<vector<double>, double> optimize(vector<double> x0) const;
	void changeStopCriteria(stopCriteria st_) { st = st_; };
	void changeFunction(smoothFunction f_, gradientFunction g_) { f = f_; gf = g_; };
	void changeArea(inAreaCheck inArea_) { inArea = inArea_; };
};

