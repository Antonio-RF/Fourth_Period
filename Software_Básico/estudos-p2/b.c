#include <stdio.h>

int globalB=1;
void b (char* s) {
	printf("%s %d\n" , s, globalB);
}
