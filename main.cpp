#include <iostream>
#include "color.h"
#include "vec3.h"
#include "ray.h"


color ray_color(const ray& r) {
  return color(0,0,0);
}

int main() {

  auto aspect_ratio = 16.0/9.0;
  int image_width = 400;
  int image_height = int(image_width / aspect_ratio);
  image_height = (image_height) < 1 ? 1 : image_height; 

  auto focal_length = 1.0;
  auto view_port_height = 2.0;
  auto view_port_width = aspect_ratio * ((double)image_width / image_height); 
  auto camera_center = point3(0, 0, 0);

  auto viewport_u = vec3(view_port_width, 0, 0);
  auto viewport_v = vec3(0, -view_port_height, 0);

  auto pixel_delta_u = view_port_width / image_width * viewport_u;
  auto pixel_delta_v = view_port_height / image_height * viewport_v;

  auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
  auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

  std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
  for (int row = 0; row < image_height; ++row) {
    std::clog << "\rScanlines remaining: " << (image_height - row) << ' '
              << std::flush;
    for (int col = 0; col < image_width; ++col) {
      auto pixel_center = pixel00_loc + row * pixel_delta_u + col * pixel_delta_v;
      auto ray_direction = pixel_center - camera_center;
      ray r(pixel_center, ray_direction);
      auto pixel_color = ray_color(r);
      write_color(std::cout, pixel_color);
    }
  }
  std::clog << "\rDone.                 \n";
}
