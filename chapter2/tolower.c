#include <stdio.h>

void strtolower(char *s);

main()
{
	char s[] = "The Quick Brown Fox Jumped Over The Fence";
	strtolower(s);
	printf("%s", s);
}

void strtolower(char *s)
{
	for (; *s != '\0'; *s = (*s >= 'A' && *s <= 'Z')? (*s - 'A' + 'a'):*s, s++)
		;
}