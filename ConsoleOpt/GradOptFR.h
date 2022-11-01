#pragma once
#include "BasicDef.h"
#include "DerivativeOptimizatorInterface.h"
#include "LinearOptimizator.h"
class GradOptFR : public DerivativeOptimizatorInterface<vector<double>>
{
private:
	LinearOptimizator lo;
public:
	GradOptFR(smoothFunction<double, vector<double>> f_, smoothFunction<vector<double>, vector<double>> gradf_, stopCriteria<vector<double>> Stop_,
		linearOptimizeMethod lom_, stopCriteria<double> linearStop_, double step_ = LINEAR_OPTIMIZE_SPLIT_SIZE, double indent_ = LINEAR_OPTIMIZE_INDENT,
		size_t maxIterations_ = MAX_OPTIMIZE_ITERATIONS
		) : DerivativeOptimizatorInterface(f_, gradf_, Stop_, maxIterations_), lo(nullptr, nullptr, linearStop_, lom_, step_, indent_, maxIterations_) {};
	GradOptFR(smoothFunction<double, vector<double>> f_, smoothFunction<vector<double>, vector<double>> gradf_, stopCriteria<vector<double>> Stop_,
		LinearOptimizator lo_, size_t maxIterations_ = MAX_OPTIMIZE_ITERATIONS)
		: DerivativeOptimizatorInterface(f_, gradf_, Stop_, maxIterations_), lo(lo_) {};
	~GradOptFR() {};
	std::pair<vector<double>, double> optimize(vector<double> x0, inAreaCheck<vector<double>> inArea) final;
};

