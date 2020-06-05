#ifndef __STRINGS_H__
#define __STRINGS_H__

extern void *my_memchr (const void *string, int ch, size_t n);
extern int   my_memcmp (const void *string1, const void *string2, size_t n);
extern void *my_memcpy (void *dest, const void *src, size_t n);
extern void *my_memmove (void *dest, const void *src, size_t n);
extern void *my_memset (void *string, int ch, size_t n);

extern char *my_strcat (char *dest, const char *src);
extern char *my_strncat (char *dest, const char *src, size_t n);
extern int   my_strcmp (const char *string1, const char *string2);
extern int   my_strncmp (const char *string1, const char *string2, size_t n);
extern char *my_strcpy (char *dest, const char *src);
extern char *my_strncpy (char *dest, const char *src, size_t n);

extern char *my_strchr (const char *string, int ch);
extern char *my_strrchr (const char *string, int ch);
extern char *my_strstr (const char* string1, const char *string2);

extern size_t strlen (const char *string);

extern size_t my_strspn (const char *string1, const char *string2);
extern size_t my_strcspn (const char *string1, const char *string2);
#endif
