#ifndef INTERVAL_H
#define INTERVAL_H
#include "rtweekend.hpp"

class interval {
 public:
  double min, max;

  interval();

  interval(double min, double max);

  double size() const;

  bool contains(double val);

  bool surrounds(double val);

  double clamp(double val) const;

  static const interval empty, universe;
};

#endif
