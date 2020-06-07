#ifndef __SINGLE_LINKED_LIST_H__
#define __SINGLE_LINKED_LIST_H__

typedef struct singleLinkedListNode
{
    int data;
    struct singleLinkedListNode *next_link;
} singleLinkedList_st;

extern void addNodeBackOfSingleLinkedList(singleLinkedList_st **head, int value);
extern void deleteNodeBackOfSingleLinkedList(singleLinkedList_st *head);
extern void addNodeFrontOfSingleLinkedList(singleLinkedList_st **head, int value);
extern void deleteNodeFrontOfSingleLinkedList(singleLinkedList_st **head);
extern void traverseSingleLinkedList(singleLinkedList_st *head);
extern void findMiddleOfSingleLinkedList(singleLinkedList_st *head, singleLinkedList_st **middle);



#endif
