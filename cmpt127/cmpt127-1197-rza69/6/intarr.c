/* 
 * intarr.c
 *
 * Provides a bounds-checked, resizable array of integers with
 * random-access and stack interfaces, and several utility functions
 * that operate on them.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "intarr.h"

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len ) {
  intarr_t* arr = malloc(sizeof(intarr_t));
  if (arr == NULL) {
    return NULL;
  }
  arr->len = len;
  arr->data = malloc(len * sizeof(int));
  if (arr->data == NULL) {
    return NULL;
  }
  return arr;
}

// Frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ) {
  if (ia->data != NULL && ia != NULL) {
    free(ia);
  }
}

/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, unsigned int index, int val ) {
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }
  if (index < ia->len) {
    ia->data[index] = val;
    return INTARR_OK;
  }
  else {
    return INTARR_BADINDEX;
  }
}

// If index is valid and val is non-null, set *val to ia->data[index] and return
// INTARR_OK. Otherwise do not modify *val and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, unsigned int index, int* val ) {
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }
  if (index < ia->len && val != NULL) {
    *val = ia->data[index];
    return INTARR_OK;
  }
  else {
    return INTARR_BADINDEX;
  }
}

/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer. 
intarr_t* intarr_copy( const intarr_t* ia ) {
  intarr_t* arr = malloc(sizeof(intarr_t));
  if (ia == NULL) {
    return NULL;
  }
  arr->len = ia->len;
  arr->data = malloc(arr->len * sizeof(int));
  if (arr->data == NULL) {
    return NULL;
  }
  memcpy(arr->data, ia->data, arr->len);
  return arr;
}

/* LAB 5 TASK 4 */

// Sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia ) {
  if (ia==NULL) {
    return INTARR_BADARRAY;
  }
  else {
    int min, ind, tmp;
    for (int i = 0; i < ia->len; i++) {
      min = ia->data[i];
      for (int j = i; j < ia->len; j++) {
        if (ia->data[j] <= min) {
          min = ia->data[j];
          ind = j;
        }
      }
      tmp=ia->data[i];
      ia->data[i]=min;
      ia->data[ind]=tmp;
    }
    return INTARR_OK;
  }
}

/* LAB 5 TASK 5 */

// Find the first occurrence of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ) {
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }
  for (int j = 0; j < ia->len; j++) {
    if (ia->data[j] == target && i != NULL) {
      *i = j;
      return INTARR_OK;
    }
  }
  return INTARR_NOTFOUND;
}

/* LAB 5 TASK 6 */

// HINT: First, do TASK 7, since you will need to resize your array
//       by +1 in order to successfully push val.
// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val ) {
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }
  int ind = ia->len;
  intarr_resize(ia, ia->len + 1);
  ia->data[ind] = val;
  if (ia->data[ind] == val) {
    return INTARR_OK;
  }
  return INTARR_BADALLOC;
}

// HINT: You will need to decrement len so that it always represents
//       the number of int's stored in the array data.
// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i ) {
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }
  if (ia->len > 0) {
    int ind = ia->len - 1;
    int rem = ia->data[ind];
    intarr_resize(ia, ia->len - 1);
    if (i != NULL) {
      *i = rem;
    }
    return INTARR_OK;
  }
  return INTARR_BADINDEX;
}

/* LAB 5 TASK 7 */

// HINT: Do this task before doing TASK 6.
// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. 
// If newlen is greater than the original array length, the values 
// of the new integers will be undefined 
// (see https://en.cppreference.com/w/c/memory/realloc). 
// If the allocation is successful, return INTARR_OK, otherwise 
// return INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ) {
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }
  if (newlen >= 0) {
    int* arr = realloc(ia->data,sizeof(int)*newlen);
    ia->len = newlen;
    ia->data = arr;
    return INTARR_OK;
  }
  return INTARR_BADALLOC;
}

/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index 'first' to index 'last'
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, 'first' or 'last' are out of bounds, 
// 'last' < 'first', or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, unsigned int first, unsigned int last ) {
  if (ia  == NULL || last < first || first >= ia->len || last >= ia->len) {
    return NULL;
  }
  int len = last - first + 1;
  intarr_t* arr = intarr_create(len);
  if (arr->data == NULL || arr == NULL) {
    return NULL;
  }
  for (int i = 0; i < len; i++) {
    arr->data[i] = ia->data[i + first];
  }
  return arr;
}

