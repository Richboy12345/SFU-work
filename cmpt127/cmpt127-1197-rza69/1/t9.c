#include <stdio.h>
#include <math.h>

int main() {
	int x, y, z, left, right;
	scanf("%d%d%d", &x, &y, &z);
	float slope = (float)x/(2*z);
	for (int i = z - 1; i > 0; i--) {
		left = floor((float)(slope * i));
		right = ceil((float)x - 1 -(slope * i));
		for (int j = 0; j <= right; j++) {
			if (j < left){
				printf(" ");
			}
			else if (j >= left || j <= right) {
				if (i == z - 1 || j == left || j == right) {
					printf("#");
				}
				else {
					printf(".");
				}
			}
			
		}
		printf("\n");
	}
	for (int i = 0; i < x; i++) {
		printf("#");
	}
	printf("\n");

	return 0;
}
