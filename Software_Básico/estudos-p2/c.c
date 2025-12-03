#include <stdio.h>

int globalC=1;
void c (char* s) {
	printf("%s %d\n" , s, globalC);
}
