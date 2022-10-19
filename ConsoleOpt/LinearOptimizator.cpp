#include "LinearOptimizator.h"

std::pair<double, double> LinearOptimizator::optimize(std::function<double(double)> f, std::function<double(double)> df, std::function<bool(double)> inSegment) const
{
    double optimalValue=f(-indent);
    double optimalPoint = -indent;
    for (double i = -indent; i < indent; i += step)
    {
        if (!inSegment(i) || !inSegment(i + step)) continue;
        std::pair<double, double> curIt = lom(i, i + step, f, df);
        if (curIt.second < optimalValue)
        {
            optimalPoint = curIt.first;
            optimalValue = curIt.second;
        }
    }
    return std::make_pair(optimalPoint,optimalValue);
}
