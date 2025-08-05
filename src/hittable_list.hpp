#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
#include <vector>
#include "ray.hpp"
#include "hittable.hpp"

class hittable_list : public hittable {
 public:
  std::vector<std::shared_ptr<hittable>> objects;

  hittable_list();
  hittable_list(std::shared_ptr<hittable> object);

  void clear();

  void add(std::shared_ptr<hittable> object);

  bool hit(const ray& r, interval ray_t, hit_record& rec) const override;
};
#endif
