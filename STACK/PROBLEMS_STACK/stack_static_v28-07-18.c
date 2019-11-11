#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CURRENT_SIZE 1000

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
//Removendo da pilha um elemento - destroi a pilha
int pop_ed(stack_ed *stack)
{
    if(is_empty_ed(stack))
    {
        //printf("Empty stack!\n");
        return -1;
    }
    else return stack->items[--stack->current_size];
}
void print_stack_ed(stack_ed *stack)
{
  int i;

  for(i = (stack->current_size-1); i >= 0; --i)
  {
    printf("Elemento %d da pilha: %d.\n",i,(stack->items[i]));
  }
}
//Verificando topo da pilha
int peek_ed(stack_ed *stack)
{
   if(!is_empty_ed(stack))
       return stack->items[stack->current_size - 1];
   else return -1;
}

int size_stack(stack_ed *stack)
{
  return (stack->current_size);
}

int numb;
stack_ed *stk_pair = create_stack_ed();

void pair_element_recursive(stack_ed *stack)
{
  if(size_stack(stack) > 0)
  {
    numb = pop_ed(stack);
    if(numb % 2 == 0 && numb != 0)
    {
      push_stack_ed(stk_pair,numb);
    }
    pair_element_recursive(stack);
  }else{
    return;
  }
}
/*
//Pilha invertida
stack_ed *stk_pair_inver = create_stack_ed();

void invert_stack(stack_ed *stack)
{
  int pair_number;
  while (!is_empty_ed(stack))
  {
    pair_number = pop_ed(stack);
    push_stack_ed(stk_pair_inver, pair_number);
  }
}
*/
int main()
{
  stack_ed *my_stack = create_stack_ed();//Criando a pilha
  int continuar = 1;
  int number;

  do {
    printf("Digite um numero:\n");
    scanf("%d", &number);
    push_stack_ed(my_stack,number);
    printf("Continuar?(0 - Nao/1 - Sim):\n");
    scanf("%d", &continuar);
    /* code */
  } while(continuar == 1);

  pair_element_recursive(my_stack);

  //Se a pilha está vazia
  if(is_empty_ed(stk_pair)){printf("Pilha vazia!\n");}
  else{//Se a pilha não está vazia
    printf("Pilha com elementos pares e invertida:\n");
    print_stack_ed(stk_pair);
  }

  return 0;
}
