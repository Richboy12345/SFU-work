#include <stdio.h>

int main(void) {
  int d = 0;
  int largest = 0;
  int arr[80];
  while (scanf("%d", &arr[d]) != EOF) {
	  if (arr[d] > largest) {
		  largest = arr[d];
	  }
	  d++;
  }
  for (int i = 0; i < largest; i++) {
	  for (int j = 0; j < d; j++) {
		  if(arr[j] + i >= largest) {
			  printf("#");
		  }
		  else {
			  printf(" ");
		  }
	  }
	  printf("\n");
  }
}
