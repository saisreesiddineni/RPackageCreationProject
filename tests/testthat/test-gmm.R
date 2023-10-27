library(RPackageCreationProject)
library(testthat)
context("gmm")

test_that("gmm_algo computes the same answer as R", {
  N <- 10
  K <- 2
  max_iterations <- 100
  data <- numeric(N)
  set.seed(123)
  data <- runif(N)
  gmm <- gmm_algo(data, K, max_iterations)
  expect_equal(nrow(gmm), N)
  expect_equal(ncol(gmm), K)
})
