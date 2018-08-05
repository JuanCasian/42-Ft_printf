#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	void *s;

	s = (void*)malloc(5);
    printf("%-30p\n", s);
}
