#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 5

//Estrutura node
struct Node
{
  int item;
  Node *next_node;
};
//Definindo tipo node
typedef struct Node node_ed;
//Criando a lista encadeada - modo 1
node_ed* create_linked_list_ed()
{
  return NULL;
}

//Criando a lista - modo 2
node_ed* create_linked_list_ed2(node_ed *node, int item)
{
  node->item = item;
  node->next_node = NULL;
  return node;
}
//Lista vazia
int is_empty_ed(node_ed *head)
{
  return (head == NULL);
}
//Adicionando elemento no começo da fila
node_ed* add_on_head_ed(node_ed *head, int item)
{
  node_ed *new_node = (node_ed*)malloc(sizeof(node_ed));
  new_node->item = item;
  new_node->next_node = head;
  return new_node;
}
//Adicionando elemento no fim da Lista
node_ed* add_on_last_ed(node_ed *head, int item)
{
  node_ed *aux = (node_ed*)malloc(sizeof(node_ed));
  aux = head;

  while(aux->next_node != NULL) aux = aux->next_node;
  node_ed *new_node = (node_ed*)malloc(sizeof(node_ed));
  new_node->item = item;
  new_node->next_node = NULL;
  aux->next_node = new_node;
  head = aux;
  return head;
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
bool search_element_ed(node_ed *head, int item)
{
  while(head != NULL)
  {
    if(head->item == item)
    {
      return true;
    }
    head = head->next_node;
  }
  return false;
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

int main()
{
  node_ed *ll_head = create_linked_list_ed();
  node_ed *ll_last = create_linked_list_ed();
  int n, i;

  for(i = 0; i < SIZE; ++i)
  {
    printf("Digite um numero:\n");
    scanf("%d", &n);
    ll_head = add_on_head_ed(ll_head,n);
    //add_on_last_ed(ll_last,n);
  }
  printf("Lista:\n");
  print_linked_list_recursive_ed(ll_head);
  printf("\n");
  return 0;
}
