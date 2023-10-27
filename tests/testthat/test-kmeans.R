library(RPackageCreationProject)
library(testthat)
context("kmeans")

test_that("kmeans_algo computes the same answer as R", {
  pointX <- c(2.0, 3.0, 1.0, 8.0, 9.0, 7.0)
  pointY <- c(3.0, 3.0, 2.0, 8.0, 8.0, 9.0)
  k <- 2
  maxIterations <- 100
  centX <- c(2.0)
  centY <- c(2.0)
  kmeans <- kmeans_algo(pointX, pointY, k, maxIterations, centX, centY)
  expect_equal(length(pointX), length(kmeans))
})
