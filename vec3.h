#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
 public:
  double e[3];

  vec3() : e{0, 0, 0} {}
  vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

  double x() const { return e[0]; }
  double y() const { return e[1]; }
  double z() const { return e[2]; }

  vec3 operator-() { return vec3(-e[0], -e[1], -e[2]); }
  double operator[](int i) const { return e[i]; }
  double& operator[](int i) { return e[i]; }

  vec3& operator+=(const vec3& v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
  }

  vec3& operator-=(const vec3& v) {
    vec3 rhs = v;
    rhs = -rhs;
    return *this += rhs;
  }

  vec3& operator*=(const vec3& v) {
    e[0] *= v[0];
    e[1] *= v[1];
    e[2] *= v[2];
    return *this;
  }

  vec3& operator*=(double scalar) {
    e[0] *= scalar;
    e[1] *= scalar;
    e[2] *= scalar;
    return *this;
  }

  vec3& operator/=(double scalar) {
    *this *= 1 / scalar;
    return *this;
  }

  double length() const { return std::sqrt(length_squared()); }

  double length_squared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
  }
};

using point3 = vec3;

inline std::ostream& operator<<(std::ostream& os, const vec3& v) {
  return os << v[0] << " " << v[1] << " " << v[2];
}

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

#endif
