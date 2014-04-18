#include <stdio.h>

void ritoa(int i, char *s);
void reverse(char *s);

int main() {
	char s[1000];
	int i;
	i = -896896;
	ritoa(i, s);
	reverse(s);
	printf("int %d converted to string %s\n", i, s);
}


int slen(char *s);

void ritoa(int i, char *s) {
	int sign;
	sign = 1;

	if (i < 0) {
		sign = -1;
		i = -i;
	}
	
	*s++ = i%10 + '0';
	i *= sign;

	i /= 10;

	if (!i) {
		if (sign < 0) *s++ = '-';
		*s = '\0';
	} else {
		ritoa(i, s);
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

