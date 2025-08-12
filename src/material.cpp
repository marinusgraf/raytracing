#include "material.hpp"
#include "vec3.hpp"

material::~material() = default;

bool material::scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const { return false; }

lambertian::lambertian(const color& albedo) : albedo(albedo) {}

bool lambertian::scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const {
    vec3 scatter_direction = rec.normal + random_unit_vector();
    if (scatter_direction.near_zero()) {
        scatter_direction = rec.normal;
    }
    scattered = ray(rec.p, scatter_direction);
    attenuation = albedo;
    return true;
}

metal::metal(const color& albedo, double fuzz) : albedo(albedo), fuzz(fuzz) {}

bool metal::scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const {
    vec3 scatter_direction = reflect(r_in.direction(), rec.normal);
    scatter_direction = unit_vector(scatter_direction) + (fuzz * random_unit_vector());
    scattered = ray(rec.p, scatter_direction);
    attenuation = albedo;
    return dot(scatter_direction, rec.normal) > 0;
}

dielectric::dielectric(double refrac_index) : refrac_index(refrac_index) {}

bool dielectric::scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const {
    double refrac_index_ratio = refrac_index;
    if (rec.front_face) {
        refrac_index_ratio = 1.0 / refrac_index;
    }
    scattered = ray(rec.p, refract(unit_vector(r_in.direction()), rec.normal, refrac_index_ratio));
    attenuation = color(1.0, 1.0, 1.0);
    return true;
}
