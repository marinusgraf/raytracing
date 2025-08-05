#include "interval.hpp"

interval::interval() : min(+infinity), max(-infinity) {}

interval::interval(double min, double max) : min(min), max(max) {}

double interval::size() const { return max - min; }

bool interval::contains(double val) { return min <= val && val <= max; }

bool interval::surrounds(double val) { return min < val && val < max; }

double interval::clamp(double val) const {
  if (val < min) {
    return min;
  }
  if (val > max) {
    return max;
  }
  return val;
}
