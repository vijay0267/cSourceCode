#include <stddef.h>
#include "INCLUDE/strings.h"

/*
 * Description:- The my_memchr() function locates the ﬁrst occurrence of ch (converted to an unsigned char)
 * in the initial n characters (each interpreted as unsigned char) of the object pointed to by string.
 *
 * Return value:- The my_memchr() function returns a pointer to the located character, or a null pointer
 * if the character does not occur in the object.
*/
void *my_memchr (const void *string, int ch, size_t n)
{
    unsigned char c  = (unsigned char)ch;
    unsigned char *s = (unsigned char *)string;

    for( ; 0 < n; ++s, --n)
        if(c == *s)
            return ((void *)s);

    return (NULL);
}

/*
 * Description:- The my_memcmp() function compares first n characters of object pointed to by string1 with
 * firat n characters of object pointed to by string2.
 *
 * Return value:- The my_memcmp() function returns an integer greater than, equal to, or less than zero,
 * accordingly as the object pointed to by s1 is greater than, equal to, or less than the object pointed to by s2.
*/
int my_memcmp (const void *string1, const void *string2, size_t n)
{
    const unsigned char *s1 = string1, *s2 = string2;

    for( ; 0 < n; ++s1, ++s2, --n)
        if(*s1 != *s2)
            return ((*s1 < *s2)? -1: +1);

    return (0);
}



/*
 * This function returns the length of the string except NULL.
*/
size_t my_strlen(const char *string)
{
    size_t string_length = 0Ul;

    while(*string != '\0')
    {
        ++string_length;
        ++string;
    }

    return string_length;
}
