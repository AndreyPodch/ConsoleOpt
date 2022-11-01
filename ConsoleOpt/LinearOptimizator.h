#pragma once
#include "BasicDef.h"
#include "DerivativeOptimizatorInterface.h"
class LinearOptimizator: public DerivativeOptimizatorInterface<double>
{
private:
	linearOptimizeMethod lom;
	double indent;
	double step;
public:
	LinearOptimizator(smoothFunction<double, double> f_, smoothFunction<double, double> fDiff_, stopCriteria<double> Stop_,
		linearOptimizeMethod lom_,
		double step_=LINEAR_OPTIMIZE_SPLIT_SIZE, double indent_=LINEAR_OPTIMIZE_INDENT, size_t maxIterations_ = MAX_OPTIMIZE_ITERATIONS)
		: DerivativeOptimizatorInterface(f_, fDiff_, Stop_, maxIterations_),  lom(lom_), indent(indent_), step(step_) {};
	std::pair<double, double> optimize(double x0, inAreaCheck<double> inArea);
	void setLinearOptimizeMethod(linearOptimizeMethod lom_) { lom = lom_; };
	void setStep(double step_) { step = step_; };
	void setIndent(double indent_) { indent = indent_; };
};

