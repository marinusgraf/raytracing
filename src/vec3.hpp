#ifndef VEC3_H
#define VEC3_H
#include "rtweekend.hpp"
#include <iostream>

class vec3 {
 public:
  double e[3];

  vec3();
  vec3(double e0, double e1, double e2);

  double x() const;
  double y() const;
  double z() const;

  vec3 operator-() const;
  double operator[](int i) const;
  double& operator[](int i);

  vec3& operator+=(const vec3& v);

  vec3& operator-=(const vec3& v);

  vec3& operator*=(const vec3& v);

  vec3& operator*=(double scalar);

  vec3& operator/=(double scalar);

  double length() const;

  double length_squared() const;

  static vec3 random();

  static vec3 random(double min, double max);
};

using point3 = vec3;

inline std::ostream& operator<<(std::ostream& os, const vec3& v) { return os << v[0] << " " << v[1] << " " << v[2]; }

inline vec3 operator+(const vec3& lhs, const vec3& rhs) {
  vec3 result = lhs;
  return (result += rhs);
}

inline vec3 operator-(const vec3& lhs, const vec3& rhs) {
  vec3 result = lhs;
  return (result -= rhs);
}

inline vec3 operator*(const vec3& lhs, const vec3& rhs) {
  vec3 result = lhs;
  return (result *= rhs);
}

inline vec3 operator*(const vec3& lhs, double t) {
  vec3 result = lhs;
  return (result *= t);
}

inline vec3 operator*(double t, const vec3& rhs) {
  vec3 result = rhs;
  return (result *= t);
}

inline vec3 operator/(const vec3& lhs, double t) {
  vec3 result = lhs;
  return (result /= t);
}

inline double dot(const vec3& lhs, const vec3& rhs) {
  double result = 0;
  for (size_t i = 0; i < 3; i++) {
    result += lhs[i] * rhs[i];
  }
  return result;
}

inline vec3 cross(const vec3& lhs, const vec3& rhs) {
  vec3 result = lhs;
  result.e[0] = (lhs[1] * rhs[2]) - (rhs[1] * lhs[2]);
  result.e[1] = (lhs[2] * rhs[0]) - (lhs[0] * rhs[2]);
  result.e[2] = (lhs[0] * rhs[1]) - (rhs[0] * lhs[1]);
  return result;
}

inline vec3 unit_vector(const vec3& v) { return v / v.length(); }

inline vec3 random_unit_vector() {
  while (true) {
    vec3 candidate = vec3::random(-1, 1);
    double length_squared = candidate.length_squared();
    if (1e-160 < length_squared && length_squared <= 1) {
      return candidate / std::sqrt(length_squared);
    }
  }
}

inline vec3 random_on_hemisphere(const vec3& normal) {
  vec3 unit_vector = random_unit_vector();
  if (dot(unit_vector, normal) < 0.0) {
    unit_vector = -unit_vector;
  }
  return unit_vector;
}
#endif
