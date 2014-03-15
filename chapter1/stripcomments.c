#include <stdio.h>

int getch();
void ungetch(char c);

#define IN_CODE					0
#define IN_MULTILINE_COMMENT	1
#define IN_ONELINE_COMMENT		2

main()
{
	int c, next, state;

	state = IN_CODE;
	while ((c = getch()) != EOF) {
		if (c == '*' && state == IN_MULTILINE_COMMENT) {
			next = getch();
			if (next == EOF) {
				break;
			} else if (next == '/') {
				state = IN_CODE;
			} else {
				ungetch(next);
			}
		} else if (c == '\n' && state == IN_ONELINE_COMMENT) {
			state = IN_CODE;
		} else if (c == '/' && state != IN_MULTILINE_COMMENT && state != IN_ONELINE_COMMENT) {
			next = getch();
			if (next == EOF) {
				break;
			} else if (next == '/') {
				state = IN_ONELINE_COMMENT;
			} else if (next == '*') {
				state = IN_MULTILINE_COMMENT;
			} else {
				ungetch(next);
			}
		} else if (state != IN_MULTILINE_COMMENT && state != IN_ONELINE_COMMENT) {
			putchar(c);
		}
	}
}


#define MAX_BUFFER_SIZE 100
static char buffer[MAX_BUFFER_SIZE];
static char *buffer_ptr = buffer;

int getch()
{
	if (buffer_ptr > buffer && buffer_ptr < (buffer + MAX_BUFFER_SIZE)) {
		return *--buffer_ptr;
	}
	return getchar();
}

void ungetch(char c)
{
	if (buffer_ptr >= buffer && buffer_ptr < (buffer + MAX_BUFFER_SIZE)) {
		*buffer_ptr++ = c;
	}
}



