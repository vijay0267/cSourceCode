#include <stdio.h>
#include <stdlib.h>
#include "INCLUDE/stack.h"

#if(STACK_WITH_ARRAY)

#define SIZE    10

int top_of_stack = -1;
int stack[SIZE];

static int isEmpty(void)
{
    if(top_of_stack == -1)
        return 1;

    return 0;
}

static int isFull(void)
{
    if(top_of_stack == SIZE - 1)
        return 1;

    return 0;
}

void traverse(void)
{
    int i = 0;
    if(isEmpty())
        printf("Stack is empty.");
    else
    {
        for( ; i <= top_of_stack; ++i)
            printf("%d\n", stack[i]);
    }
}

void push(int num)
{
    if(isFull())
        printf("Stack is full. Cann't push elements...");
    else
        stack[++top_of_stack] = num;
}

void pop(void)
{
    if(isEmpty())
        printf("Stack is empty. Elements cann't be popped..");
    else
        --top_of_stack;
}

#endif

#if(STACK_WITH_LINKED_LIST)

typedef struct stack
{
    int data;
    struct stack *next_node;
}stack_t;

stack_t *top_of_stack = NULL;


void push(int num)
{
    stack_t *temp_node = NULL;
    temp_node = (stack_t *)malloc(sizeof(stack_t));

    if(!temp_node)
        printf("Stack is full. Elements cann't be inserted\n");
    else
    {
        temp_node->data = num;

        if(!top_of_stack)
            temp_node->next_node = NULL;
        else
            temp_node->next_node = top_of_stack;

        top_of_stack = temp_node;
    }
}

void pop(void)
{
    stack_t *temp_node = top_of_stack;

    if(!top_of_stack)
        printf("Stack is empty..");
    else
    {
        top_of_stack = top_of_stack->next_node;
        free(temp_node);
    }
}

void traverse(void)
{
    stack_t *temp_node = top_of_stack;

    if(!top_of_stack)
        printf("Stack is empty..");
    else
        for( ; temp_node != NULL; temp_node = temp_node->next_node)
            printf("%d\n", temp_node->data);
}
#endif
