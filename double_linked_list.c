#include <stdio.h>
#include <stdlib.h>
#include "INCLUDE/double_linked_list.h"

void addNodeBackOfDoubleLinkedList(double_linked_list_st **head , int val)
{
	double_linked_list_st *newNode = NULL, *node = *head;

	newNode = (double_linked_list_st *)malloc(sizeof(double_linked_list_st));
	newNode->data = val;
	newNode->next = NULL;

	if(*head == NULL)
	{
		newNode->previous = NULL;
		*head = newNode;
	}
	else
	{
		while((node->next) != NULL)
			node = node->next;

		node->next = newNode;
		newNode->previous = node;
	}
}

void deleteNodeBackOfDoubleLinkedList(double_linked_list_st *head)
{
    double_linked_list_st *temp_list = head;
    if(head == NULL)
        printf("Double linked list is empty. Node cann't be deleted\n");
    else
    {
        while(temp_list->next != NULL)
        {
            head = temp_list;
            temp_list = temp_list->next;
        }

        head->next = NULL;
        free(temp_list);
    }
}

void addNodeFrontOfDoubleLinkedList(double_linked_list_st **head, int val)
{
	double_linked_list_st *newNode = NULL;

	newNode = (double_linked_list_st *)malloc(sizeof(double_linked_list_st));
	newNode->data = val;
	newNode->previous = NULL;

	if(*head == NULL)
	{
		newNode->next = NULL;
		*head = newNode;
	}
	else
	{
		(*head)->previous = newNode;
		newNode->next = *head;
		*head = newNode;
	}
}

void deleteNodeFrontOfDoubleLinkedList(double_linked_list_st **head)
{
    double_linked_list_st *temp_list = *head;
    if(*head == NULL)
        printf("Double linked list is empty. Node cann't be deleted\n");
    else
    {
        *head = (*head)->next;
        (*head)->previous = NULL;
        free(temp_list);
    }
}
void traverseDoubleLinkedListForward(double_linked_list_st *head)
{
	if(head == NULL)
		printf("List is empty.\n");
	else
	{
		printf("%d\n", head->data);
		while(head->next != NULL)
		{
			head = head->next;
			printf("%d\n", head->data);
		}
	}
}

void traverseDoubleLinkedListBackward(double_linked_list_st *head)
{
	if(head == NULL)
		printf("List is empty.\n");
	else
	{
		while(head->next != NULL)
		{
			head = head->next;
		}

		printf("%d\n", head->data);
		while(head->previous != NULL)
		{
			head = head->previous;
			printf("%d\n", head->data);
		}
	}
}
