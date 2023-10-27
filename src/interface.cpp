#include "gmm.h"
#include "kmeans.h"
#include <R_ext/Rdynload.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

RcppExport SEXP fitGMM_interface(SEXP dataSEXP, SEXP numComponentsSEXP, SEXP maxItersSEXP) {
  BEGIN_RCPP

  Rcpp::NumericVector data(dataSEXP);
  int numComponents = Rcpp::as<int>(numComponentsSEXP);
  int maxIters = Rcpp::as<int>(maxItersSEXP);

  std::vector<double> dataVector(data.begin(), data.end());
  std::vector<std::vector<double>> result = fitGMM(dataVector, numComponents, maxIters);
  int numRows = result.size();
  int numCols = result[0].size();
  Rcpp::NumericMatrix resultR(numRows, numCols);

  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      resultR(i, j) = result[i][j];
    }
  }

  return resultR;

  END_RCPP
}

RcppExport SEXP calculateDistance_interface(SEXP x1SEXP, SEXP y1SEXP, SEXP x2SEXP, SEXP y2SEXP) {
  BEGIN_RCPP
  
  double x1 = Rcpp::as<double>(x1SEXP);
  double y1 = Rcpp::as<double>(y1SEXP);
  double x2 = Rcpp::as<double>(x2SEXP);
  double y2 = Rcpp::as<double>(y2SEXP);

  double result = calculateDistance(x1, y1, x2, y2);

  return Rcpp::wrap(result);
  
  END_RCPP
}

RcppExport SEXP assignToClusters_interface(SEXP pointXSEXP, SEXP pointYSEXP,
                                           SEXP centroidsXSEXP, SEXP centroidsYSEXP,
                                           SEXP clusterAssignmentsSEXP) {
  BEGIN_RCPP
  
  Rcpp::NumericVector pointX(pointXSEXP);
  Rcpp::NumericVector pointY(pointYSEXP);
  Rcpp::NumericVector centroidsX(centroidsXSEXP);
  Rcpp::NumericVector centroidsY(centroidsYSEXP);
  Rcpp::IntegerVector clusterAssignments(clusterAssignmentsSEXP);
  
  std::vector<double> pointXCpp = Rcpp::as<std::vector<double>>(pointX);
  std::vector<double> pointYCpp = Rcpp::as<std::vector<double>>(pointY);
  std::vector<int> clusterAssignmentsCpp = Rcpp::as<std::vector<int>>(clusterAssignments);
  std::vector<double> centroidsXCpp = Rcpp::as<std::vector<double>>(centroidsX);
  std::vector<double> centroidsYCpp = Rcpp::as<std::vector<double>>(centroidsY);
  
  assignToClusters(pointXCpp, pointYCpp,centroidsXCpp, centroidsYCpp, clusterAssignmentsCpp);
  
  clusterAssignments = Rcpp::wrap(clusterAssignmentsCpp);
  
  END_RCPP
}

RcppExport SEXP updateCentroids_interface(SEXP pointXSEXP, SEXP pointYSEXP,
                                          SEXP clusterAssignmentsSEXP,
                                          SEXP centroidsXSEXP, SEXP centroidsYSEXP) {
  BEGIN_RCPP
  
  Rcpp::NumericVector pointX(pointXSEXP);
  Rcpp::NumericVector pointY(pointYSEXP);
  Rcpp::IntegerVector clusterAssignments(clusterAssignmentsSEXP);
  Rcpp::NumericVector centroidsX(centroidsXSEXP);
  Rcpp::NumericVector centroidsY(centroidsYSEXP);
  
  std::vector<double> pointXCpp = Rcpp::as<std::vector<double>>(pointX);
  std::vector<double> pointYCpp = Rcpp::as<std::vector<double>>(pointY);
  std::vector<int> clusterAssignmentsCpp = Rcpp::as<std::vector<int>>(clusterAssignments);
  std::vector<double> centroidsXCpp = Rcpp::as<std::vector<double>>(centroidsX);
  std::vector<double> centroidsYCpp = Rcpp::as<std::vector<double>>(centroidsY);
  
  updateCentroids(pointXCpp, pointYCpp, clusterAssignmentsCpp, centroidsXCpp, centroidsYCpp);
  
  centroidsX = Rcpp::wrap(centroidsXCpp);
  centroidsY = Rcpp::wrap(centroidsYCpp);
  
  END_RCPP
}

RcppExport SEXP kMeans_interface(SEXP pointXSEXP, SEXP pointYSEXP, SEXP kSEXP,
                                 SEXP maxIterationsSEXP, SEXP centroidsXSEXP, SEXP centroidsYSEXP) {
  BEGIN_RCPP
  
  Rcpp::NumericVector pointX(pointXSEXP);
  Rcpp::NumericVector pointY(pointYSEXP);
  int k = Rcpp::as<int>(kSEXP);
  int maxIterations = Rcpp::as<int>(maxIterationsSEXP);
  Rcpp::NumericVector centroidsX(centroidsXSEXP);
  Rcpp::NumericVector centroidsY(centroidsYSEXP);
  
  std::vector<double> pointXCpp = Rcpp::as<std::vector<double>>(pointX);
  std::vector<double> pointYCpp = Rcpp::as<std::vector<double>>(pointY);
  std::vector<double> centroidsXCpp = Rcpp::as<std::vector<double>>(centroidsX);
  std::vector<double> centroidsYCpp = Rcpp::as<std::vector<double>>(centroidsY);

  std::vector<int> clusterAssignments = kMeans(pointXCpp, pointYCpp, k, maxIterations, centroidsXCpp, centroidsYCpp);
 
  centroidsX = Rcpp::wrap(centroidsXCpp);
  centroidsY = Rcpp::wrap(centroidsYCpp);

  return Rcpp::wrap(clusterAssignments);
  
  END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
  {"fitGMM_interface", (DL_FUNC) &fitGMM_interface, 3},
  {"calculateDistance_interface", (DL_FUNC) &calculateDistance_interface, 4},
  {"assignToClusters_interface", (DL_FUNC) &assignToClusters_interface, 5},
  {"updateCentroids_interface", (DL_FUNC) &updateCentroids_interface, 5},
  {"kMeans_interface", (DL_FUNC) &kMeans_interface, 6},
  {NULL, NULL, 0}
};

RcppExport void R_init_RPackageCreationProject(DllInfo *dll) {
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}