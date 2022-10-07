#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <utility>
#include <optional>
using namespace boost::numeric::ublas;

typedef double(*smoothFunction)(vector<double> x);
typedef vector<double>(*gradientFunction)(vector<double> x);
typedef bool(*stopCriteria)(vector<double> x0, double f0, vector<double> x1, double f1);
typedef std::pair<double, double>(*lineOptimize)(vector<double> x, vector<double> dir);