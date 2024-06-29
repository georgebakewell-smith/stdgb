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