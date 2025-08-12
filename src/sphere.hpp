#ifndef SPHERE_H
#define SPHERE_H
#include <memory>
#include "hittable.hpp"
#include "interval.hpp"
#include "vec3.hpp"
#include "ray.hpp"

class sphere : public hittable {
   public:
    sphere(const point3& center, double radius, std::shared_ptr<material> mat);

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override;

   private:
    point3 center;
    double radius;
    std::shared_ptr<material> mat;
};

#endif
