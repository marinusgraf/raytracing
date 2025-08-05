#ifndef HITTABLE_H
#define HITTABLE_H
#include "interval.hpp"
#include "vec3.hpp"
#include "ray.hpp"

class hit_record {
 public:
  point3 p;
  vec3 normal;
  double t;
  bool front_face;

  void set_face_normal(const ray& r, const vec3& outward_normal);
};

class hittable {
 public:
  virtual ~hittable() = default;
  virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif
