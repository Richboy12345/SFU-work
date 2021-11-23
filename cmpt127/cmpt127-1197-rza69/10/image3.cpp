#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "image3.hpp"

using namespace std;

Image::Image() {
  cols = 0;
  rows = 0;
  pixels = NULL;
}

Image::~Image() {
  if (pixels) {
    for (int i = 0; i < rows; i++) {
      if (pixels[i]) {
        delete[] pixels[i];
      }
    }
    delete[] pixels;
  }
}

int Image::resize(unsigned int width, unsigned int height, uint8_t fillcolour) {
  if (pixels) {
    for (int i = 0; i < rows; i++) {
      delete[] pixels[i];
    }
    delete[] pixels;
  }
  pixels = new uint8_t*[height];
  if (!pixels) {
    return 1;
  }
  cols = width;
  rows = height;
  for (int i = 0; i < rows; i++) {
    pixels[i] = new uint8_t[width];
    if (!pixels[i]) {
      return 1;
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      pixels[i][j] = fillcolour;
    }
  }
  return 0;
}

int Image::set_pixel(unsigned int x, unsigned int y, uint8_t colour) {
  if (x >= cols || y >= rows) {
    return 1;
  }
  pixels[y][x] = colour;
  return 0;
}

int Image::get_pixel(unsigned int x, unsigned int y, uint8_t* colourp) {
  if (x >= cols || y >= rows || !colourp) {
    return 1;
  }
  *colourp = pixels[y][x];
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
  fprintf(file, "%d, %d, ", cols, rows);
  if (cols && rows) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        fprintf(file, "%d, ", pixels[i][j]);
      }
    }
  }
  fclose(file);
  return 0;
}

int Image::load(const char* filename) {
  if (!filename) {
    return 1;
  }
  cout << "filename " << filename << endl;
  FILE* file = fopen(filename, "r+");
  if (!file) {
    return 1;
  }
  cout << "file" << endl;
  while (fscanf(file, "%d", &cols) != 1) {
    fseek(file, 1, SEEK_CUR);
  }
  while (fscanf(file, "%d", &rows) != 1) {
    fseek(file, 1, SEEK_CUR);
  }
  cout << cols << rows;
  if (pixels) {
    for (int i = 0; i < rows; i++) {
      delete[] pixels[i];
    }
    delete[] pixels;
  }
  pixels = new uint8_t*[rows];
  if (!pixels) {
    return 1;
  }
  for (int i = 0; i < rows; i++) {
    pixels[i] = new uint8_t[cols];
    if (!pixels[i]) {
      return 1;
    }
  }
  int size = rows * cols;
  if (size) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        int temp;
        while (fscanf(file, "%d", &temp) != 1) {
          fseek(file, 1, SEEK_CUR);
        }
        pixels[i][j] = temp;
      }
    }
  }
  fclose(file);
  return 0;
}
