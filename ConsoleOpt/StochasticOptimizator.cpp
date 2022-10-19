#include "StochasticOptimizator.h"

bool StochasticOptimizator::isNotCutted(std::list<vector<double>>& v, vector<double> x0) const
{
    std::list<vector<double>> ::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        if (distanceBetween(*it, x0) <= radiusOfCut) return false;
    }
    return true;
}

std::pair<vector<double>, double> StochasticOptimizator::optimize() const
{
    std::list<vector<double>> alreadyVisited;
    double optValue=1e8;
    size_t curIter = 0;
    vector<double> optPoint, curPoint;
    do
    {
        curPoint = randomPt();
        if (inArea(curPoint) && isNotCutted(alreadyVisited, curPoint))
        {
            alreadyVisited.push_back(curPoint);
            if (optValue > f(curPoint))
            {
                optValue = f(curPoint);
                optPoint = curPoint;
            }
            if (curIter++ > maxIteration) break;
        }
    } while (1);
    return std::make_pair(optPoint, optValue);
}
