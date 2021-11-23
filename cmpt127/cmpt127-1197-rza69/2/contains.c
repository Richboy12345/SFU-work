#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int a, char* b[]) {
	int c = strlen(b[1]);
	int d = strlen(b[2]);
	int contains = 0;
	for (int i = 0; i < c; i++) {
		if (b[1][i] == b[2][0]) {
			contains = 1;
			for (int j = 1; j < d; j++) {
				if (b[1][i + j] != b[2][j]) {
					contains = 0;
				}
			}
			if (contains) {
				printf("true\n");
				return 0;
			}
		}
	}
	printf("false\n");

	return 0;
}
