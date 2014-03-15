#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int getsingleline(char s[], int limit);
int gettrimmedline(char s[], int lastindex);

main()
{
	int len = 0;
	char line[MAX_LINE_LENGTH];
	while ((len = getsingleline(line, MAX_LINE_LENGTH)) > 0) {
		len = gettrimmedline(line, len);
		printf("%s\n", line);
	}
}

int getsingleline(char s[], int limit)
{
	int c;
	int j;
	int i = 0;
	
	while (i < limit-1 && (c = getchar()) !=  EOF && c != '\n') {
		s[i++] = c;
	}

	if (c == '\n') {
		s[i++] = c;
	}

	s[i] = '\0';

	return i;
}

int gettrimmedline(char s[], int lastindex)
{
	int c;
	int nnewline = 0;
	while ((c = s[lastindex]) == '\0' || c == '\n' || c == ' ' || c == '\t') {
		if (c == '\n') {
			nnewline++;
		}
		s[lastindex--] = '\0';
	}

	while (nnewline > 0) {
		s[++lastindex] = '\n';
		nnewline--;
	}

	s[++lastindex] = '\0';
	return lastindex;
}