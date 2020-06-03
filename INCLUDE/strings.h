#ifndef __STRINGS_H__
#define __STRINGS_H__

extern void *my_memchr (const void *string, int ch, size_t n);
extern int   my_memcmp (const void *string1, const void *string2, size_t n);
extern void *my_memcpy (void *dest, const void *src, size_t n);
extern void *my_memmove (void *dest, const void *src, size_t n);
extern void *my_memset (void *string, int ch, size_t n);

extern char *my_strcat (char *dest, const char *src);
extern char *my_strchr (const char *string, int ch);


size_t strlen(const char *string);


#endif
