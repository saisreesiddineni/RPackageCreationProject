#' Assign data points to clusters based on centroids
#'
#' This function assigns data points to clusters based on the given centroids.
#' @name assignToClusters_interface
#' @param pointX A numeric vector representing the x-coordinates of data points.
#' @param pointY A numeric vector representing the y-coordinates of data points.
#' @param centroidsX A numeric vector representing the x-coordinates of centroids.
#' @param centroidsY A numeric vector representing the y-coordinates of centroids.
#' @param clusterAssignments A vector of integers indicating the cluster assignments for each data point.
#'
#' @return A vector of integers representing the cluster assignments for each data point.
#'
#' @export
#'
#' @examples
#' pointX <- c(1.0, 2.0, 3.0, 4.0, 5.0)
#' pointY <- c(2.0, 3.0, 4.0, 5.0, 6.0)
#' centroidsX <- c(1.5, 4.0)
#' centroidsY <- c(2.5, 5.0)
#' clusterAssignments <- integer(length(pointX))
#' assign_to_clusters(pointX, pointY, centroidsX, centroidsY, clusterAssignments)
assign_to_clusters <- function(pointX, pointY, centroidsX, centroidsY, clusterAssignments)
{
  .Call(`assignToClusters_interface`, pointX, pointY, centroidsX, centroidsY, clusterAssignments)
  clusterAssignments
}