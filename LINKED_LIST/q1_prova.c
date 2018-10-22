#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 5

struct Node_doubly
{
  int item;
  Node_doubly *previous_node;
  Node_doubly *next_node;
};

typedef struct Node_doubly doubly_ll;

//Creando lista dupla
doubly_ll* create_doubly_linked_list_ed()
{
  return NULL;
}

int is_empty_doubly_ll_ed(doubly_ll *head)
{
  return (head == NULL);
}

//Adicionando elemento no começo em uma lista dupla
doubly_ll* add_begin_dll(doubly_ll *head, int item)
{
  doubly_ll *new_node = (doubly_ll*) malloc(sizeof(doubly_ll));
  new_node->item = item;
  new_node->next_node = head;
  new_node->previous_node = NULL;

  if (head != NULL) head->previous_node = new_node;

  return new_node;
}

//Buscando elemento na lista dupla
bool search_doubly_ll(doubly_ll *head, int item)
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

//Imprimindo a lista de trás pra frente
void print_doubly_ll_backward(doubly_ll *tail)
{
  if(tail != NULL)
  {
    printf("%d\n", tail->item);
    print_doubly_ll_backward(tail->previous_node);
  }
}
//Imprimindo a da cabeça para a cauda
void print_doubly_ll_forward(doubly_ll *head)
{
  if(head != NULL)
  {
    printf("%d\n", head->item);
    print_doubly_ll_forward(head->next_node);
  }
}

//Removendo item e o nó do item
doubly_ll* remove_doubly_ll(doubly_ll *head, int item)
{
  doubly_ll *current = head;

  while (current != NULL && current->item != item) current = current->next_node;

  if (current == NULL) return head;

  if (head == current)
  {
    head = current->next_node;
  } else {
    current->previous_node->next_node = current->next_node;
  }
  if (current->next_node != NULL) {
    current->next_node->previous_node = current->previous_node;
  }
  free(current);
  return head;
}
//Tamanho da lista dupla
int size_doubly_ll(doubly_ll *ll)
{
  int size_list = 0;
  while (ll != NULL)
  {
    size_list++;
    ll = ll->next_node;
  }
  return size_list;
}

void swap(int *x, int *y)
{
  int aux = *x;
  *x = *y;
  *y = aux;
}

//Ordenando a lista dupla
void decrescente_bubble_v1(doubly_ll *list)
{
  int i, swapped;
  doubly_ll *current, *aux = NULL;

  if(list == NULL) return;

  //Laço para percorrer a lista
  do {
    swapped = 0;
    current = list;
    //Laço para ordenar a lista e deslocar aux da cauda para frente
    while(current->next_node != aux)
    {
      if(current->item < current->next_node->item)
      {
        swap(&current->item, &current->next_node->item);
      }
      current = current->next_node;
    }
    aux = current;
  } while(swapped == 1);
}

//Ordenando a lista dupla
void decrescente_bubble_v2(doubly_ll *list, int size_list)
{
  int i, j;
  for (j = 1; j <= size_list; j++)
  {
    for (i = 0; i < (size_list - 1); i++)
    {
      if (list->item < list->next_node->item) swap(&list->item,&list->next_node->item);
    }
  }
}

int main()
{
  doubly_ll *ll_doubly = create_doubly_linked_list_ed();
  //node_ed *ll_last = create_linked_list_ed();
  int n, i, continuar = 1;

  do {
    printf("Digite um numero:\n");
    scanf("%d", &n);
    ll_doubly = add_begin_dll(ll_doubly,n);
    printf("Continuar? (0 - Nao/ 1 - Sim)\n");
    scanf("%d", &continuar);
  } while(continuar == 1);

  printf("Tamanho da lista:\n");
  int size_list = size_doubly_ll(ll_doubly);
  printf("%d\n", size_list);
  printf("\n");

  printf("Lista dupla antes da ordenacao:\n");
  print_doubly_ll_forward(ll_doubly);
  printf("\n");

  //Chamando função para ordenar
  decrescente_bubble_v1(ll_doubly);

  printf("Lista dupla em ordem decrescente:\n");
  print_doubly_ll_forward(ll_doubly);

  return 0;
}
