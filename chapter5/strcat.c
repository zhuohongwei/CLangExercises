#include <stdio.h>

void scat(char *s, char *t);
int main() {
	char s[] = "hello ";
	char t[] = "world";
	scat(s, t);
	printf("final string: %s\n", s);
	return 0;
}


void scat(char *s, char *t) {
	while (*s != '\0') s++;
	while (*t != '\0') {
		*s++ = *t++;
	}
	*s = '\0';
}
