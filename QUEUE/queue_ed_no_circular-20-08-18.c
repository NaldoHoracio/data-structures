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

//Invertendo a fila
void invert_queue(queue_ed *queue)
{
  int i;
  queue_ed *queue_aux = create_queue_ed();//Criando uma fila auxiliar

  for(i = (queue->rear-1); i >= 0; --i)
  {
    //Enfileirando: o ultimo eh o primeiro, o penultimo eh o segundo...
    enqueue_ed(queue_aux,queue->items[i]);
  }
  //Realocando na fila
  for(i = 0; i < queue_aux->rear; ++i)
  {
    enqueue_ed(queue,queue_aux->items[i]);
  }
}

int main()
{
  int i, number;
  queue_ed *queue = create_queue_ed();//Cria a fila vazia

  for(i = 0; i < 5; ++i)
  {
    printf("Digite um numero:\n");
    scanf("%d", &number);//Lendo numero
    enqueue_ed(queue,number);
  }
  printf("O tamanho da fila eh: %d\n", size_queue(queue));
  printf("A fila eh:\n");
  while(!is_empty_ed(queue))
  {
    //Imprimindo a fila
    printf("%d\n", dequeue_ed(queue));
  }
  printf("\n");
  printf("Fila invertida:\n");
  invert_queue(queue);//Chamando a função para inverter a fila
  return 0;
}
