#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Estrutura node
struct Node
{
  int item;
  node *next_node;
};
//Definindo tipo node
typedef struct Node node_ed;
//Criando a lista encadeada
node_ed* create_linked_list_ed()
{
  return NULL;
}
//Lista vazia
int is_empty_ed(node_ed *head)
{
  return (head == NULL);
}
//Adicionando elemento
node_ed* add_ed(node_ed *head, int item)
{
  node_ed *new_node = (node_ed*)malloc(sizeof(node_ed));
  new_node->item = item;
  new_node->next_node = head;
  return new_node;
}
//Imprimindo a lista - forma nao recursiva
void print_linked_list_no_recursive_ed(node_ed *head)
{
  while(head != NULL)
  {
    printf("%d\n", head->item);
    head = head->next_node;
  }
}
//Imprimindo a lista - forma recursiva
void print_linked_list_recursive_ed(node_ed *head)
{
  while(!is_empty_ed(head))
  {
    printf("%d\n", head->item);
    print_linked_list_recursive_ed(head->next_node);
  }
}
//Buscando elemento
node_ed* search_element_ed(node_ed *head, int item)
{
  while(head != NULL)
  {
    if(head->item == item)
    {
      return head;
    }
    head = head->next_node;
  }
}
//Removendo elemento
node_ed* remove_node_ed(node_ed *head, int item)
{
  node_ed *previous = NULL;
  node_ed *current = head;
  while (current != NULL && current->item != item)
  {
    previous = current;
    current = current->next_node;
  }
  if(current == NULL)
  {
    return head;
  }
  if(previous = NULL)
  {
    head = current->next_node;
  }else
  {
    previous->next_node = current->next_node;
  }
  free(current);
  return head;
}
