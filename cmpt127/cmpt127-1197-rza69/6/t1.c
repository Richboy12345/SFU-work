#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intarr.h"

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.

  Make sure you validate the parameters before you use them.
*/
int intarr_save_binary( intarr_t* ia, const char* filename ) {
  if (ia == NULL || filename == NULL) {
    return 1;
  }
  FILE* file = fopen(filename, "w");
  int written = fwrite(ia->data, sizeof(int), ia->len, file);
  fclose(file);
  if (written != ia->len) {
    return 1;
  }
  return 0;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.

  Make sure you validate the parameter before you use it.
*/
intarr_t* intarr_load_binary( const char* filename ) {
  if (filename == NULL) {
    return NULL;
  }
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }
  intarr_t* arr = malloc(sizeof(intarr_t));
  if (arr == NULL) {
    return NULL;
  }
  fseek(file, 0, SEEK_END);
  int len = ftell(file)/sizeof(int);
  fseek(file, 0, SEEK_SET);
  arr->len = len;
  arr->data = malloc(len * sizeof(int));
  if (arr->data == NULL) {
    return NULL;
  }
  int read = fread(arr->data, sizeof(int), len, file);
  fclose(file);
  if (read == arr->len) {
    return arr;
  }
  return NULL;
}
