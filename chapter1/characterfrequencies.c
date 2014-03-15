#include <stdio.h>

#define MAX_CHAR_VALUE 500

main()
{
	int c, i, j;
	int nchar[MAX_CHAR_VALUE];

	for (i = 0; i < MAX_CHAR_VALUE; i++) {
		nchar[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		++nchar[c]; 
	}

	for (i = 0; i < MAX_CHAR_VALUE; i++) {
		if (nchar[i] == 0) {
			continue;
		}

		printf("%c|", (char)i);
		for (j = 0; j < nchar[i]; j++) {
			putchar('-');
		}
		putchar('\n');
	}
}