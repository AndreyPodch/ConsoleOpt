#pragma once
#include "BasicDef.h";
#include "OptimizatorInterface.h"
template <class T>
class DerivativeOptimizatorInterface: public OptimizatorInterface<T>
{
protected:
	smoothFunction<T, T> fDiff;
public:
	DerivativeOptimizatorInterface<T>(smoothFunction<double, T> f_, smoothFunction<T, T> fDiff_, stopCriteria<T> Stop_, 
		size_t maxIterations_ = MAX_OPTIMIZE_ITERATIONS) : OptimizatorInterface(f_, Stop_, maxIterations_), fDiff( fDiff_ ) {};
	void setFunctionAndDifferential(smoothFunction<double, T> f_, smoothFunction<T, T> fDiff_) { OptimizatorInterface::f = f_; fDiff = fDiff_; }
};

