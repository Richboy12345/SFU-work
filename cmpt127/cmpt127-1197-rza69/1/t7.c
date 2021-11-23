#include <stdio.h>

int main() {
	int d;
	int i = 0;
	while (i != EOF) {
		i = scanf("%d", &d);
		if (i == EOF) {
			break;
		}
		else {
			for (int j = 0; j < d; j++) {
				printf("#");
			}
			printf("\n");
		}

	}

	return 0;
}
