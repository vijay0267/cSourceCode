#include <stdio.h>
#include "INCLUDE/strings.h"

int main(void)
{
    char name[40] = "Vijay Lakshman Kumar";
    size_t length = 0Ul;

    length = strlen(name);    

    printf("Length of the name = %lu\n", length);
    
    return (0);
}
