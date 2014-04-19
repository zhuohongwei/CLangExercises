#include <stdio.h>

void itoa(int i, char s[]);
int main() {
	char s[1000];
	int i;
	i = -896896;
	itoa(i, s);
	printf("int %d converted to string %s\n", i, s);
}

void itoaiter(int i, char s[], int offset, int sign);
void reverse(char *s);

void itoa(int i, char s[]) {
	int offset = 0;
	int sign = 1;
	if (i < 0) {
		sign = -1;
		i = -i;
	}
	itoaiter(i, s, offset, sign);
	reverse(s);	
}

void itoaiter(int i, char s[], int offset, int sign) {
	s[offset++] = i%10 + '0';
	if (i/10) {
		itoaiter(i/10, s, offset, sign);
	} else {
		if (sign < 0) {
			 s[offset++] = '-';
		}
		s[offset] = '\0';
	}
}  

int slen(char *s);
void reverse(char *s) {
	int i, j;
	i = 0;
	j = slen(s) - 1;
	while (i < j){
		*(s+i) ^= *(s+j);
		*(s+j) ^= *(s+i);
		*(s+i) ^= *(s+j);
		i++; j--;
	}
}

int slen(char *s) {
	int len;
	len = 0;
	while (*s++ != '\0') {
		++len;
	}
	return len;
}



