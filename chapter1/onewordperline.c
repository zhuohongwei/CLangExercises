#include <stdio.h>

main()
{
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar('\n');
		} else {
			putchar(c);
		}
	}
}

