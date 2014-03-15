#include <stdio.h>

main()
{
	int c;
	int nwhitespace = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t' || c == ' ' || c == '\n') {
			++nwhitespace;
		}
	}	
	printf("number of space characters: %d", nwhitespace);
}
