#include <stdio.h>

void squeeze1(char s1[], char s2[]);
void squeeze2(char *s1, char *s2);

main()
{
	char s1[] = "the quick brown fox jump over the fence";
	char s2[] = "aeiou";  
	squeeze2(s1, s2);
	printf(s1);
}

void squeeze1(char s1[], char s2[])
{
	int c, i, j, k;
	i = 0;
	while ((c = s2[i++]) != '\0') {
		for (j = k = 0; s1[j] != '\0'; j++) {
			if (s1[j] != c) {
				s1[k++] = s1[j];
			}
		}
		s1[k] = '\0';
	}
}

void squeeze2(char *s1, char *s2)
{
	int c;
	char *p1, *p2;
	while ((c = *s2++) != '\0') {
		for (p1 = p2 = s1; *p1 != '\0'; p1++) {
			if (*p1 != c) {
				*p2++ = *p1;
			}
		}
		*p2 = '\0';
	}
}
