#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "intarr.h"

int main() {
  int len = 10;
  bool ok = true;

  //test create
  intarr_t* arr = intarr_create(len);
  if (arr != NULL) {
    printf("Task 1 - create OK\n");
  }

  //runs if create was successful
  if (arr != NULL) {

    //task 2
    for (int i = 0; i < len; i++) {
      if (intarr_set(arr, i, i) != INTARR_OK) {
        ok = false;
      }
    }
    if (ok) {
      printf("Task 2 - set OK\n");
    }
    ok = true;
    for (int i = 0; i < len; i++) {
      int val;
      if (intarr_get(arr, i, &val) != INTARR_OK) {
        ok = false;
      }
    }
    if (ok) {
      printf("Task 2 - get OK\n");
    }
    ok = true;

    //task 3
    intarr_t* cpy = intarr_copy(arr);
    if (cpy == NULL) {
      ok = false;
    }
    if (ok) {
      printf("Task 3 OK\n");
    }
    ok = true;

    //tests destroy
    intarr_destroy(cpy);
    printf("Task 1 - destroy OK\n");

    //task 4
    intarr_t* srt = intarr_create(len);
    for (int i = 0; i < len; i++) {
      if (intarr_set(srt, i, len - i) != INTARR_OK) {
        ok = false;
      }
    }
    if (intarr_sort(srt) != INTARR_OK) {
      ok = false;
    }
    if (ok) {
      printf("Task 4 OK\n");
    }

    intarr_destroy(srt);
    ok = true;

    //task 5
    int ind = -1;
    int target = 1; //change this to whatever
    if (intarr_find(arr, target, &ind) == INTARR_BADARRAY) {
      ok = false;
    }
    if (ind != -1 && ok) {
      int val;
      intarr_get(arr, ind, &val);
      if (val != target) {
        ok = false;
      }
    }
    if (ok) {
      printf("Task 5 OK\n");
    }
    ok = true;

    //task 6 and 7
    int val;
    if (intarr_pop(arr, &val) != INTARR_OK) {
      ok = false;
    }
    if (ok) {
      if (intarr_push(arr, val) != INTARR_OK) {
        ok = false;
      }
    }
    if (ok) {
      printf("Task 6 and 7 OK\n");
    }
    ok = true;

    //task 8
    int first = 0.3 * len;
    int last = 0.7 * len;
    int cpylen = last - first;
    intarr_t* cpysub = intarr_copy_subarray(arr, first, last);
    for (int i = 0; i < cpylen; i++) {
      int valorig, valcopy;
      if (intarr_get(arr, i + first, &valorig) != INTARR_OK) {
        ok = false;
      }
      if (intarr_get(cpysub, i, &valcopy) != INTARR_OK) {
        ok = false;
      }
      if (valorig != valcopy) {
        ok = false;
      }
    }

    if (ok) {
      printf("Task 8 OK\n");
    }
    intarr_destroy(cpysub);
  }
  intarr_destroy(arr);
  return 0;
}

