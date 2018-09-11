/*
* Create by Edvonaldo
* September 11th, 2018.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_QUEUE_SIZE 100

struct item_priority
{
  int item;
  int priority;
};

typedef struct item_priority i_p;//Item com prioridade

struct PQ
{
  int front, rear;
  i_p items[MAX_QUEUE_SIZE];
};

typedef struct PQ pq_ed;//Definindo o tipo q_ed

pq_ed* create_queue_ed()
{
  pq_ed *new_queue = (pq_ed*)malloc(sizeof(pq_ed));
  new_queue->front = 0;
  new_queue->rear = 0;
  return new_queue;//Retorna a fila
}

//Fila vazia
int is_empty_ed(pq_ed *queue)
{
  return ((queue->front == queue->rear) ? 1 : 0);//Se está vazia retorna 1; se não, retorna 0.
}

//Função para retornar o tamanho da fila
int size_queue(pq_ed *queue)
{
  return queue->rear;//O tamanho é a posição do último elemento da fila.
}

//Função para enfileirar
void enqueue_ed(pq_ed *queue, int item, int priority)
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
    queue->items[queue->rear].item = item;//Isere na posição rear e depois soma 1 para atualizar o tamanho
    queue->items[queue->rear].priority = priority;//Insere a prioridade
    queue->rear++;//Soma 1 para atualizar o indice do ultimo elemento
  }
}

//Função para desenfileirar
int dequeue_ed(pq_ed *queue)
{
  int i, element_dequeue, priority_element;
  if(is_empty_ed(queue))
  {
    printf("Queue empty!\n");
    exit(1);
  }
  element_dequeue = queue->items[0].item;//Guardando o primeiro elemento da fila
  priority_element = queue->items[0].priority;//Guardando a prioridade do elemento
  for(i = 0; i < queue->rear; ++i)
  {
    queue->items[i] = queue->items[i+1];//Faz a fila andar - o queue->items[0] recebe o queue->items[0+1]...
    //queue->items[i].priority = queue->items[i+1].priority;
    //Já troca tambem a prioridade
  }
  queue->rear--;//Subtrai 1 do rear atualizando a posição do último elemento
  return element_dequeue;
}

//Função para imprimir o elemento da cabeça da fila
int print_front_queue(pq_ed *queue)
{
  return queue->items[queue->front].item;
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
  int continuar = 1, i, priority;
  char n[50];
  pq_ed *q = create_queue_ed();//Criando fila

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

    printf("Digite a prioridade:\n");
    scanf("%d", &priority);
    if(priority != 0 && priority != 1)
    {
      printf("Prioridade invalida!\n");
      exit(1);
    }else
    {
        enqueue_ed(q,number,priority);//Colocando numero na fila
    }

    printf("Deseja continuar?(0 - Nao/1 - Sim):\n");
    scanf("%d", &continuar);
  } while(continuar == 1);

  printf("Fila de prioridade:\n");
  while(!is_empty_ed(q))
  {
    printf("Elemento")
  }

  return 0;
}
