#include <stdio.h>
#include "INCLUDE/strings.h"



int main(void)
{
	const char a1[40] = "vijaylakshman";
	const char a2[40] = "vijaylakshmanvijvia";
	const char a3[40] = "vijaylakshman";
	const char a4[40] = "vijaylaklaklakshman";
	const char a5[40] = "vijaylakshman";

	const char b1[20] = "vij";

	printf("%s\n", my_strstr(a1, b1));
	printf("%s\n", my_strstr(a2, "via"));
	printf("%s\n", my_strstr("vijaylakshman", "lak"));
	printf("%s\n", my_strstr(a4, "laks"));
	printf("%s\n", my_strstr("vijaylakshman", "\0"));

	return 0;
}
