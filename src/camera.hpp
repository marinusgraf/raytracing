#include "color.hpp"
#include "vec3.hpp"
#include "hittable.hpp"
#include "ray.hpp"
#include "material.hpp"

class camera {
   public:
    int image_width = 100;
    double aspect_ratio = 1.0;
    int samples_per_pixel = 10;
    int max_depth;

    void render(const hittable& world);

   private:
    int image_height;
    point3 center;
    point3 pixel00_loc;
    vec3 pixel_delta_v;
    vec3 pixel_delta_u;
    double pixel_scale_factor;

    void initialize();

    color ray_color(const ray& r, int depth, const hittable& world) const;

    ray get_ray(int row, int col) const;

    vec3 rand_sample_unit_square() const;
};
