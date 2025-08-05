#ifndef RT_WEEKEND_H
#define RT_WEEKEND_H

#include <cmath>
#include <iostream>
#include <random>
#include <limits>
#include <memory>

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double random_double(double min, double max) {
  static std::uniform_real_distribution<double> dist(min, max);
  static std::mt19937 generator;
  return dist(generator);
}

inline double random_double() { return random_double(0.0, 1.0); }

inline double degrees_to_radians(double degrees) { return (180.0 / pi) * degrees; }

#endif
