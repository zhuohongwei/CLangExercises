#include <stdio.h>

int any(char s1[], char s2[]);

main()
{
	char s1[] = "the quick brown fox jumped over the fence";
	char s2[] = "aeiou";
	char s3[] = "lz";
	printf("any(%s, %s): %d\n", s1, s2, any(s1, s2));
	printf("any(%s, %s): %d\n", s1, s3, any(s1, s3));
}

int any(char s1[], char s2[])
{
	int i, j;
	for (i = 0; s2[i] != '\0'; i++)
		for (j = 0; s1[j] != '\0'; j++)
			if (s1[j] == s2[i])
				return j;
	return -1;
}
