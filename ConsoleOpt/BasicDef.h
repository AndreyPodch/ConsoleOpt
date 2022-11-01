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
const size_t MAX_OPTIMIZE_ITERATIONS = 20000;
const double STANDART_RADIUS_OF_CUT = 0.03;


template <class T, class P> using smoothFunction = std::function<T (P)>;
template <class T> using stopCriteria = bool(*)(T x0, double f0, T x1, double f1);
template <class T> using inAreaCheck = std::function<bool(T)>;
typedef vector<double>(*randomPointInCoveringArea)();
typedef std::pair<double, double>(*linearOptimizeMethod)(double a, double b, std::function <double(double)> f, std::function <double(double)> df);

double scalarProduct(vector<double> x, vector<double> y);
double distanceBetween(vector<double> x, vector<double> y);