#include <stdio.h>
#include <math.h>

int main() {
	double d = 0;
	int i = 0;
	while (i != EOF) {
		i = scanf("%lf", &d);
		if (i == EOF) {
			printf("Done.\n");
			break;
		}
		printf("%d ", (int)floor(d));
    	printf("%d ", (int)round(d));
    	printf("%d", (int)ceil(d));
    	printf("\n");

	}

	return 0;
}
