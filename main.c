#include <stdio.h>
#include "INCLUDE/strings.h"


int main(void)
{
	printf("%d\n", my_memcmp("vijay", "vijay", 1));
    printf("%d\n", my_memcmp("vijay", "vijay", 2));
    printf("%d\n", my_memcmp("vijay", "viJay", 3));
    printf("%d\n", my_memcmp("vijAy", "vijay", 4));
    printf("%d\n", my_memcmp("vijay", "zija", 5));
	return 0;
}
