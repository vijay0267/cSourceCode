#include <stdlib.h>
#include "INCLUDE/strings.h"
    

size_t strlen(const char *string)
{
    size_t string_length = 0Ul;
    
    while(*string != NULL)
    {
        ++string_length;
        ++string;
    }

    return string_length;
}
