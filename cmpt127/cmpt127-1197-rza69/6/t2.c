#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intarr.h"

/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.

  Make sure you validate the parameters before you use them.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename ) {
  if (ia == NULL || ia->data == NULL || filename == NULL) {
    return 1;
  }
  FILE* file = fopen(filename, "w+");
  fprintf(file, "%s", "[ ");
  for (int i = 0; i < ia->len; i++) {
    fprintf(file, "%d", ia->data[i]);
    if (i < ia->len-1) {
      fprintf(file, "%s", ", ");
    }
  }
  fprintf(file, "%s", " ]");
  fclose(file);
  return 0;

}


/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_json(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.

  Make sure you validate the parameter before you use it.
*/
intarr_t* intarr_load_json( const char* filename ) {
  if (filename == NULL) {
    return NULL;
  }
  FILE* file = fopen(filename, "r+");
  if (file == NULL) {
    return NULL;
  }
  int len = 0;
  char c;
  intarr_t* arr = malloc(sizeof(intarr_t));
  while (!feof(file)) {
    c = getc(file);
    if (c == ',') {
      len++;
    }
  }
  fseek(file, 0, SEEK_SET);
  if (len == 0) {
    arr->len = len;
    arr->data = NULL;
    return arr;
  }
  len++;
  arr->len = len;
  arr->data = malloc(len * sizeof(int));
  for (int i = 0; i < len; i++) {
    int j;
    while (fscanf(file, "%d", &j) != 1) {
      fseek(file, 1, SEEK_CUR);
    }
    arr->data[i] = j;
  }
  fseek(file,0,SEEK_END);
  fclose(file);
  return arr;
}
