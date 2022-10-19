#pragma once
#include "BasicDef.h"
class LinearOptimizator
{
private:
	linearOptimizeMethod lom;
	double indent;
	double step;
public:
	LinearOptimizator(linearOptimizeMethod lom_, double step_=LINEAR_OPTIMIZE_SPLIT_SIZE, double indent_=LINEAR_OPTIMIZE_INDENT) : lom(lom_), indent(indent_), step(step_) {};
	std::pair<double, double> optimize(std::function <double(double)> f, std::function <double(double)> df, std::function<bool(double)> inSegment) const;
	void changeLinearOptimizeMethod(linearOptimizeMethod lom_) { lom = lom_; };
	void changeStep(double step_) { step = step_; };
	void changeIndent(double indent_) { indent = indent_; };
};

