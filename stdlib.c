#include <unistd.h>
#include <string.h>
#include <pthread.h>


header_t *head = NULL, *tail = NULL;
pthread_mutex_t global_malloc_lock;

header_t *getFreeMemoryBlock(size_t size)
{
    header_t *temp_head = head;
    while(temp_head)
    {
        if((temp_head->memData.is_free) && (temp_head->memData.size >= size))
            return (void *)temp_head;

        temp_head = temp_head->memData.next;
    }
    return NULL;
}

void *my_malloc(size_t size)
{
    header_t *header;
    size_t total_size;
    void *memory_block = NULL;

    if(!size)
        return NULL;

    pthread_mutex_lock(&global_malloc_lock);
    header = getFreeMemoryBlock(size);

    if(header)
    {
        header->memData.is_free = 0;
        pthread_mutex_unlock(&global_malloc_lock);
        return (void *)(header + 1);
    }
    total_size = sizeof(header_t) + size;
    memory_block = sbrk(total_size);

    if(memory_block == (void *) -1)
    {
        pthread_mutex_unlock(&global_malloc_lock);
        return NULL;
    }
    header = memory_block;
    header->memData.size = size;
    header->memData.is_free = 0;
    header->memData.next = NULL;

    if(!head)
        head = header;

    if(tail)
        tail->memData.next = header;

    tail = header;
    pthread_mutex_unlock(&global_malloc_lock);
    return (void *)(header + 1);
}

void my_free(void *mem_block)
{
	header_t *header, *tmp;
	/* program break is the end of the process's data segment */
	void *programbreak;

	if (!mem_block)
		return;

	pthread_mutex_lock(&global_malloc_lock);
	header = (header_t*)mem_block - 1;
	/* sbrk(0) gives the current program break address */
	programbreak = sbrk(0);

	/*
	   Check if the block to be freed is the last one in the
	   linked list. If it is, then we could shrink the size of the
	   heap and release memory to OS. Else, we will keep the block
	   but mark it as free.
	 */
	if ((char*)mem_block + header->memData.size == programbreak) {
		if (head == tail) {
			head = tail = NULL;
		} else {
			tmp = head;
			while (tmp) {
				if(tmp->memData.next == tail) {
					tmp->memData.next = NULL;
					tail = tmp;
				}
				tmp = tmp->memData.next;
			}
		}
		/*
		   sbrk() with a negative argument decrements the program break.
		   So memory is released by the program to OS.
		*/
		sbrk(0 - header->memData.size - sizeof(header_t));
		/* Note: This lock does not really assure thread
		   safety, because sbrk() itself is not really
		   thread safe. Suppose there occurs a foregin sbrk(N)
		   after we find the program break and before we decrement
		   it, then we end up realeasing the memory obtained by
		   the foreign sbrk().
		*/
		pthread_mutex_unlock(&global_malloc_lock);
		return;
	}
	header->memData.is_free = 1;
	pthread_mutex_unlock(&global_malloc_lock);
}

void *my_calloc(size_t num, size_t nsize)
{
	size_t size;
	void *block;
	if (!num || !nsize)
		return NULL;
	size = num * nsize;
	/* check mul overflow */
	if (nsize != size / num)
		return NULL;
	block = my_malloc(size);
	if (!block)
		return NULL;
	memset(block, 0, size);
	return block;
}

void *my_realloc(void *block, size_t size)
{
	header_t *header;
	void *new_block;
	if (!block || !size)
		return my_malloc(size);

	header = (header_t*)block - 1;
	if (header->memData.size >= size)
		return block;

	ret = my_malloc(size);
	if (new_block) {
		/* Relocate contents to the new bigger block */
		memcpy(ret, block, header->memData.size);
		/* Free the old memory block */
		my_free(block);
	}
	return ret;
}
