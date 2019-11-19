#include "linked_list.h"

struct node* create_linked_list()
{
  return NULL;
}

int is_empty(struct node *head)
{
  return (head == NULL);
}

struct node* add(struct node *head, int item)
{
  struct node *new_node = (struct node*)malloc(sizeof(struct node));
  new_node->item = item;
  new_node->next_node = head;
  return new_node;
}

struct node* search(struct node *head, int item)
{
  while (!is_empty(head))
  {
    if(head->item == item)
    {
      return head;
    }
    head = head->next_node;
  }
  return NULL;
  
}

struct node* remove(struct node *head, int item)
{
  struct node *previous = NULL;
  struct node *current = head;
  while(current != NULL && current->item != item)
  {
    previous = current;
    current = current->next_node;
  }
  if(current == NULL) return head;
  if(previous == NULL) head = current->next_node;
  else previous->next_node = current->next_node;

  free(current);
  return head;
}

void print_linked_list(struct node *head)
{
  while (!is_empty(head))
  {
    printf("%d\n", head->item);
    head = head->next_node;
  } 
}

int main()
{
  printf("Hello world!\n");
  return 0;
}