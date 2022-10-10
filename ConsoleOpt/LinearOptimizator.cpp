#include "LinearOptimizator.h"

std::pair<double,double> LinearOptimizator::optimize(std::function<double(double)> f, std::function<double(double)> df) const
{
    double optimalValue=f(-LINEAR_OPTIMIZE_INDENT);
    double optimalPoint = -LINEAR_OPTIMIZE_INDENT;
    for (double i = -LINEAR_OPTIMIZE_INDENT; i < LINEAR_OPTIMIZE_INDENT; i += LINEAR_OPTIMIZE_SPLIT_SIZE)
    {
        std::pair<double, double> curIt = lom(i, i + LINEAR_OPTIMIZE_SPLIT_SIZE, f, df);
        if (curIt.second < optimalValue)
        {
            optimalPoint = curIt.first;
            optimalValue = curIt.second;
        }
    }
    return std::make_pair(optimalPoint,optimalValue);
}
