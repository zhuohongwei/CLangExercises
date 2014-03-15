#include <stdio.h>

#define MAX_LINE_LENGTH 1000

void reverse(char *s);
int getoneline(char *s, int length);

main()
{
	int len = 0;
	char line[MAX_LINE_LENGTH];
	while ((len = getoneline(line, MAX_LINE_LENGTH)) > 0) {
		reverse(line);
		printf("%s", line);
	}
}

void reverse(char *s)
{
	int temp;
	char *t = s;

	while (*s != '\0') {
		s++;
	}

	s--;
	while (t < s) {
		temp = *t;
		*t = *s;
		*s = temp;
		t++;
		s--;
	}
}

int getoneline(char *s, int length)
{
	int i, c;
	
	i = 0;
	while (i < length-1 && (c = getchar()) != EOF && c != '\n') {
		*(s+i) = c;
		i++;
	}

	if (c == '\n') {
		*(s+i) = c;
		i++;
	}

	*(s+i) = '\0';

	return i;
}