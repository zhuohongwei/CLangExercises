#include <stdio.h>

#define MAX_BUFFER_SIZE 5000

void expand(char s1[], char s2[]);

main()
{
	char s1[] = "a-aA-Za-z0-9-";
	char s2[MAX_BUFFER_SIZE];
	expand(s1, s2);
	printf("%s expands into %s\n", s1, s2);
}



void expand(char s1[], char s2[])
{
	int c, d, i, j, k;
	i = 0;
	k = 0;
	while ((c = s1[i++]) != '\0' && k < MAX_BUFFER_SIZE-1) {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
			j = i;
			d = s1[j++];
			if (d != '\0' && d == '-') {
				d = s1[j];
				if (d != '\0' && ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z') || (d >= '0' && d <= '9')) ) {
					if (d > c) {
						int n;
						for (n = c; n <= d; n++) {
							s2[k++] = n;
						}
						i = j+1;
						continue;
					}
				}
			}
		}
		s2[k++] = c;
	}
	s2[k] = '\0';
}