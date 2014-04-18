#include <stdio.h>

void reverse(char *s);

int main() {
	char s[] = "helloooo worrrrldddd";
	reverse(s);
	printf("reversed string:%s\n", s);
}

int slen(char *s);
void reverseiter(char *s, int left, int right);

void reverse(char *s) {
	int i, j;
	i = 0;
	j = slen(s) - 1;
	reverseiter(s, i, j);
}

int slen(char *s) {
	int len;
	len = 0;
	while(*s++ != '\0') len++;
	return len;
}

void reverseiter(char *s, int left, int right) {
	if (left < right) {
		s[left] ^= s[right];
		s[right] ^= s[left];
		s[left] ^= s[right];
		reverseiter(s, ++left, --right); 
	}
}

