#include "camera.hpp"

void camera::render(const hittable& world) {
  initialize();

  std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
  for (int row = 0; row < image_height; ++row) {
    std::clog << "\rScanlines remaining: " << (image_height - row) << ' ' << std::flush;
    for (int col = 0; col < image_width; ++col) {
      color pixel_color = color(0, 0, 0);
      for (int i = 0; i < samples_per_pixel; i++) {
        ray r = get_ray(row, col);
        pixel_color += ray_color(r, max_depth, world);
      }
      write_color(std::cout, pixel_color * pixel_scale_factor);
    }
  }
  std::clog << "\rDone.                 \n";
}

void camera::initialize() {
  image_height = int(image_width / aspect_ratio);
  image_height = (image_height) < 1 ? 1 : image_height;
  center = point3(0, 0, 0);
  pixel_scale_factor = 1.0 / samples_per_pixel;

  double focal_length = 1.0;
  double view_port_height = 2.0;
  double view_port_width = view_port_height * (double(image_width) / image_height);

  vec3 viewport_u = vec3(view_port_width, 0, 0);
  vec3 viewport_v = vec3(0, -view_port_height, 0);

  pixel_delta_u = viewport_u / image_width;
  pixel_delta_v = viewport_v / image_height;

  point3 viewport_upper_left = center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
  pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
}

color camera::ray_color(const ray& r, int depth, const hittable& world) const {
  if (depth == 0) {
    return color(0, 0, 0);
  }
  hit_record rec;
  if (world.hit(r, interval(0.001, infinity), rec)) {
    vec3 direction = rec.normal + random_unit_vector();
    return 0.5 * ray_color(ray(rec.p, direction), depth - 1, world);
  }
  vec3 unit_r = unit_vector(r.direction());
  double a = 0.5 * (unit_r.y() + 1.0);
  return (1 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

ray camera::get_ray(int row, int col) const {
  vec3 offset = rand_sample_unit_square();
  vec3 direction = pixel00_loc + (row + offset.y()) * pixel_delta_v + (col + offset.x()) * pixel_delta_u;
  return ray(center, direction);
}

vec3 camera::rand_sample_unit_square() const { return vec3(random_double() - 0.5, random_double() - 0.5, 0); }
