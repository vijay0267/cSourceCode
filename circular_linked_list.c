#include <stdio.h>
#include <stdlib.h>
#include "INCLUDE/circular_linked_list.h"

void addNodeBackOfCircularLinkedList(circularLinkedList_st **head, int value)
{
    circularLinkedList_st *new_node = NULL, *temp_list = *head;

    new_node = (circularLinkedList_st *)malloc(sizeof(circularLinkedList_st));
    if(new_node == NULL)
    {
        printf("malloc() error... memory is not allocated...\n");
    }
    else
    {
        new_node->data = value;

        if((*head) == NULL)
        {
            *head = new_node;
            (*head)->next_link = *head;
        }
        else
        {
            while(temp_list->next_link != *head)
                temp_list = temp_list->next_link;

            new_node->next_link = *head;
            temp_list->next_link = new_node;
        }

    }
}

void deleteNodeBackOfCircularLinkedList(circularLinkedList_st **head)
{
    singleLinkedList_st *temp_list_1 = *head, *temp_list_2 = NULL;

    if(*head == NULL)
        printf("Single linked list is empty. Node can't be deleted...\n");
    else
    {
        if(temp_list_1->next_link == *head)
            *head = NULL;
        else
        {
            while(temp_list_1->next_link != *head)
            {
                temp_list_2 = temp_list_1;
                temp_list_1 = temp_list_1->next_link;
            }
            temp_list_2->next_link = *head;
        }
        free(temp_list_1);
    }
}

void addNodeFrontOfCircularLinkedList(circularLinkedList_st **head, int value)
{
    circularLinkedList_st *new_node = NULL, temp_list_1 = *head;
    new_node = (circularLinkedList_st *)malloc(sizeof(circularLinkedList_st));

    if(new_node == NULL)
        printf("malloc() error... memory is not allocated...\n");
    else
    {
        new_node->data = value;
        if(temp_list_1 == NULL)
        {
            temp_node->next_link = temp_node;
            *head = temp_node;
        }
        else
        {
            while(temp_list_1->next_link != *head)
                temp_list_1 = temp_list_1->next_link;

            temp_node->next_link = *head;
            temp_list_1->next_link = temp_node;
            *head = temp_node;
        }
    }
}
