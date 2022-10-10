#pragma once
#include "BasicDef.h"
std::pair<double, double> linearSearch(double a, double b, std::function <double(double)> f, std::function <double(double)> df);