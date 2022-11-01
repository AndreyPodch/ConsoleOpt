#include "LinearOptimizator.h"

std::pair<double, double> LinearOptimizator::optimize(double x0, inAreaCheck<double> inArea)
{
    double optimalValue=f(-indent);
    double optimalPoint = -indent;
    for (double i = -indent; i < indent; i += step)
    {
        if (!inArea(i) || !inArea(i + step)) continue;
        std::pair<double, double> curIt = lom(i, i + step, f, fDiff);
        if (curIt.second < optimalValue)
        {
            optimalPoint = curIt.first;
            optimalValue = curIt.second;
        }
    }
    return std::make_pair(optimalPoint,optimalValue);
}
