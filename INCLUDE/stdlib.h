#ifndef __STDLIB_H__
#define __STDLIB_H__

typedef char SPACE[16];
typedef unsigned long size_t;

typedef union header_data {
	struct {
		size_t size;
		unsigned int is_free;
		union header_data *next;
	} memData_t;
	SPACE head_size;
}header_t;



#endif
