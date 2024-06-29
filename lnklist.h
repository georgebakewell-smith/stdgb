#ifndef LNKLIST_H
#define LNKLIST_H

typedef struct Node
{

    int data;
    struct Node *next;

}node;

node *gb_create_node();
void gb_free_list(node *head);
void gb_append(node *head, int x);
void gb_print_list(node *head);

#endif