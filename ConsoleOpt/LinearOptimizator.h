#pragma once
#include "BasicDef.h"
#include "DerivativeOptimizatorInterface.h"
/// <summary>
/// Implement optimize for double->double function with derivative
/// </summary>
class LinearOptimizator: public DerivativeOptimizatorInterface<double>
{
private:
	/// <summary>
	/// Method that used in optimization process
	/// </summary>
	linearOptimizeMethod lom;
	/// <summary>
	///	Indent in segment of search [-indent, indent]
	/// </summary>
	double indent;
	/// <summary>
	/// Search precision (used different in different criterias)
	/// </summary>
	double searchPrecision;
	/// <summary>
	/// Step in Area detection (more in optimize realization)
	/// </summary>
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

