/*
* Fila Circular
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

struct Queue
{
  int rear, front;//Primeiro e último elemento da fila
  int items[MAX_QUEUE_SIZE];//Vetor que irá armazenar a fila
};

typedef struct Queue queue_ed;//Definindo novo tipo queue_ed

//Criando a fila vazia
queue_ed* create_queue_ed()
{
  queue_ed *new_queue = (queue_ed*)malloc(sizeof(queue_ed));
  new_queue->front = -1;//Primeiro elemento da fila
  new_queue->rear = -1;//Último elemento da fila
  return new_queue;//Retorna a fila
}

//Fila vazia
int is_empty_queue_ed(queue_ed *queue)
{
  return ((queue->front == queue->rear) ? 1 : 0);
}

//Função para retornar o tamanho da fila
int size_queue(queue_ed *queue)
{
  //Quando o final ainda não alcançou o final do vetor
  if(queue->front <= queue->rear)
  {
    //O tamanho é a diferença entre o último e o primeiro elemento
    return (queue->rear - queue->front);
  }
  //Se não, o resultado é a soma
  else return (queue->front + queue->rear);
}

//Função para enfileirar
void enqueue_ed(queue_ed *queue, int item)
{
  // Inversão das posições dos ponteiros. Se o inal do vetor já foi
  //alcançado, então retorna-se ao início do vetor
  if(queue->rear == (MAX_QUEUE_SIZE-1))
  {
    queue->rear = 0;
  }
  //Se não, soma 1 a esse ponteiro
  else
  {
    queue->rear++;
  }
  //Se o primeiro é igual ao último
  //Fila cheia
  if(queue->rear == queue->front)
  {
    printf("Queue full!\n");
  }//Se não, insere na posição que está vazia
  {
    queue->items[queue->rear] = item;//Insere na última posição (que está vazia e já foi somada)
  }
}

//Função para desenfileirar
int dequeue_ed(queue_ed *queue)
{
  int i;
  if(is_empty_queue_ed(queue))
  {
    printf("Queue empty!\n");
    exit(1);
  }
  //Se o final já foi alcançado
  //então retorna oa início do vetor
  if(queue->front == (MAX_QUEUE_SIZE - 1))
  {
    queue->front = 0;
  }
  else
  {
    queue->front++;
  }
  //Retorna o primeiro elemento da fila
  return (queue->items[queue->front]);
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

  enqueue_ed(my_queue,1);
  enqueue_ed(my_queue,2);
  enqueue_ed(my_queue,3);
  enqueue_ed(my_queue,4);
  enqueue_ed(my_queue,5);

  printf("%d\n", dequeue_ed(my_queue));
  return 0;
}
