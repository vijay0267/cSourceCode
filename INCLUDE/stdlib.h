#ifndef __STDLIB_H__
#define __STDLIB_H__

typedef char ALIGN[16];

typedef union header {
	struct {
		size_t size;
		unsigned is_free;
		union header *next;
	} s;
	ALIGN stub;
}header_t;


#endif
