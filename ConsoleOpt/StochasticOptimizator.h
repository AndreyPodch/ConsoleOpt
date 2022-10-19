#pragma once
#include "BasicDef.h"
class StochasticOptimizator
{
private:
	smoothFunction f;
	size_t maxIteration;
	double radiusOfCut;
	randomPointInCoverArea randomPt;
	inAreaCheck inArea;
	bool isNotCutted(std::list<vector<double>>& v, vector<double> x0) const;
public:
	StochasticOptimizator(smoothFunction f_, inAreaCheck inArea_, randomPointInCoverArea randomPt_,
		double radiusOfCut_=STANDART_RADIUS_OF_CUT, size_t maxIteration_ = MAX_OPTIMIZE_ITERATION) 
		: f(f_), inArea(inArea_), randomPt(randomPt_), radiusOfCut(radiusOfCut_), maxIteration(maxIteration_) {};
	std::pair<vector<double>, double> optimize() const;
};

