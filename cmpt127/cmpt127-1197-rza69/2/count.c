#include <stdio.h>
#include <string.h>

int main(void) {
	unsigned long int charcount = 0;
	unsigned long int wordcount = 0;
	unsigned long int linecount = 0;
	int lastWasChar = 0;
	int c;
	int i = 0;
	while ((c = getchar()) != EOF) {
		charcount++;
		if (c == '\'' || (c >= 'a' && c <= 'z') || (c >= 'A' && c < 'Z')) {
			lastWasChar = 1;
		}
		if (!(c == '\'' || (c >= 'a' && c <= 'z') || (c >= 'A' && c < 'Z')) && lastWasChar == 1) {
			wordcount++;
			lastWasChar = 0;
		}
		if (c == '\n') {
			linecount++;
		}
	}
	if (charcount > 0) {
		if (lastWasChar == 1) {
			wordcount++;
		}
	}

	printf("%lu %lu %lu\n", charcount, wordcount, linecount);
}

