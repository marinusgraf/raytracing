#include "color.hpp"

void write_color(std::ostream& out, const color& pixel_color) {
  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();

  r = linear_to_gamma(r);
  g = linear_to_gamma(g);
  b = linear_to_gamma(b);

  static const interval intensity(0.0, 0.999);
  int ir = int(intensity.clamp(r) * 256);
  int ig = int(intensity.clamp(g) * 256);
  int ib = int(intensity.clamp(b) * 256);

  out << ir << " " << ig << " " << ib << "\n";
}
