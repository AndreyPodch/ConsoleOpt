#pragma once
#include "BasicDef.h"
#include "DerivativeOptimizatorInterface.h"
class LinearOptimizator: public DerivativeOptimizatorInterface<double>
{
private:
	linearOptimizeMethod lom;
	double indent;
	double searchPrecision;
	double searchStep;
public:
	LinearOptimizator(smoothFunction<double, double> f_, smoothFunction<double, double> fDiff_, double searchPrecision_,
		linearOptimizeMethod lom_,
		double step_ = LINEAR_OPTIMIZE_IN_AREA_CHECK_SPLIT_SIZE, double indent_ = LINEAR_OPTIMIZE_INDENT, size_t maxIterations_ = MAX_OPTIMIZE_ITERATIONS)
		: DerivativeOptimizatorInterface(f_, fDiff_, nullptr, maxIterations_)
		, searchPrecision(searchPrecision_), lom(lom_), indent(indent_), searchStep(step_) {};
	std::pair<double, double> optimize(double x0, inAreaCheck<double> inArea);
	void setLinearOptimizeMethod(linearOptimizeMethod lom_) { lom = lom_; };
	void setSearchPrecision(double searchPrecision_) { searchPrecision = searchPrecision_; }
	void setStep(double step_) { searchStep = step_; };
	void setIndent(double indent_) { indent = indent_; };
};

