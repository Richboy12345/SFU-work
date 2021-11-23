#include <stdio.h>

int main() {
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (i == 0 || i == y - 1 || j == 0 || j == x - 1) {
				printf("#");
			}
			else {
				printf(".");
			}
		}
		printf("\n");
	}

	return 0;
}
