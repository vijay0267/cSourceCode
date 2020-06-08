#include <unistd.h>
#include <stdef.h>
#include <pthread.h>


header_t *head, *tail;
pthread_mutex_t global_malloc_lock;


void *malloc(size_t size)
{
    header_t *header;
    if(!size)
        return NULL;

    pthread_mutex_lock(&global_malloc_lock);

    if(header)
    {
        header->memData_t.is_free = 0;
    }
}
