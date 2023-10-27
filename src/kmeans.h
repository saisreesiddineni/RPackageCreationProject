#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

double calculateDistance(const double x1, const double y1, const double x2, const double y2);
void assignToClusters(
    const std::vector<double>& pointX,
    const std::vector<double>& pointY,
    const std::vector<double>& centroidsX,
    const std::vector<double>& centroidsY,
    std::vector<int>& clusterAssignments
);
void updateCentroids(
    const std::vector<double>& pointX,
    const std::vector<double>& pointY,
    const std::vector<int>& clusterAssignments,
    std::vector<double>& centroidsX,
    std::vector<double>& centroidsY
);
std::vector<int> kMeans(
    std::vector<double>& pointX,
    std::vector<double>& pointY,
    int k,
    int maxIterations,
    std::vector<double>& centroidsX,
    std::vector<double>& centroidsY
);