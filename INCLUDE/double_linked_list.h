#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

typedef struct double_linked_list
{
	struct double_linked_list *previous;
	int data;
    struct double_linked_list *next;
}double_linked_list_st;

extern void addNodeBackOfDoubleLinkedList(double_linked_list_st **head , int val);
extern void deleteNodeBackOfDoubleLinkedList(double_linked_list_st *head);
extern void addNodeFrontOfDoubleLinkedList(double_linked_list_st **head, int val);
extern void deleteNodeFrontOfDoubleLinkedList(double_linked_list_st **head);
extern void traverseDoubleLinkedListForward(double_linked_list_st *head);
extern void traverseDoubleLinkedListBackward(double_linked_list_st *head);

#endif
