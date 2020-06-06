#include <stdio.h>
#include <stdlib.h>
#include "INCLUDE/single_linked_list.h"

void addNodeBackOfSingleLinkedList(singleLinkedList_st **head, int value)
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

void deleteNodeBackOfSingleLinkedList(singleLinkedList_st *head)
{
    singleLinkedList_st *temp_list = head;

    if(head == NULL)
        printf("Single linked list is empty. Node can't be deleted...\n");
    else
    {
        while(temp_list->next_link != NULL)
        {
            head = temp_list;
            temp_list = temp_list->next_link;
        }

        free(temp_list);
        head->next_link = NULL;
    }
}

void addNodeFrontOfSingleLinkedList(singleLinkedList_st **head, int value)
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

void deleteNodeFrontOfSingleLinkedList(singleLinkedList_st **head)
{
    singleLinkedList_st *temp_list = *head;

    if(*head == NULL)
        printf("Single linked list is empty. Node can't be deleted...\n");
    else
    {
        *head = (*head)->next_link;
        free(temp_list);
    }
}

void traverseSingleLinkedList(singleLinkedList_st *head)
{
    singleLinkedList_st *list_head = head;

    if(head == NULL)
        printf ("The linked list is empty....\n");
    else
    {
        while (list_head != NULL)
        {
            printf("\t %d \n", list_head->data);
            list_head = list_head->next_link;
        }
    }
}
