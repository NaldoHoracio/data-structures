/*
* Create by Edvonaldo
* September 11th, 2018.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_QUEUE_SIZE 100

struct queue
{
  int front, rear;
  int items[MAX_QUEUE_SIZE];
};

typedef struct queue q_ed;//Definindo o tipo q_ed

q_ed* create_queue_ed()
{
  q_ed *new_queue = (q_ed*)malloc(sizeof(q_ed));
  new_queue->front = 0;
  new_queue->rear = 0;
  return new_queue;//Retorna a fila
}

//Fila vazia
int is_empty_ed(q_ed *queue)
{
  return ((queue->front == queue->rear) ? 1 : 0);//Se está vazia retorna 1; se não, retorna 0.
}

//Função para retornar o tamanho da fila
int size_queue(q_ed *queue)
{
  return queue->rear;//O tamanho é a posição do último elemento da fila.
}

//Função para enfileirar
void enqueue_ed(q_ed *queue, int item)
{
  //Quando o tamanho atual é maior ou igual ao tamanho máximo da fila
  //Indica que a fila está cheia
  if(queue->rear >= MAX_QUEUE_SIZE)
  {
    printf("Queue full!\n");
    exit(1);
  }
  else
  {
    queue->items[queue->rear++] = item;//Isere na posição rear e depois soma 1 para atualizar o tamanho
  }
}

//Função para desenfileirar
int dequeue_ed(q_ed *queue)
{
  int i, element_dequeue;
  if(is_empty_ed(queue))
  {
    printf("Queue empty!\n");
    exit(1);
  }
  element_dequeue = queue->items[0];//Guardando o primeiro elemento da fila
  for(i = 0; i < queue->rear; ++i)
  {
    queue->items[i] = queue->items[i+1];//Faz a fila andar - o queue->items[0] recebe o queue->items[0+1]...
  }
  queue->rear--;//Subtrai 1 do rear atualizando a posição do último elemento
  return element_dequeue;
}

//Função para imprimir o elemento da cabeça da fila
int print_front_queue(q_ed *queue)
{
  return queue->items[queue->front];
}

//Função para avaliar uma expressão
//Se for um numero entre 0 e 9 o caracter eh correto e retorna 1
//Se nao for, retorna 0
int valid_expression(char c)
{
  int is_valid = 0;
  if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4')
  {
    is_valid = 1;
  }
  else if(c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
  {
    is_valid = 1;
  }else
  {
    is_valid = 0;
  }
  return is_valid;
}

int main()
{
  int continuar = 1, i;
  char n[50];
  q_ed *q = create_queue_ed();//Criando fila

  do {
    printf("Digite um numero:\n");
    scanf("%s", n);
    getchar();//Lendo \n

    //Testando a entrada
    for(i = 0; i < strlen(n); ++i)
    {
      if(valid_expression(n[i]) == 1)
      {
        continue;
      }else{
        printf("Expressao invalida!\n");
        exit(1);
      }
    }
    int number;
    number = atoi(n);//Transforma a string cujos caracteres sao digitos em um inteiro e coloca em number
    enqueue_ed(q,number);//Colocando numero na fila

    printf("Deseja continuar?(0 - Nao/1 - Sim):\n");
    scanf("%d", &continuar);
  } while(continuar == 1);

  q_ed *q_pair = create_queue_ed();

  for(i = 0; i < size_queue(q); ++i)
  {
    int element = q->items[i];

    if(abs(element) % 2 == 0 && abs(element) != 0)
    {
      enqueue_ed(q_pair,q->items[i]);
    }
  }
  printf("Fila original:\n");
  while (!is_empty_ed(q))
  {
    printf("%d\n", dequeue_ed(q));
  }
  printf("\n");
  printf("Fila apenas com numeros pares:\n");
  if(is_empty_ed(q_pair)){printf("Nao ha elementos pares na fila!\n");}
  else
  {
    while (!is_empty_ed(q_pair))
    {
      printf("%d\n", dequeue_ed(q_pair));
    }
  }
  return 0;
}
