#pragma once
#include "BasicDef.h"
class LinearOptimizator
{
private:
	linearOptimizeMethod lom;
public:
	LinearOptimizator(linearOptimizeMethod lom_) : lom(lom_) {};
	double optimize(std::function <double(double)> f, std::function <double(double)> df) const;
};

