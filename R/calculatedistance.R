#' Calculate the Euclidean distance between two points
#'
#' This function calculates the Euclidean distance between two points represented by their coordinates (x1, y1) and (x2, y2).
#' @name calculateDistance_interface
#' @param x1 A numeric value representing the x-coordinate of the first point.
#' @param y1 A numeric value representing the y-coordinate of the first point.
#' @param x2 A numeric value representing the x-coordinate of the second point.
#' @param y2 A numeric value representing the y-coordinate of the second point.
#'
#' @return The Euclidean distance between the two points as a numeric value.
#'
#' @export
#'
#' @examples
#' x1 <- 1.0
#' y1 <- 2.0
#' x2 <- 3.0
#' y2 <- 4.0
#' distance <- calculate_distance(x1, y1, x2, y2)
calculate_distance <- function(x1, y1, x2, y2)
{
  distance <- .Call(`calculateDistance_interface`, x1, y1, x2, y2)
  distance
}