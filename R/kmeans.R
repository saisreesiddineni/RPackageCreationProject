#' Perform K-means Clustering
#'
#' This function performs K-means clustering on a set of data points in two-dimensional space.
#' @name kMeans_interface
#' @param pointX A numeric vector representing the x-coordinates of data points.
#' @param pointY A numeric vector representing the y-coordinates of data points.
#' @param k An integer specifying the number of clusters to create.
#' @param maxIterations An integer specifying the maximum number of iterations for the K-means algorithm.
#' @param centroidsX A numeric vector representing the initial x-coordinates of cluster centroids.
#' @param centroidsY A numeric vector representing the initial y-coordinates of cluster centroids.
#'
#' @return A numeric vector containing cluster assignments for each data point. Each element of the vector corresponds to the cluster ID to which the corresponding data point belongs.
#'
#' @export
#'
#' This function is intended for use by other packages and is exported for that purpose.
#'
#' @examples
#' pointX <- c(1.0, 2.0, 3.0)
#' pointY <- c(4.0, 5.0, 6.0)
#' k <- 3
#' maxIterations <- 100
#' centroidsX <- numeric(k)
#' centroidsY <- numeric(k)
#' kmeans_algo(pointX, pointY, k, maxIterations, centroidsX, centroidsY)
#' 
kmeans_algo <- function(pointX, pointY, k, maxIterations, centroidsX, centroidsY)
{
  cluster.assignment.vec <- .Call(`kMeans_interface`, pointX, pointY, k, maxIterations, centroidsX, centroidsY)
  cluster.assignment.vec
}