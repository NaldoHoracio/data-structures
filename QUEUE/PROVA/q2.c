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
void dequeue_ed(pq_ed *queue)
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
  printf("Elemento: %d - %d (prioridade).\n", element_dequeue, priority_element);
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
//Função de troca de valores
void swap_pq(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

//Selection sort para colocar a fila em ordem crescente de prioridade
void selection_sort_pq(pq_ed *queue)
{
  int i, j, min;

  for(i = 0; i < size_queue(queue); ++i)
  {
    min = i;
    for(j = i + 1; j < size_queue(queue); ++j)
    {
      if(queue->items[j].priority < queue->items[min].priority)
      {
        min = j;
      }
    }
    //Troca a prioridade e troca o item para que sua proridade não seja alterada
    swap_pq(&queue->items[i].priority, &queue->items[min].priority);
    swap_pq(&queue->items[i].item, &queue->items[min].item);
  }
}

int main()
{
  int continuar = 1, i;
  char n[50], priority[1];
  pq_ed *q = create_queue_ed();//Criando fila principal
  pq_ed *q_ordered = create_queue_ed();//Criando fila que vai ser ordenada

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
    scanf("%s", priority);
    getchar();//Lendo \n
    for(i = 0; i < strlen(priority); ++i)
    {
      if(priority[i] != '0' && priority[i] != '1')
      {
        printf("Prioridade invalida!\n");
        exit(1);
      }else
      {
          int priority_number = atoi(priority);
          enqueue_ed(q,number,priority_number);//Colocando numero na fila
          enqueue_ed(q_ordered,number,priority_number);
      }
    }

    printf("Deseja continuar?(0 - Nao/1 - Sim):\n");
    scanf("%d", &continuar);
  } while(continuar == 1);

  printf("Fila de prioridade nao ordenada:\n");
  while(!is_empty_ed(q))
  {
    dequeue_ed(q);
  }

  printf("\nOrdenando a fila de prioridades em ordem crescente...\n");
  selection_sort_pq(q_ordered);
  printf("\n");

  printf("Fila de prioridade em ordem crescente:\n");

  if(is_empty_ed(q_ordered)){printf("A fila esta vazia!\n");}
  else{
    while (!is_empty_ed(q_ordered))
    {
      dequeue_ed(q_ordered);
    }
  }

  return 0;
}
