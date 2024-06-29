#include <stdio.h>
#include <stdlib.h>
#include "../lnklist.h"

node *gb_create_node()
{

    node *head = (node*)malloc(sizeof(node));
    head->data = 0;
    head->next = NULL;

    return head;
}

void gb_free_list(node *head)
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

void gb_append(node *head, int x)
{
    node *current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = gb_create_node();
    current->next->data = x;
}

void gb_print_list(node *head)
{
    node *current = head;
    while(current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}