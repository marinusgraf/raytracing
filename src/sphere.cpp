#include "sphere.hpp"
#include <memory>

sphere::sphere(const point3& center, double radius, std::shared_ptr<material> mat) : center(center), radius(std::fmax(radius, 0)), mat(mat) {}

bool sphere::hit(const ray& r, interval ray_t, hit_record& rec) const {
    vec3 oc = center - r.origin();
    double a = r.direction().length_squared();
    double h = dot(r.direction(), oc);
    double c = oc.length_squared() - radius * radius;
    double discriminant = h * h - a * c;
    if (discriminant < 0) {
        return false;
    }
    double sqrt_discriminant = std::sqrt(discriminant);
    double root = (h - sqrt_discriminant) / a;
    if (!ray_t.surrounds(root)) {
        root = (h + sqrt_discriminant) / a;
    }
    if (!ray_t.surrounds(root)) {
        return false;
    }
    rec.t = root;
    rec.p = r.at(rec.t);
    rec.mat = mat;
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    return true;
}
