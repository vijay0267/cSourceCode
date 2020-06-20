#ifndef __STACK_H__
#define __STACK_H__

#define STACK_WITH_ARRAY            0
#define STACK_WITH_LINKED_LIST      1

    #if(STACK_WITH_ARRAY)

    extern void traverse(void);
    extern void push(int num);
    extern void pop(void);

    #endif

    #if(STACK_WITH_LINKED_LIST)

    extern void traverse(void);
    extern void push(int num);
    extern void pop(void);

    #endif
#endif
