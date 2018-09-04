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
//Lendo a string
#define MAXSTR 256
int read_string(char s[], int max_str)
{
   	int i = 0;
   	char c;

   	for (i = 0; i < (max_str - 1); i++)
	{
	   	c = fgetc(stdin);
		/*
		if ((c == '\n') && (i == 0))
		{
	       i = i - 1;
	       continue;
	   	}
		*/
	   	if (c == '\n') break;
      s[i] = c;
  }
  s[i] = 0;
  return (i);
}
//Verificar se é operador ou operando
int is_operand(char c)
{
  if(c != '*' || c != '/' || c != '+' || c != '-') return 1;//É número, então é operando
  else return 0;//Não é número, então é operador

}
//Verificando a precedencia do operador
int precedence_operador(char op)
{
  switch (op) {
    case '*':
      return 2;
      break;
    case '/':
      return 2;
      break;
    case '+':
      return 1;
      break;
    case '-':
      return 1;
      break;
  }
  return -1;
}
//Função para converter de infixa para posfixa
int infix_to_posfix(char *expression)
{
  int i, j;
  stack_ed *stk_expression = create_stack_ed();

  for(i = 0, j = -1; expression[i]; ++i)
  {
    //Se é um número, já coloca na string
    if(is_operand(expression[i]) == 1)
    {
      expression[++j] = expression[i];//Se é operando, escreve na string
    }
    //Se não se for um parênteses abrindo, coloca na pilha
    else if(expression[i] == '(')
    {
      push_stack_ed(stk_expression,expression[i]);
    }
    //Se não se for um parênteses fechando
    //Faça
    else if(expression[i] == ')')
    {
      while(!is_empty_ed(stk_expression) && peek_ed(stk_expression) != '(')
      {
        expression[++j] = pop_ed(stk_expression);
      }
      if(!is_empty_ed(stk_expression) && peek_ed(stk_expression) != '(')
      {
        return -1;//Expressão inválida
      }
      else pop_ed(stk_expression);
    }
    else // an operator is encountered
    {
      while (!is_empty_ed(stk_expression) && precedence_operador(expression[i]) <= precedence_operador(peek_ed(stk_expression)))
      {
          expression[++j] = pop_ed(stk_expression);
      }
      push_ed(stk, expression[i]);
    }
  }
  while(!is_empty_ed(stk_expression))
  {
    expression[++j] = pop_ed(stk_expression);
  }
  expression[++j] = '\0';
  printf("Expressão pósfixa: %s.\n", expression);
}
//Função principal
int main()
{
  int i, n, t;//i - contador; n - numero de expressões a serem digitadas
  //puts("Digite o numero N de expressões a serem digitadas:");
  scanf("%d", &n);
  getchar();//Lendo \n
  //puts("Digite as cadeias caracteres:");
  t = read_string(word,MAXSTR);//Lendo string
  return 0;
}
