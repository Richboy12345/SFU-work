/*
 * imgops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
  PART 0: OPERATIONS ON A PIXEL 
*/

// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 


/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/


/* TASK 1 - Easy functions to get started */

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  memset(array, 0, rows * cols * sizeof(array[0]));
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  uint8_t* copy = malloc((cols * rows) * sizeof(array[0]));
  for (int i = 0; i < cols * rows; i++) {
    copy[i] = array[i];
  }
  return copy;
}

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
  uint8_t darkest = array[0];
  for (int i = 0; i < cols * rows; i++) {
    if (array[i] < darkest) {
      darkest = array[i];
    }
  }
  return darkest;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
  uint8_t lightest = array[0];
  for (int i = 0; i < cols * rows; i++) {
    if (array[i] > lightest) {
      lightest = array[i];
    }
  }
  return lightest;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (get_pixel(array, cols, rows, j, i) == pre_color) {
        set_pixel(array, cols, rows, j, i, post_color);
      }
    }
  }
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
  uint8_t temp = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols / 2; j++) {
      temp = get_pixel(array, cols, rows, j, i);
      set_pixel(array, cols, rows, j, i, get_pixel(array, cols, rows, cols - 1 - j, i));
      set_pixel(array, cols, rows, cols - 1 - j, i, temp);
    }
  }
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
  uint8_t temp = 0;
  for (int i = 0; i < rows / 2; i++) {
    for (int j = 0; j < cols; j++) {
      temp = get_pixel(array, cols, rows, j, i);
      set_pixel(array, cols, rows, j, i, get_pixel(array, cols, rows, j, rows - 1 - i));
      set_pixel(array, cols, rows, j, rows - 1 - i, temp);
    }
  }
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
  
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (get_pixel(array, cols, rows, j, i) == color) {
        *x = j;
	*y = i;
	return 1;
      }
    }
  }
  return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      set_pixel(array, cols, rows, j, i, 255 - get_pixel(array, cols, rows, j, i));
    }
  }
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Resulting values are rounded to the nearest
// integer (0.5 rounded up) and any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (scale_factor * get_pixel(array, cols, rows, j, i) > 255) {
        set_pixel(array, cols, rows, j, i, 255);
      }
      else {
        set_pixel(array, cols, rows, j, i, round(scale_factor * get_pixel(array, cols, rows, j, i)));
      }
    }
  }
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max().
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
  int small = min(array, cols, rows);
  for (int i = 0; i < cols * rows; i++) {
    array[i] -= small;
  }
  int big = max(array, cols, rows);
  double scale = 1;
  if (big != 0) {
    scale = 255.00/big;
  }
  scale_brightness(array, cols, rows, scale);
}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image
// has an odd number of columns, ignore its rightmost column. If the
// original image has an odd number of rows, ignore its bottom row.
// The value of a pixel at (p,q) in the new image is the average of
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in
// the original image.
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  uint8_t* arr = malloc(cols * rows / 4 * sizeof(uint8_t));
  if (arr != NULL) {
    for (int i = 0; i < rows / 2; i++) {
      for (int j = 0; j < cols / 2; j++) {
        set_pixel(arr, floor(cols/2), floor(rows/2), j, i, round((float)(get_pixel(array, cols, rows, 2 * j, 2 * i) + 
								  	 get_pixel(array, cols, rows, 2 * j + 1, 2 * i) + 
								 	 get_pixel(array, cols, rows, 2 * j, 2 * i + 1) + 
								 	 get_pixel(array, cols, rows, 2 * j + 1, 2 * i + 1)) / 4));
      }
    }
  }
  return arr;
}




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The rectangle edges of a rectangular region are aligned with the x,y axes. 
  
  The region includes all the columns from [left, right-1] inclusive,
  and all the rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, you can use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must remained unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
  if (left != right && top != bottom) {
    for (int i = top; i < bottom; i++) {
      for (int j = left; j < right; j++) {
        set_pixel(array, cols, rows, j, i, color);
      }
    }
  }
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
  unsigned long int sum = 0;
  if (left != right && top != bottom) {
    for (int i = top; i < bottom; i++) {
      for (int j = left; j < right; j++) {
        sum += get_pixel(array, cols, rows, j, i);
      }
    }
  }
  return sum;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
  uint8_t cpcols = right - left;
  uint8_t cprows = bottom - top;
  if (cprows == 0 || cpcols == 0) {
    return NULL;
  }
  uint8_t* arr = malloc(cpcols * cprows * sizeof(uint8_t));
  if (arr != NULL && left != right && top != bottom) {
    for (int i = top; i < bottom; i++) {
      for (int j = left; j < right; j++) {
	arr[(i - top) * cpcols + (j - left)] = get_pixel(array, cols, rows, j, i);
      }
    }
  }
  return arr;
}


