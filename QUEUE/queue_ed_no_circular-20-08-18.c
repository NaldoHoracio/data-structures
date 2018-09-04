#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

struct Queue
{
  int items[MAX_QUEUE_SIZE];//Vetor de itens
  int front,rear;//Primeiro e último
};

typedef struct Queue queue_ed;//Definindo novo tipo queue_ed

//Criando a fila vazia
queue_ed* create_queue_ed()
{
  queue_ed *new_queue = (queue_ed*)malloc(sizeof(queue_ed));
  new_queue->front = 0;
  new_queue->rear = 0;
  return new_queue;//Retorna a fila
}

//Fila vazia
int is_empty_ed(queue_ed *queue)
{
  return ((queue->front == queue->rear) ? 1 : 0);//Se está vazia retorna 1; se não, retorna 0.
}

//Função para retornar o tamanho da fila
int size_queue(queue_ed *queue)
{
  return queue->rear;//O tamanho é a posição do último elemento da fila.
}

//Função para enfileirar
void enqueue_ed(queue_ed *queue, int item)
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
int dequeue_ed(queue_ed *queue)
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
int print_front_queue(queue_ed *queue)
{
  return queue->items[queue->front];
}

int main()
{
  int continuar = 1;
  int number;
  queue_ed *my_queue = create_queue_ed();//Criando a fila

  do {
    scanf("%d", &number);
    enqueue_ed(my_queue,number);
    printf("Continuar (0 - Nao/ 1 - Sim)\n");
    scanf("%d", &continuar);
  } while(continuar);

  //Imprimindo a fila
  dequeue_ed(my_queue);
  return 0;
}
