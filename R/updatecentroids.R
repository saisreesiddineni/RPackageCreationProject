#' Update centroids based on cluster assignments
#'
#' This function updates the centroids based on the cluster assignments.
#' @name updateCentroids_interface
#' @param pointX A numeric vector representing the x-coordinates of data points.
#' @param pointY A numeric vector representing the y-coordinates of data points.
#' @param clusterAssignments A vector of integers indicating the cluster assignments for each data point.
#' @param centroidsX A numeric vector representing the x-coordinates of centroids.
#' @param centroidsY A numeric vector representing the y-coordinates of centroids.
#'
#' @return None (the function updates centroids in place).
#'
#' @export
#'
#' @examples
#' pointX <- c(1.0, 2.0, 3.0, 4.0, 5.0)
#' pointY <- c(2.0, 3.0, 4.0, 5.0, 6.0)
#' clusterAssignments <- c(1, 1, 2, 2, 1)
#' centroidsX <- c(1.5, 4.0)
#' centroidsY <- c(2.5, 5.0)
#' update_centroids(pointX, pointY, clusterAssignments, centroidsX, centroidsY)
update_centroids <- function(pointX, pointY, clusterAssignments, centroidsX, centroidsY)
{
  .Call(`updateCentroids_interface`, pointX, pointY, clusterAssignments, centroidsX, centroidsY)
}