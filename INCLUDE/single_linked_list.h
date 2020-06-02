#ifndef __SINGLE_LINKED_LIST_H__
#define __SINGLE_LINKED_LIST_H__

typedef struct singleLinkedListNode
{
    int data;
    struct singleLinkedListNode *next_link;
} singleLinkedList_st;

extern void addNodeBackOfLinkedList(singleLinkedList_st **head, int value);
extern void deleteNodeBackOfLinkedList(singleLinkedList_st *head, int value);
extern void addNodeFrontOfLinkedList(singleLinkedList_st **head, int value);
extern void deleteNodeFrontOfLinkedList(singleLinkedList_st **head, int value);
extern void traverseSingleLinkedList(singleLinkedList_st *head);



#endif
