#include <stdio.h>

int strend(char *s, char *t);

int main() {
	char s[] = "The quick brown fox jumped over the fence";
	
	char t1[] = "fence";
	char t2[] = "enc";
	char t3[] = "some";

	printf("%s ends with %s: %d\n", s, t1, strend(s, t1)); 	
	printf("%s ends with %s: %d\n", s, t2, strend(s, t2)); 	
	printf("%s ends with %s: %d\n", s, t3, strend(s, t3)); 	

	return 0;
}

int strend(char *s, char *t) {
	int found = 0;
	char *sp, *tp;
	sp = s;
	tp = t;

	while (*s != '\0') {
		if (*s == *t) {
			sp = s;
			tp = t;
			while (*sp != '\0' && *tp != '\0' && *sp++ == *tp++);		
		}
		s++;
	}

	if (*sp == '\0' && *tp == '\0') { 
		found = 1;
	}

	return found;
}
