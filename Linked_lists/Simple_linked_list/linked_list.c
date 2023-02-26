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
  if(!is_empty(head))
  {
    printf("%d\n", head->item);
    print_linked_list(head->next_node);
  }
}

int main()
{
  int op;
  struct node* list = create_linked_list();
  int item;
  printf("Digite a opcao desejada:\n");
  printf("1 - Adicionar elemento\n2 - Buscar elemento\n3 - Remover elemento\n4 - Imprimir a lista\n");
  scanf("%d", &op);
  
  do
  {
    switch (op)
    {
    case 1:
      printf("Digite o numero que deseja inserir:\n");
      scanf("%d", &item);
      list = add(list,item);
      break;
    case 2:
      printf("Digite um numero que voce deseja encontrar:\n");
      scanf("%d", &item);
      list = search(list,item);
      if(!is_empty(list)) printf("O elemendo %d existe.\n", item);
      else printf("O elemento %d nao existe.\n", item);
      break;
    case 3:
      printf("Digite um numero que voce deseja remover:\n");
      scanf("%d", &item);
      list = remove(list,item);
      break;
    case 4:
      printf("LISTA\n");
      print_linked_list(list);
      break;
    default:
      printf("Essa opcao nao existe! Digite um numero entre 1 e 4.\n");
      break;
    }
    printf("Digite a opcao desejada:\n");
    printf("1 - Adicionar elemento\n2 - Buscar elemento\n3 - Remover elemento\n4 - Imprimir a lista\n");
    scanf("%d", &op);
  } while (1);
  

  return 0;
}