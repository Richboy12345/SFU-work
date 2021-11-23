#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "image2.hpp"

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
  pixels = NULL;
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
  if (x > cols || y > rows) {
    return 1;
  }
  pixels[y * cols + x] = colour;
  return 0;
}

int Image::get_pixel(unsigned int x, unsigned int y, uint8_t* colourp) {
  if (x > cols || y > rows) {
    return 1;
  }
  *colourp = pixels[y * cols + x];
  return 0;
}

int Image::save(const char* filename) {
  if (!filename) {
    return 1;
  }
  FILE* file = fopen(filename, "w+");
  if (!file) {
    return 1;
  }
  int size = cols * rows;
  fprintf(file, "%d, %d, ", cols, rows);
  if (size) {
    for (int i = 0; i < size; i++) {
      fprintf(file, "%d, ", pixels[i]);
    }
  }
  fclose(file);
  return 0;
}

int Image::load(const char* filename) {
  if (!filename) {
    return 1;
  }
  FILE* file = fopen(filename, "r+");
  if (!file) {
    return 1;
  }
  while (fscanf(file, "%d", &cols) != 1) {
    fseek(file, 1, SEEK_CUR);
  }
  while (fscanf(file, "%d", &rows) != 1) {
    fseek(file, 1, SEEK_CUR);
  }
  int size = cols * rows;
  pixels = new uint8_t[size];
  for (int i = 0; i < size; i++) {
    int temp;
    while (fscanf(file, "%d", &temp) != 1) {
      fseek(file, 1, SEEK_CUR);
    }
    pixels[i] = temp;
  }
  fclose(file);
  return 0;
}
