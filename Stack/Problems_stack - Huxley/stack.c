#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CURRENT_SIZE 100

//Estrutura pilha
struct Stack
{
  int current_size;
  int items[CURRENT_SIZE];
};
//Definindo novo tipo pilha
typedef struct Stack stack_ed;
//Criando a pilha
stack_ed* create_stack_ed()
{
    stack_ed *stack = (stack_ed*)malloc(sizeof(stack_ed));
    stack->current_size = 0;
    return stack;
}
//Pilha vazia
int is_empty_ed(stack_ed *stack)
{
    return (stack->current_size == 0);
}
//Inserindo na pilha um elemento
void push_stack_ed(stack_ed *stack, int item)
{
  //Verificando se a pilha está cheia
  if(stack->current_size == CURRENT_SIZE)
  {
    printf("Stack full!\n");
  }//Se não estiver cheia, insere na posição + 1
  else
  {
    stack->items[stack->current_size++] = item;
  }
}
//Removendo da pilha um elemento
int pop_ed(stack_ed *stack)
{
    if(is_empty_ed(stack))
    {
        //printf("Empty stack!\n");
        return -1;
    }
    else return stack->items[--stack->current_size];
}
//Verificando topo da pilha
int peek_ed(stack_ed *stack)
{
   if(!is_empty_ed(stack))
       return stack->items[stack->current_size - 1];
   else return -1;
}

int main()
{
  stack_ed *my_stack = create_stack_ed();//Criando a pilha
  stack_ed *my_stack_upside_down = create_stack_ed();//Pilha da cópia
  int item, cont = 0;
  printf("Digite um número:\n");
  scanf("%d", &item);

  while(item != 0)
  {
    if(item > 0)
    {
      push_stack_ed(my_stack,item);
    }
  }

  printf("Elemento do topo: %d\n", peek_ed(my_stack));

  while(!is_empty_ed(my_stack))
  {
    printf("element[%d] --> ", my_stack->current_size);
    printf("%d\n", pop_ed(my_stack));
  }
  return 0;
}
