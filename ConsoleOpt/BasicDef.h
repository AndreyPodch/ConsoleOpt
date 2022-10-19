#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <utility>
#include <functional>
#include <iterator>
#include <list>
#include <exception>
#include <random>
#include <iostream>
using namespace boost::numeric::ublas;

const double LINEAR_OPTIMIZE_INDENT = 1;
const double LINEAR_OPTIMIZE_SPLIT_SIZE = 1e-5;
const size_t MAX_OPTIMIZE_ITERATION = 20000;
const double STANDART_RADIUS_OF_CUT = 0.03;


typedef double(*smoothFunction)(vector<double> x);
typedef vector<double>(*gradientFunction)(vector<double> x);
typedef vector<double>(*randomPointInCoverArea)();
typedef bool(*stopCriteria)(vector<double> x0, double f0, vector<double> x1, double f1);
typedef std::pair<double, double>(*linearOptimizeMethod)(double a, double b, std::function <double(double)> f, std::function <double(double)> df);
typedef bool(*inAreaCheck)(vector<double>);

double scalarProduct(vector<double> x, vector<double> y);
double distanceBetween(vector<double> x, vector<double> y);