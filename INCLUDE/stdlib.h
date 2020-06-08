#ifndef __STDLIB_H__
#define __STDLIB_H__

typedef char SPACE[16];
typedef unsigned long size_t;

typedef union header_data {
	struct {
		size_t size;
		unsigned int is_free;
		union header_data *next;
	} memData;
	SPACE head_size;
}header_t;

extern header_t *getFreeMemoryBlock(size_t size);
extern void *my_malloc(size_t size);
extern void my_free(void *mem_block);
extern void *my_calloc(size_t num, size_t nsize);

#endif
