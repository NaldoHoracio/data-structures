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
//Verificando se a expressão é bem formada
int well_formed_expression(char s[])
{
  int i = 0;
  stack_ed *stk = create_stack_ed();//Criando a pilha

  //Verificando a expressão até seu tamanho
  for(i = 0; i < strlen(s); ++i)
  {
    //Se o símbolo é fechando parênteses
    if(s[i] == ')')
    {
      //Se a pilha está vazia ou tem colchetes abrindo - expressão não é bem formada
      if (is_empty_ed(stk) || peek_ed(stk) == '[')
      {
        return -1;
        break;
      }
      //Se o elemento do topo é um parênteses abrindo, retira do topo da pilha
      else if(peek_ed(stk) == '(') pop_ed(stk);
    }
    //Se o símbolo é fechando colchetes
    else if(s[i] == ']')
    {
      //Verifica se a pilha está vazia ou se tem um parênteses abrindo
      if (is_empty_ed(stk) || peek_ed(stk)=='(')
      {
        return -1;
        break;
      }
      //Se o elemento do topo é colchetes abrindo, remove da pilha
      else if(peek_ed(stk) == '[') pop_ed(stk);
    }
    //Avalia se o elemento é um parênteses ou colchetes abrindo e coloca na pilha
    else if (s[i] == '(' || s[i] == '[')
    {
      push_stack_ed(stk, s[i]);
    }
    else if(s[i]==' ')
    {
      continue;//Comando para continuar
      //push(stk, s[i]);
      //pop(stk);
    }
  }
  //Se a pilha não está vazia, então a expressão não é bem formada
  //Retorna -1 porque não é bem formada
  if(!is_empty_ed(stk))
  {
    return -1;
    //freeStack(stk);
  }
  //Se a pilha está vazia, então a expressão é bem formada
  else return 1;
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

int main()
{
  int i, n, t;//i - contador; n - numero de expressões a serem digitadas
  //puts("Digite o numero N de expressões a serem digitadas:");
  scanf("%d", &n);
  getchar();//Lendo \n
  //puts("Digite as cadeias caracteres:");
  for(i = 0; i < n; ++i)
  {

    char word[256];
    t = read_string(word,MAXSTR);
    //gets(word);
    (well_formed_expression(word) == 1) ? printf("Yes\n") : printf("No\n");
    //if(well_formed_expression(word) == 1) printf("Yes\n");
    //else if(well_formed_expression(word) == -1) printf("No\n");
    //printf("Digite a sequencia %d.\n", i+2);
    //printf("Ainda lhe restam %d sequencias a serem digitadas.\n", n - i - 2);
  }
  return 0;
}
