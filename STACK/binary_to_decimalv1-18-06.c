#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  stack_ed *binary_digits_stack = create_stack_ed();
  int number, dividendo, divisor, quociente, resto;
  printf("Digite um número:\n");
  scanf("%d", &number);
  divisor = 2;
  dividendo = number;

  while(dividendo > 1)
  {
    quociente = dividendo/2;
    resto = dividendo%2;//Pega o resto da divisão por 2 - vai compor o número em binário
    push_stack_ed(binary_digits_stack,resto);//Colocando o valor na pilha
    dividendo = quociente;
    printf("O resto: %d\n", resto);
    printf("Dividendo %d\n", dividendo);
  }
  push_stack_ed(binary_digits_stack,1);
  printf("O número %d em binário é: ", number);
  while(!is_empty_ed(binary_digits_stack))
  {
    printf("%d", pop_ed(binary_digits_stack));
  }
  printf("\n");

  return 0;
}
