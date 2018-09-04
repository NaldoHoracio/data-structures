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

int main()
{
  stack_ed *my_stack = create_stack_ed();//Criando a pilha
  push_stack_ed(my_stack,6);
  push_stack_ed(my_stack,7);
  push_stack_ed(my_stack,8);
  push_stack_ed(my_stack,9);
  push_stack_ed(my_stack,10);
  int continues = 1;

  //Apenas imprimindo a pilha
  while (continues)
  {
    printf("Pilha impressa:\n");
    print_stack_ed(my_stack);
    printf("\n");
    printf("Deseja imprimir a pilha? (1 - Sim: 0 - Não):\n");
    scanf("%d", &continues);
  }
  /*
  printf("Removendo os elementos da pilha:\n");
  //Destruindo a pilha
  while (!is_empty_ed(my_stack))
  {
    printf("Elemento %d da pilha: %d.\n", my_stack->current_size, pop_ed(my_stack));
  }
  */
  return 0;
}
