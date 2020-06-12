#ifndef __CIRCULAR_LINKED_LIST_H__
#define __CIRCULAR_LINKED_LIST_H__

typedef struct circularLinkedListNode
{
    int data;
    struct circularLinkedListNode *next_link;
} circularLinkedList_st;

extern void addNodeBackOfCircularLinkedList(circularLinkedList_st **head, int value)
extern void deleteNodeBackOfCircularLinkedList(circularLinkedList_st **head);
extern void addNodeFrontOfCircularLinkedList(circularLinkedList_st **head, int value);

#endif
