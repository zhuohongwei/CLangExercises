#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int getsingleline(char s[], int limit);

main()
{
	int len = 0;
	char line[MAX_LINE_LENGTH];
	while ((len = getsingleline(line, MAX_LINE_LENGTH)) > 0) {
		if (len > 80) {
			printf("%s\n", line);
		}
	}
}

int getsingleline(char s[], int limit)
{
	int c;
	int i = 0;
	
	while(i < limit-1 && (c = getchar()) !=  EOF && c != '\n') {
		s[i++] = c;
	}

	if (c == '\n') {
		s[i++] = c;
	}

	s[i] = '\0';
	return i;
}