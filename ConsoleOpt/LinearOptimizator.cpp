#include "LinearOptimizator.h"

double LinearOptimizator::optimize(std::function<double(double)> f, std::function<double(double)> df) const
{
    double optimalValue=f(-LINEAR_OPTIMIZE_INDENT);
    for (double i = -LINEAR_OPTIMIZE_INDENT; i < LINEAR_OPTIMIZE_INDENT; i += LINEAR_OPTIMIZE_SPLIT_SIZE)
    {
        optimalValue = std::max(optimalValue, lom(i, i + LINEAR_OPTIMIZE_SPLIT_SIZE, f, df).second);
    }
    return optimalValue;
}
