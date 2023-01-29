/*
  * Create by NaldoHorácio
  * 04 September 2018
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_PQ_SIZE 100

struct item_PQ
{
  int data;//Dado da fila
  int priority;//Guarda a prioridade do dado
};

typedef struct item_PQ item_pq;//Defino o novo tipo

struct priority_queue
{
  item_pq items[MAX_PQ_SIZE];//Vetor em que cada elemento tem o dado e a prioridade do dado
  int rear, front;//Frente e trás
};

typedef struct priority_queue pq_ed;//Define novo tipo pq_ed
