% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/updatecentroids.R
\name{updateCentroids_interface}
\alias{updateCentroids_interface}
\alias{update_centroids}
\title{Update centroids based on cluster assignments}
\usage{
update_centroids(pointX, pointY, clusterAssignments, centroidsX, centroidsY)
}
\arguments{
\item{pointX}{A numeric vector representing the x-coordinates of data points.}

\item{pointY}{A numeric vector representing the y-coordinates of data points.}

\item{clusterAssignments}{A vector of integers indicating the cluster assignments for each data point.}

\item{centroidsX}{A numeric vector representing the x-coordinates of centroids.}

\item{centroidsY}{A numeric vector representing the y-coordinates of centroids.}
}
\value{
None (the function updates centroids in place).
}
\description{
This function updates the centroids based on the cluster assignments.
}
\examples{
pointX <- c(1.0, 2.0, 3.0, 4.0, 5.0)
pointY <- c(2.0, 3.0, 4.0, 5.0, 6.0)
clusterAssignments <- c(1, 1, 2, 2, 1)
centroidsX <- c(1.5, 4.0)
centroidsY <- c(2.5, 5.0)
update_centroids(pointX, pointY, clusterAssignments, centroidsX, centroidsY)
}
