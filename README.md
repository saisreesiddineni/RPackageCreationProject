# RPackageCreationProject
# KMeans and GMM package

This R package provides a demonstration of the K-Means and GMM clustering algorithms implemented in C++. Users can use this package to perform K-Means and GMM clustering on their data.

## Installation

To install this package from CRAN, you can use the following command:

```R
install.packages("RPackageCreationProject")
##OR:
if (!requireNamespace("remotes")) install.packages("remotes")
remotes::install_github("saisreesiddineni/RPackageCreationProject")

Examples:

GMM:

data <- c(1.0, 2.0, 3.0, 4.0, 5.0)
numComponents <- 2
maxIters <- 100
gmm_algo(data, numComponents, maxIters)

K-means:

pointX <- c(1.0, 2.0, 3.0)
pointY <- c(4.0, 5.0, 6.0)
k <- 3
maxIterations <- 100
centroidsX <- numeric(k)
centroidsY <- numeric(k)
kmeans_algo(pointX, pointY, k, maxIterations, centroidsX, centroidsY)

<!-- badges: start -->
  [![R-CMD-check](https://github.com/saisreesiddineni/RPackageCreationProject/actions/workflows/R-CMD-check.yaml/badge.svg)](https://github.com/saisreesiddineni/RPackageCreationProject/actions/workflows/R-CMD-check.yaml)
  <!-- badges: end -->