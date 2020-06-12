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

void deleteNodeBackOfSingleLinkedList(singleLinkedList_st **head)
{
    singleLinkedList_st *temp_list1 = *head, temp_list_2 = NULL;

    if(*head == NULL)
        printf("Single linked list is empty. Node can't be deleted...\n");
    else
    {
        if(temp_list_1->next_link == NULL)
            *head = NULL;
        else
        {
            while(temp_list_1->next_link != NULL)
            {
                temp_list_2 = temp_list_1;
                temp_list_1 = temp_list_1->next_link;
            }
            temp_list_2->next_link = NULL;
        }
        free(temp_list_1);
    }
}

void addNodeFrontOfSingleLinkedList(singleLinkedList_st **head, int value)
{
    singleLinkedList_st *temp_node = NULL;
    temp_node = (singleLinkedList_st *)malloc(sizeof(singleLinkedList_st));

    if(temp_node == NULL)
        printf("malloc() error... memory is not allocated...\n");
    else
    {
        temp_node->data = value;
        temp_node->next_link = NULL;

        if((*head) == NULL)
            *head = temp_node;
        else
        {
            temp_node->next_link = *head;
            *head = temp_node;
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

void findMiddleOfSingleLinkedList(singleLinkedList_st *head, singleLinkedList_st **middle)
{
    singleLinkedList_st *slow_ptr = head;
    singleLinkedList_st *fast_ptr = head;

    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next_link != NULL)
        {
            fast_ptr = fast_ptr->next_link->next_link;
            slow_ptr = slow_ptr->next_link;
        }
        *middle = slow_ptr;
    }
}

void addMiddleOfSingleLinkedList(singleLinkedList_st *head, int value)
{
    singleLinkedList_st *middle = NULL, *temp_node = NULL;

    temp_node = (singleLinkedList_st *)malloc(sizeof(singleLinkedList_st));

    if(temp_node == NULL)
        printf("malloc() error... memory is not allocated...\n");
    else
    {
        findMiddleOfSingleLinkedList(head , &middle);

        while(head->next_link != middle)
            head = head->next_link;

        temp_node->data = value;
        temp_node->next_link = middle;
        head->next_link = temp_node;
    }

}
