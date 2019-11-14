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

//Adicionando elemento em uma lista dupla
doubly_ll* add_double_ll(doubly_ll *head, int item)
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
    print_doubly_ll_backward(tail->previous_node);
    printf("%d\n", tail->item);
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

int main()
{
  doubly_ll *ll_doubly = create_doubly_linked_list_ed();
  //node_ed *ll_last = create_linked_list_ed();
  int n, i;

  for(i = 0; i < SIZE; ++i)
  {
    printf("Digite um numero:\n");
    scanf("%d", &n);
    ll_doubly = add_double_ll(ll_doubly,n);
    //add_on_last_ed(ll_last,n);
  }
  printf("Lista de tras pra frente:\n");
  print_doubly_ll_backward(ll_doubly);
  printf("\n");

  printf("Lista de frente pra tras:\n");
  print_doubly_ll_forward(ll_doubly);
  printf("\n");


  printf("Digite um numero que voce deseja procurar:\n");
  scanf("%d", &n);
  if(search_doubly_ll(ll_doubly,n) == true) printf("O elemento %d esta na lista.\n", n);
  else printf("O elemento %d nao esta na lista.\n", n);

  printf("Digite um numero que voce deseja remover:\n");
  scanf("%d", &n);

  if(search_doubly_ll(ll_doubly,n) == true)
  {
    remove_doubly_ll(ll_doubly,n);
    printf("Lista de tras pra frente:\n");
    print_doubly_ll_backward(ll_doubly);
    printf("\n");

    printf("Lista de frente pra tras:\n");
    print_doubly_ll_forward(ll_doubly);
    printf("\n");
  }else
  {
    printf("O elemento %d nao esta na lista.\n", n);

    printf("Lista de tras pra frente:\n");
    print_doubly_ll_backward(ll_doubly);
    printf("\n");

    printf("Lista de frente pra tras:\n");
    print_doubly_ll_forward(ll_doubly);
    printf("\n");
  }
  return 0;
}
