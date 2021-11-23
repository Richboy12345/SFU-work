#include <stdio.h>

int identical( int arr1[], int arr2[], unsigned int len ) {
	for (int i = 0; i < len; i++) {
		if (arr1[i] != arr2[i]) {
			return 0;
		}
	}
	return 1;
}
