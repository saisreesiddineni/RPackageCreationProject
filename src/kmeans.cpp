#include "kmeans.h"

// Function to calculate the Euclidean distance between two points
double calculateDistance(const double x1, const double y1, const double x2, const double y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// Function to assign each point to the nearest cluster
void assignToClusters(
    const std::vector<double>& pointX,
    const std::vector<double>& pointY,
    const std::vector<double>& centroidsX,
    const std::vector<double>& centroidsY,
    std::vector<int>& clusterAssignments
) {
  for (size_t i = 0; i < pointX.size(); i++) {
    double minDist = calculateDistance(pointX[i], pointY[i], centroidsX[0], centroidsY[0]);
    clusterAssignments[i] = 0;
    for (size_t j = 1; j < centroidsX.size(); j++) {
      double dist = calculateDistance(pointX[i], pointY[i], centroidsX[j], centroidsY[j]);
      if (dist < minDist) {
        minDist = dist;
        clusterAssignments[i] = static_cast<int>(j);
      }
    }
  }
}

// Function to update the cluster centroids
void updateCentroids(
    const std::vector<double>& pointX,
    const std::vector<double>& pointY,
    const std::vector<int>& clusterAssignments,
    std::vector<double>& centroidsX,
    std::vector<double>& centroidsY
) {
  for (size_t i = 0; i < centroidsX.size(); i++) {
    double sumX = 0, sumY = 0;
    int count = 0;
    for (size_t j = 0; j < pointX.size(); j++) {
      if (clusterAssignments[j] == static_cast<int>(i)) {
        sumX += pointX[j];
        sumY += pointY[j];
        count++;
      }
    }
    if (count > 0) {
      centroidsX[i] = sumX / count;
      centroidsY[i] = sumY / count;
    }
  }
}

// K-means clustering function
std::vector<int> kMeans(
    std::vector<double>& pointX,
    std::vector<double>& pointY,
    int k,
    int maxIterations,
    std::vector<double>& centroidsX,
    std::vector<double>& centroidsY
) {
  std::srand(static_cast<unsigned>(std::time(nullptr)));
               
               // Initialize random cluster centroids
               centroidsX.resize(k);
               centroidsY.resize(k);
               for (int i = 0; i < k; i++) {
                 int randIndex = std::rand() % pointX.size();
                 centroidsX[i] = pointX[randIndex];
                 centroidsY[i] = pointY[randIndex];
               }
               
               std::vector<int> clusterAssignments(pointX.size(), -1);
               
               for (int iteration = 0; iteration < maxIterations; iteration++) {
                 // Assign points to the nearest cluster
                 assignToClusters(pointX, pointY, centroidsX, centroidsY, clusterAssignments);
                 
                 // Update cluster centroids
                 updateCentroids(pointX, pointY, clusterAssignments, centroidsX, centroidsY);
               }
               
               return clusterAssignments;
}