#include "gmm.h"
#include <Rcpp.h>
using namespace Rcpp;

std::vector<std::vector<double>> fitGMM(std::vector<double>& data, int numComponents, int maxIters) {
  GetRNGstate();
  
  std::vector<GaussianComponent> components(numComponents);
  std::vector<double> weight(numComponents, 1.0 / numComponents);
  
  for (int k = 0; k < numComponents; k++) {
    components[k].mean = data[k];
    components[k].covariance = 1e-6;
  }
  
  std::vector<std::vector<double>> responsibilities(data.size(), std::vector<double>(numComponents, 0.0));
  
  for (int iteration = 0; iteration < maxIters; iteration++) {
    // E-step
    for (int i = 0; i < data.size(); i++) {
      double denominator = 0.0;
      
      for (int k = 0; k < numComponents; k++) {
        double exponent = -0.5 * std::pow((data[i] - components[k].mean) / (components[k].covariance + 1e-6), 2);
        responsibilities[i][k] = weight[k] * (1.0 / (components[k].covariance * sqrt(2 * M_PI))) * exp(exponent);
        denominator += responsibilities[i][k];
      }
      
      for (int k = 0; k < numComponents; k++) {
        responsibilities[i][k] /= (denominator + 1e-6);
      }
    }
    
    // M-step
    for (int k = 0; k < numComponents; k++) {
      double sum_responsibilities = 0.0;
      double sum_weighted_data = 0.0;
      double sum_weighted_sq_data = 0.0;
      
      for (int i = 0; i < data.size(); i++) {
        sum_responsibilities += responsibilities[i][k];
        sum_weighted_data += responsibilities[i][k] * data[i];
        sum_weighted_sq_data += responsibilities[i][k] * (data[i] * data[i]);
      }
      
      components[k].mean = sum_weighted_data / (sum_responsibilities + 1e-6);
      components[k].covariance = (sum_weighted_sq_data / (sum_responsibilities + 1e-6)) - (components[k].mean * components[k].mean);
      weight[k] = (sum_responsibilities / data.size()) + 1e-6;
    }
  }
  
  PutRNGstate();
  
  return responsibilities;
}
