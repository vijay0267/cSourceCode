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
 * Description:- The my_memcpy() function shall copy the first n bytes pointed to by src to the buffer pointed to by
 * dest. Source and destination may not overlap.
 *
 * Return value:- The my_memcpy() function shall return the pointer dest; the function has no failure mode and no
 * error return.
*/
void *my_memcpy (void *dest, const void *src, size_t n)
{
    char *dp = dest;
    const char *sp = src;

    for( ; 0 < n; ++dp, ++sp, --n)
        *dp = *sp;

    return (dest);
}

/*
 * Description:- The my_memmove() function shall copy the first n bytes pointed to by src to the buffer pointed to by
 * dest. Source and destination may overlap.
 *
 * Return value:- The my_memmove() function shall return the pointer dest; the function has no failure mode and no
 * error return.
*/
void *my_memmove (void *dest, const void *src, size_t n)
{
    char *dp = dest;
    const char *sp = src;

    if((dp > sp) && (dp < (sp + n))) // copy backward
        for(dp += (n-1), sp += (n-1); 0 < n; --dp, --sp, --n)
            *dp = *sp;
    else                            // copy forward
        for( ; 0 < n; ++dp, ++sp, --n)
            *dp = *sp;

    return (dest);
}

/*
 * Description:- The my_memset function copies the value of ch (converted to an unsigned char) into each of the
 * ﬁrst n characters of the object pointed to by string.
 *
 * Return value:- The my_memset() function shall returns the value of s.
*/
void *my_memset(void *string, int ch, size_t n)
{
    unsigned char *s = string;
    const unsigned char c = (char)ch;

    for( ; 0 < n; ++s, --n)
        *s = c;

    return (string);
}

/*
 * Description:- The my_strcat() function shall append the null-terminated string pointed to by src to the
 * null-terminated string pointed to by dest. The first character of src overwrites the null-terminator of dest.
 * Source and destination may not overlap.
 *
 * Return value:- The my_strcat() function shall return the pointer dest; the function has no failure mode and no
 * error return.
*/
char *my_strcat (char *dest, const char *src)
{
    char *temp_string = dest;

    for( ; *dest != '\0'; ++dest);

    for( ; (*dest = *src) != '\0'; ++dest, ++src);

    return (temp_string);
}

/*
 * Description:- The my_strchr() function locates the ﬁrst occurrence of c (converted to a char) in the string pointed
 * to by s. The terminating null character is considered to be part of the string.
 *
 * Return value:- The strchr() function returns a pointer to the located character, or a null pointer if the character
 * does not occur in the string.
*/
char *my_strchr (const char *string, int ch)
{
    const char c = ch;

    for( ; *string != '\0', ++string)
        if(c == *string)
            return (char *)(string);

    return (NULL);
}

int strcmp(const char *string1, const char *string2)
{
    
}


/*
 * Description:-
 *
 * Return value:-
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
