#include "LinearOptimizator.h"

std::pair<double, double> LinearOptimizator::optimize(double x0, inAreaCheck<double> inArea)
{
    double leftInArea, rightInArea;
    bool leftFounded = 0, rightFounded = 0;
    double li = -indent, ri = indent;
    while (!(leftFounded && rightFounded))
    {
        if (!leftFounded && inArea(li))
        {
            leftFounded=true;
            leftInArea=li;
        }
        if (!rightFounded && inArea(ri))
        {
            rightFounded = true;
            rightInArea = ri;
        }
        li += searchStep;
        ri -= searchStep;
    }
    return lom(leftInArea, rightInArea, f, fDiff, searchPrecision);
}
