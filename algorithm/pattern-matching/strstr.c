#include <stdio.h>
#include <string.h>

int main() {
	char y[] = "How are you hello world";
	char x[] = "hello";

	char *p;
	p = strstr(y, x);
	printf("p=%s\n", p);

	return 0;
}
