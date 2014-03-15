#include <stdio.h>

#define MAX_WORD_LENGTH 100

main()
{
	int c, word_length, i, j;
	int lengths[MAX_WORD_LENGTH];
	for (i = 0; i < MAX_WORD_LENGTH; i++) {
		lengths[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (word_length > 0) {
				++lengths[word_length];
			}
			word_length = 0;
		} else {
			word_length++;

		}
	}

	//print the histogram
	for (i = 0; i < MAX_WORD_LENGTH; i++) {
			printf("%4d|",i);
			for (j = lengths[i]; j > 0; j--) {
				putchar('-');
			}
			putchar('\n');
	}
}