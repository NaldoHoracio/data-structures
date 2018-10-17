#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 5

//Estrutura node
struct Node_c
{
  int item;
  Node_c *next_node;
};
//Definindo tipo node
typedef struct Node_c node_c;
//Criando a lista encadeada - modo 1
node_c* create_linked_list_circular()
{
  return NULL;
}

//Lista vazia
int is_empty_ed(node_c *head)
{
  return (head == NULL);
}

node_c* add_empty_circular(node_c *head, int item)
{
  // This function is only for empty list
  if (head != NULL)
    return head;

  // Creating a node dynamically.
  node_c *temp = (node_c*)malloc(sizeof(node_c));

  // Assigning the data.
  temp->item = item;
  head = temp;

  head->next_node = head;

  return head;
}

node_c* add_begin_circular_list(node_c *head, int item)
{
  if (head == NULL) return add_empty_circular(head, item);

  // Creating a node dynamically.
  node_c *temp = (node_c*)malloc(sizeof(node_c));

  // Assigning the data.
  temp->item = item;

  // Adjusting the links.
  temp->next_node = head->next_node;
  head->next_node = temp;

  return head;
}
//Imprimindo a lista - forma nao recursiva
void print_linked_list_circular(node_c *head)
{
  node_c *aux;

  if(head == NULL)
  {
    printf("Lista vazia.\n");
    return;
  }
  aux = head->next_node;

  do {
    printf("%d\n", aux->item);
    aux = aux->next_node;
  } while(aux != head->next_node);
}

//Buscando elemento
bool search_circular(node_c *head, int item)
{
  node_c *temp = head;
  if(head != NULL)
  {
    do {
      if(temp->item == item) return true;
      temp = temp->next_node;
    } while(temp != head);
  }
  return false;
}

int main()
{
  node_c *ll_circular = create_linked_list_circular();
  //node_ed *ll_last = create_linked_list_ed();
  int n, i;

  for(i = 0; i < SIZE; ++i)
  {
    printf("Digite um numero:\n");
    scanf("%d", &n);
    ll_circular = add_begin_circular_list(ll_circular,n);
    //add_on_last_ed(ll_last,n);
  }
  printf("Lista:\n");
  print_linked_list_circular(ll_circular);
  printf("\n");

  printf("Digite um numero que voce deseja procurar:\n");
  scanf("%d", &n);
  if(search_circular(ll_circular, n) == true) printf("O elemento %d esta na lista.\n", n);
  else printf("O elemento %d nao esta na lista.\n", n);

  //printf("Digite um numero que voce deseja remover:\n");
  //scanf("%d", &n);

  /*
  if(search_element_ed(ll_head, n) == true)
  {
  remove_node_ed(ll_head, n);
  printf("Lista sem o elemento %d:\n", n);
  print_linked_list_recursive_ed(ll_head);
  printf("\n");
}else
{
printf("O elemento %d nao esta na lista.\n", n);
printf("Lista:\n");
print_linked_list_recursive_ed(ll_head);
printf("\n");
}
*/

return 0;
}
