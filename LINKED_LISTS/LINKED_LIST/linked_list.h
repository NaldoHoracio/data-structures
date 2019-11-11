#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 5

struct node{
    int item;
    struct node *next_node;
};

struct node* create_linked_list();

struct node* add(struct node *head, int item);

struct node* search(struct node *head, int item);

struct node* remove(struct node *head, int item);

int is_empty(struct node *head);

void print_linked_list(struct node *head);


