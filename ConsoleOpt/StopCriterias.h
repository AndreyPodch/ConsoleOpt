#pragma once
#include "BasicDef.h"
const double STANDARD_STOP_EPSILON = 1e-8;

bool absValueDiffStop(vector<double> x0, double f0, vector<double> x1, double f1);
bool absCoordDiffStop(vector<double> x0, double f0, vector<double> x1, double f1);
bool relValueDiffStop(vector<double> x0, double f0, vector<double> x1, double f1);
bool relCoordDiffStop(vector<double> x0, double f0, vector<double> x1, double f1);