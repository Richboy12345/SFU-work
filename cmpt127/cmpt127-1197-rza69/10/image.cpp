#include <iostream>

#include "image.hpp"

using namespace std;

Image::Image() {
  cols = 0;
  rows = 0;
  pixels = NULL;
}

Image::~Image() {
  if (pixels) {
    delete[] pixels;
  }
}

int Image::resize(unsigned int width, unsigned int height, uint8_t fillcolour) {
  if (pixels) {
    delete[] pixels;
  }
  int size = width * height;
  pixels = new uint8_t[size];
  if (!pixels) {
    return 1;
  }
  for (int i = 0; i < size; i++) {
    pixels[i] = fillcolour;
  }
  cols = width;
  rows = height;
  return 0;
}

int Image::set_pixel(unsigned int x, unsigned int y, uint8_t colour) {
  if (x >= cols || y >= rows || !colour) {
    return 1;
  }
  pixels[y * cols + x] = colour;
  return 0;
}

int Image::get_pixel(unsigned int x, unsigned int y, uint8_t* colourp) {
  if (x >= cols || y >= rows || !colourp) {
    return 1;
  }
  *colourp = pixels[y * cols + x];
  return 0;
}
