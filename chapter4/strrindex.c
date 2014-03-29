#include <stdio.h>

int strrindex(char s[], char t[]);

main()
{
	char s[] = "this is a long string";
	char t1[] = "is";
	char t2[] = "long";
	char t3[] = "range";

	printf("index of string %s in %s is %d\n", t1, s, strrindex(s, t1));
	printf("index of string %s in %s is %d\n", t2, s, strrindex(s, t2));
	printf("index of string %s in %s is %d\n", t3, s, strrindex(s, t3));
}

int strrindex(char s[], char t[])
{
	char *u, *v, *orig;
	int n;

	orig = s;
	n = -1;
	while (*s != '\0') {
		if (*s == *t) {
			u = s;
			v = t;
			while (*u != '\0' && *v != '\0' && *u == *v) {
				u++; v++;
			}
			if (*v == '\0') {
				n = s - orig;
			} 
		}
		s++;
	}

	return n;
}
