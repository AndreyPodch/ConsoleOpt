#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <utility>
#include <functional>
#include <exception>
#include <optional>
using namespace boost::numeric::ublas;

const double LINEAR_OPTIMIZE_INDENT = 2;
const double LINEAR_OPTIMIZE_SPLIT_SIZE = 1e-5;

typedef double(*smoothFunction)(vector<double> x);
typedef vector<double>(*gradientFunction)(vector<double> x);
typedef bool(*stopCriteria)(vector<double> x0, double f0, vector<double> x1, double f1);
typedef std::pair<double, double>(*linearOptimizeMethod)(std::function <double(double)> f, std::function <double(double)> df);

inline double scalarProduct(vector<double> x, vector<double> y);