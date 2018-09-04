#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

struct Queue
{
  int current_size_queue;//Tamanho atual da fila
  int tail, head;//Cabeça e cauda da fila
  int items[MAX_QUEUE_SIZE];//Vetor que irá armazenar a fila
};

typedef struct Queue queue_ed;//Definindo novo tipo queue_ed

//Criando a fila vazia
queue_ed* create_queue_ed()
{
  queue_ed *new_queue = (queue_ed*)malloc(sizeof(queue_ed));
  new_queue->current_size_queue = 0;//Tamanho inicial da fila é zero
  new_queue->head = 0;//
  new_queue->tail = 0;//
  return new_queue;//Retorna a fila
}

//Fila vazia
int is_empty_ed(queue_ed *queue)
{
  return ((queue->current_size_queue == 0) ? 1 : 0);
}

//Função para retornar o tamanho da fila
int size_queue(queue_ed *queue)
{
  return queue->current_size_queue;
}

//Função para enfileirar
void enqueue_ed(queue_ed *queue, int item)
{
  //Quando o tamanho atual é maior ou igual ao tamanho máximo da fila
  //Indica que a fila está cheia
  if(queue->current_size_queue >= MAX_QUEUE_SIZE)
  {
    printf("Queue full!\n");
    exit(1);
  }
  else
  {
    queue->tail = (queue->tail) % MAX_QUEUE_SIZE;//A nova cauda é a resto da (cauda + 1) pelo tamanho máximo
    queue->items[queue->tail] = item;//O item é guardado na posição queue->tail
    queue->tail = queue->tail+1;//Soma 1 a cauda
    queue->current_size_queue++;//O tamanho é atualizado
  }
}

//Função para desenfileirar
int dequeue_ed(queue_ed *queue)
{
  if(is_empty_ed(queue))
  {
    printf("Queue empty!\n");
    exit(1);
  }
  else
  {
    int element_dequeue = queue->items[queue->head];//O elemento da cabeça será guardado para retornar
    queue->head = (queue->head + 1) % MAX_QUEUE_SIZE;//A nova cabeça é o próximo elemento no vetor
    queue->current_size_queue--;//atualizado o tamanho da fila
    return element_dequeue;
  }
}

//Função para imprimir o elemento da cabeça da fila
int print_front_queue(queue_ed *queue)
{
  return queue->items[queue->head];
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
