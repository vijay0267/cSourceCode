#include <stddef.h>

typedef struct singleLinkedListNode
{
    int data;
    struct singleLinkedListNode *next_link;
} singleLinkedList_st;

void addNodeBackOfLinkedList(singleLinkedList_st **head, int value)
{
    singleLinkedList_st *temp_node = NULL, *temp_list = *head;

    temp_node = (singleLinkedList_st *)malloc(sizeof(singleLinkedList_st));
    if(temp_node == NULL)
    {
        printf("malloc() error... memory is not allocated...\n");
    }
    else
    {
        temp_node->data = value;
        temp_node->next_link = NULL;
        if((*head) == NULL)
        {
            *head = temp_node;
        }
        else
        {
            while(temp_list->next_link != NULL)
                temp_list = temp_list->next_link;

            temp_list->next_link = temp_node;
        }

    }
}

void addNodeFrontOfLinkedList(singleLinkedList_st **head, int value)
{
    singleLinkedList_st *temp_node = NULL, *temp_list = *head;

    temp_node = (singleLinkedList_st *)malloc(sizeof(singleLinkedList_st));
    if(temp_node == NULL)
    {
        printf("malloc() error... memory is not allocated...\n");
    }
    else
    {
        temp_node->data = value;
        temp_node->next_link = NULL;
        if((*head) == NULL)
        {
            *head = temp_node;
        }
        else
        {
            temp_list->next_link = *head;
            *head = temp_list;
        }

    }
}

void traverseSingleLinkedList(singleLinkedList_st *head)
{
    singleLinkedList_st list_head = head;

    if(head == NULL)
    {
        printf ("The linked list is empty....\n");
    }
    else
    {
        while (list_head != NULL)
        {
            printf("\t %d \n", list_head->data);
            list_head = list_head->next_link;
        }
    }
}
