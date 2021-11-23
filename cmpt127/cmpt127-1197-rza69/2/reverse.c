#include <stdio.h>
#include <math.h>

void reverse(int arr[], unsigned int len) {
	int tmp, swap;
	//swaps front with back until it reaches middle
	for (int i = 0; i < floor(len/2); i++) {
		swap = len - 1 - i;
		tmp = arr[i];
		arr[i] = arr[swap];
		arr[swap] = tmp;
	}
}
