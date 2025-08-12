#ifndef MATERIAL_H
#define MATERIAL_H
#include "hittable.hpp"
#include "color.hpp"

class material {
   public:
    virtual ~material();

    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const;
};

class lambertian : public material {
   public:
    lambertian(const color& albedo);

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

   private:
    color albedo;
};

class metal : public material {
   public:
    metal(const color& albedo, double fuzz);

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

   private:
    color albedo;
    double fuzz;
};

class dielectric : public material {
   public:
    dielectric(double refrac_index);

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

   private:
    double refrac_index;
};
#endif
