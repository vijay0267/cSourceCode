#include <stdio.h>
#include "INCLUDE/strings.h"
#include <string.h>


int main(void)
{
	const char a1[40] = "vijaylakshman";
	const char a2[40] = "vijaylakshmanvijvia";
	const char a3[40] = "vijaylakshman";
	const char a4[40] = "vijaylaklaklakshman";
	const char a5[40] = "vijaylakshman";

	const char b1[20] = "vij";

	printf("%lu\n", my_strspn(a1, b1));
	printf("%lu\n", my_strspn(a1, "va"));
	printf("%lu\n", my_strspn(a1, "z"));
	printf("%lu\n", my_strspn(a1, "ivjayl"));

	printf("%lu\n", strspn(a1, b1));
	printf("%lu\n", strspn(a1, "va"));
	printf("%lu\n", strspn(a1, "z"));
	printf("%lu\n", strspn(a1, "ivjayl"));

	return (EXIT_SUCCESS);
}
