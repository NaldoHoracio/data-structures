#include "doubly_ll.h"

struct double_node* create_double_linked_list()
{
  return NULL;
}

int is_empty(struct double_node *head)
{
  return (head == NULL);
}

struct double_node* add(struct double_node *head, int item)
{
  struct double_node *new_node = (struct double_node*)malloc(sizeof(struct double_node));
  new_node->item = item;
  new_node->next_node = head;
  new_node->previous_node = NULL;
  if(head != NULL)
  {
    head->previous_node = new_node;
  }
  return new_node;
}

struct double_node* search(struct double_node *head, int item)
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

struct double_node* remove(struct double_node *head, int item)
{
  struct double_node *current = head;
  while(current != NULL && current->item != item)
  {
    current = current->next_node;
  }

  if(current == NULL) return head;

  if(head == current){
    head = current->next_node;
  }else{
    current->previous_node->next_node = current->next_node;
  }

  if(current->next_node != NULL)
  {
    current->next_node->previous_node = current->previous_node;
  }
  free(current);
  return head;
}

void print_doubly_linked_list_foward(struct double_node *head)
{
  if(!is_empty(head))
  {
    printf("%d\n", head->item);
    print_doubly_linked_list_foward(head->next_node);
  }
}

void print_doubly_linked_list_backward(struct double_node *head)
{
  if(!is_empty(head))
  {
    printf("%d\n", head->item);
    print_doubly_linked_list_backward(head->previous_node);
  }
}

int main()
{
  struct double_node *my_dll = create_double_linked_list();
  int item_search = 8;
  my_dll = add(my_dll, 3);
  my_dll = add(my_dll, 5);
  my_dll = add(my_dll, 7);

  printf("PRA FRENTE:\n");
  print_doubly_linked_list_foward(my_dll);
  //printf("\nPRA TRÁS:\n");
  //print_doubly_linked_list_backward(my_dll);

  my_dll = search(my_dll, item_search);

  if(!is_empty(my_dll)) printf("O elemento %d existe!\n", item_search);
  else printf("O elemento %d nao existe.\n", item_search);

  printf("Hello world!\n");
  return 0;
}
