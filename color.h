#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color) {
  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();

  int ir = (int)(r * 255.99);
  int ig = (int)(g * 255.99);
  int ib = (int)(b * 255.99);

  out << ir << " " << ig << " " << ib << "\n"; 
}

#endif