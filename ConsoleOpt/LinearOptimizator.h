#pragma once
#include "BasicDef.h"
#include "DerivativeOptimizatorInterface.h"
/// <summary>
/// Implement optimize for double->double function with derivative
/// </summary>

/// <summary>
/// Struct for parameters of linear optimization
/// </summary>
struct LinearOptimizeParameters
{
	/// <summary>
	/// Search precision (used different in different criterias)
	/// </summary>
	double searchPrecision;
	/// <summary>
	///	Indent in segment of search [-indent, indent]
	/// </summary>
	double indent;
	/// <summary>
	/// Step in Area detection (more in optimize realization)
	/// </summary>
	double searchStep;
	LinearOptimizeParameters(double searchPrecision_, double indent_, double searchStep_)
		:searchPrecision(searchPrecision_), indent(indent_), searchStep(searchStep_) {};
};

class LinearOptimizator: public DerivativeOptimizatorInterface<double>
{
private:
	/// <summary>
	/// Method that used in optimization process
	/// </summary>
	linearOptimizeMethod lom;
	LinearOptimizeParameters lp;
public:
	LinearOptimizator(smoothFunction<double, double> f_, smoothFunction<double, double> fDiff_
		, linearOptimizeMethod lom_
		, double searchPrecision_, double step_ = LINEAR_OPTIMIZE_IN_AREA_CHECK_SPLIT_SIZE
		, double indent_ = LINEAR_OPTIMIZE_INDENT, size_t maxIterations_ = MAX_OPTIMIZE_ITERATIONS)
		: DerivativeOptimizatorInterface(f_, fDiff_, nullptr, maxIterations_)
		, lom(lom_), lp(searchPrecision_,  indent_, step_) {};
	LinearOptimizator(smoothFunction<double, double> f_, smoothFunction<double, double> fDiff_
		, linearOptimizeMethod lom_, LinearOptimizeParameters lp_, size_t maxIterations)
		: DerivativeOptimizatorInterface(f_, fDiff_, nullptr, maxIterations), lom(lom_), lp(lp_) {};
	std::pair<double, double> optimize(double x0, inAreaCheck<double> inArea);
	void setLinearOptimizeMethod(linearOptimizeMethod lom_) { lom = lom_; };
	void setSearchPrecision(double searchPrecision_) { lp.searchPrecision = searchPrecision_; }
	void setStep(double step_) { lp.searchStep = step_; };
	void setIndent(double indent_) { lp.indent = indent_; };
};

