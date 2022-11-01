#pragma once
#include "BasicDef.h"
#include "OptimizatorInterface.h"
class StochasticOptimizator: public OptimizatorInterface<vector<double>> 
{
private:
	double radiusOfCut;
	randomPointInCoveringArea randomPt;
	bool isNotCutted(std::list<vector<double>>& v, vector<double> x0) const;
public:
	StochasticOptimizator(smoothFunction<double, vector<double>> f_, stopCriteria<vector<double>> Stop_, randomPointInCoveringArea randomPt_,
		double radiusOfCut_=STANDART_RADIUS_OF_CUT, size_t maxIterations_ = MAX_OPTIMIZE_ITERATIONS) 
		: OptimizatorInterface(f_, Stop_, maxIterations_), randomPt(randomPt_), radiusOfCut(radiusOfCut_){};
	std::pair<vector<double>, double> optimize(vector<double> x0, inAreaCheck<vector<double>> inArea);
	void setFunction(smoothFunction<double, vector<double>> f_) { f = f_; };
};

