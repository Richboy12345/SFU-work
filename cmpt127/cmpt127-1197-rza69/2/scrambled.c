#include <stdio.h>
#include <math.h>

//checks to see if an array is a scrambled version of another array of the same length
int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len ) {
	int a = 1;
	int b = 1;
	int c = 0;
	int d = 0;
	//gets both the sum and the product of all the non 0 numbers in the array
	for (int i = 0; i < len; i++) {
		if (arr1[i] != 0) {
			a = a * arr1[i];
		}
		if (arr2[i] != 0){
			b = b * arr2[i];
		}
		c += arr1[i];
		d += arr2[i];

	}
	//if sum and product are the same, returns true
	if (a == b && c == d) {
		return 1;
	}
	return 0;
}
