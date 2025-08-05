#ifndef SPHERE_H
#define SPHERE_H
#include "hittable.hpp"
#include "interval.hpp"
#include "vec3.hpp"
#include "ray.hpp"

class sphere : public hittable {
 public:
  sphere(const point3& center, double radius);

  bool hit(const ray& r, interval ray_t, hit_record& rec) const override;

 private:
  point3 center;
  double radius;
};

#endif
