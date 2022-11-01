#pragma once
#include "BasicDef.h"
template <class T>
class OptimizatorInterface
{
protected:
	smoothFunction<double, T> f;
	stopCriteria<T> Stop;
	size_t maxIterations;
public:
	virtual std::pair<T, double> optimize(T x0, inAreaCheck<T>) = 0;
	OptimizatorInterface<T>(smoothFunction<double, T> f_, stopCriteria<T> Stop_, size_t maxIterations_=MAX_OPTIMIZE_ITERATIONS) 
		:f( f_ ), Stop(Stop_), maxIterations(maxIterations_) {};
	void setStopCriteria(stopCriteria<T> Stop_) { Stop = Stop_; }
	void setMaxIterations(size_t maxIterations_) { maxIterations = maxIterations_; }
};

