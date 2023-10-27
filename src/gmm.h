#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <R.h>
#include <Rmath.h>

const int N = 100;
const int K = 2;

struct GaussianComponent {
  double mean;
  double covariance;
};

std::vector<std::vector<double>> fitGMM(std::vector<double>& data, int numComponents, int maxIters);
