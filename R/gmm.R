#' Gaussian Mixture Model Algorithm
#'
#' This function fits a Gaussian Mixture Model (GMM) to the input data using the Expectation-Maximization (EM) algorithm.
#' @name fitGMM_interface
#' @param data The input data matrix or data frame.
#' @param numComponents The number of Gaussian components to fit in the GMM.
#' @param max_iterations The maximum number of iterations for the EM algorithm.
#'
#' @return A list containing the following components:
#'   - 'mu' - A matrix of estimated means for each Gaussian component.
#'   - 'sigma' - A list of estimated covariance matrices for each component.
#'   - 'pi' - A vector of estimated mixing proportions for each component.
#'   - 'log_likelihood' - The log-likelihood of the final GMM model.
#'
#' @export
#'
#' @examples
#' data <- c(1.0, 2.0, 3.0, 4.0, 5.0)
#' numComponents <- 2
#' maxIters <- 100
#' gmm_algo(data, numComponents, maxIters)
gmm_algo <- function(data, numComponents, max_iterations)
{
  result.mat <- .Call("fitGMM_interface", data, numComponents, max_iterations)
  result.mat
}