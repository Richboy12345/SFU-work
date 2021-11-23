#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intarr.h"

int main () {
  int len = 10;
  intarr_t* arr = intarr_create(len);
  for (int i = 0; i < len; i++) {
    intarr_set(arr, i, i);
  }
  intarr_save_json(arr, "testfile");
}
