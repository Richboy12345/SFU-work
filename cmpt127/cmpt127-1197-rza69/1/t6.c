#include <stdio.h>
#include <math.h>

int main() {
	double d;
	double smallest = 0;
	double largest = 0;
	double average = 0;
	int numnums = 0;
	int i = 0;
	while (i != EOF) {
		i = scanf("%lf", &d);
		if (i == EOF) {
			printf("%.2f ", (float)smallest);
			printf("%.2f ", (float)largest);
			printf("%.2f\n", (float)average/numnums);
			break;
		}
		else {
			numnums++;
		}
		if (numnums == 1) {
			smallest = d;
			largest = d;
		}
		else {
			if (d < smallest) {
				smallest = d;
			}
			if (d > largest) {
				largest = d;
			}
		}
		average += d;
		

	}

	return 0;
}
