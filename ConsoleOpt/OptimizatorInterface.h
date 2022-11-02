#pragma once
#include "BasicDef.h"
template <class T>
/// <summary>
/// Interface for optimizator without using first derivative(or gradient)
/// </summary>
/// <typeparam name="T"> Type of function domain</typeparam>
class OptimizatorInterface
{
protected:
	/// /// <summary>
	/// Function for optimization
	/// </summary>
	smoothFunction<double, T> f; 
	/// <summary>
	/// Criteria used for stop in optimize process
	/// </summary>
	stopCriteria<T> Stop;
	/// <summary>
	/// Number of max iterations, when optimize process stoped
	/// </summary>
	size_t maxIterations;
public:
/// <summary>
/// Find a minimum of function f
/// </summary>
/// <param name="x0"> Starting point</param>
/// <param name="inArea"> Bool check for optimization in some Area</param>
/// <returns> Pair of optimal point and optimal value </returns>
	virtual std::pair<T, double> optimize(T x0, inAreaCheck<T> inArea) = 0;
	OptimizatorInterface<T>(smoothFunction<double, T> f_, stopCriteria<T> Stop_, size_t maxIterations_=MAX_OPTIMIZE_ITERATIONS) 
		:f( f_ ), Stop(Stop_), maxIterations(maxIterations_) {};
	void setStopCriteria(stopCriteria<T> Stop_) { Stop = Stop_; }
	void setMaxIterations(size_t maxIterations_) { maxIterations = maxIterations_; }
};

