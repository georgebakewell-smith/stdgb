#include <stdio.h>
#include <stdlib.h>
#include "../lnklist.h"

node *gb_node_create()
{
    node *head = (node*)malloc(sizeof(node));
    head->data = 0;
    head->next = NULL;

    return head;
}

void gb_llist_free(node *head)
{
    node *current = head;
    node *previous = NULL;
    while(current->next != NULL)
    {
        previous = current;  
        current = current->next;

        free(previous);     
    }

    free(current);
}

void gb_llist_append(node *head, int x)
{
    node *current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = gb_node_create();
    current->next->data = x;
}

void gb_llist_print(node *head)
{
    node *current = head;
    while(current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int gb_llist_length(node *head)
{
    int length = 1;
    node *current = head;
    while(current->next != NULL)
    {
        ++length;
        current = current->next;
    }

    return length;

}

void gb_llist_insert(node *head, int position, int data)
{
    if(head == NULL)
    {
        printf("Error in gb_llist_insert() : head pointer is NULL\n");

        return;
    }

    int index = 0;
    node *current = head, *new = gb_node_create();
    if(position == 0)
    {      
        new->data = head->data;      
        new->next = head->next;      
        head->data = data;      
        head->next = new;
        
        return;
    }

    while(current->next != NULL)
    {
        if(index + 1 == position)
        {
            new->next = current->next;
            new->data = data;
            current->next = new;

            return;
        }else
        {
            current = current->next;
            ++index;
        }
    }
    if(index + 1 < position)
    {
        printf("Error in gb_llist_insert() : position is larger than length of linked list\n");

        return;
    }
    new->data = data;
    current->next = new;
}

int *gb_llist_get(node *head, int position)
{
    node *current = head;
    int index = 0;

    if(head == NULL)
    {
        printf("Error in gb_llist_get() : head pointer is NULL\n");

        return NULL;
    }    

    if(position == 0)
    {
        return &head->data;
    }

    while(current->next != NULL)
    {
        if(index == position)
        {
            return &current->data;
        }else{
            ++index;
            current = current->next;
        }
    }

    if(index < position)
    {
        printf("Error in gb_llist_get() : position is larger than length of linked list\n");

        return NULL;
    }
    return &current->data;
}