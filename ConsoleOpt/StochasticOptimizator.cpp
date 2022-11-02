#include "StochasticOptimizator.h"
/// <summary>
/// Check, if random point in already cutted zone
/// </summary>
/// <param name="v"> List of cutted circles centers</param>
/// <param name="x0"> Checking point</param>
/// <returns></returns>
bool StochasticOptimizator::isNotCutted(std::list<vector<double>>& v, vector<double> x0) const
{
    std::list<vector<double>> ::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        if (distanceBetween(*it, x0) <= radiusOfCut) return false;
    }
    return true;
}

std::pair<vector<double>, double> StochasticOptimizator::optimize(vector<double> x0, inAreaCheck<vector<double>> inArea)
{
    std::list<vector<double>> alreadyVisited;
    double optValue=f(x0);
    size_t curIter = 0;
    vector<double> optPoint, curPoint;
    do
    {
        curPoint = randomPt(); // generate random point
        if (inArea(curPoint) && isNotCutted(alreadyVisited, curPoint)) // make selection
        {
            alreadyVisited.push_back(curPoint);
            if (optValue > f(curPoint))
            {
                optValue = f(curPoint);
                optPoint = curPoint;
            }
            if (curIter++ > maxIterations) break;
        }
        else continue;
    } while (!Stop(x0,f(x0),curPoint,f(curPoint)));
    return std::make_pair(optPoint, optValue);
}
