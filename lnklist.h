#ifndef LNKLIST_H
#define LNKLIST_H

typedef struct Node
{

    int data;
    struct Node *next;

}node;

node *gb_node_create();
void gb_llist_free(node *head);
void gb_llist_append(node *head, int x);
void gb_llist_print(node *head);
int gb_llist_length(node *head);
void gb_llist_insert(node *head, int position, int data);
int *gb_llist_get(node *head, int position);

#endif