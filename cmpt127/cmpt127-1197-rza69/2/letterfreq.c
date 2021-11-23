#include <stdio.h>
#include <string.h>

//counts frequency of letters from input
int main() {
	int c = 0;
	int letters = 0;
	float arr[123];
	float freq;
        //initializes array with all 0s
	for (int i = 0; i < 123; i++) {
		arr[i] = 0;
	}
	//increments the value at the index of the ascii value of each letter
	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z') {
			arr[c]++;
			letters++;
		}
		if (c >= 'A' && c <= 'Z') {
			arr[c]++;
			letters++;
		}
	}
	//adds lowercase and capitals together, then prints all non zero values
	for (int i = 65; i < 91; i++) {
		arr[i] += arr[i + 32];
		if (arr[i] != 0) {
			freq = (float)((arr[i])/letters);
			printf("%c %.4f\n", (i + 32), freq);
		}
	}

	return 0;
}
