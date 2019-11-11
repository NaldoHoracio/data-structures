#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE_VECTOR 10

//Merge
void merge(int vector[], int beggin, int middle, int end) {
    int beggin1 = beggin, beggin2 = middle + 1, beggin_aux = 0, size = end-beggin+1;
    int *vector_aux;
    vector_aux = (int*)malloc(size * sizeof(int));
    while(beggin1 <= middle && beggin2 <= end)
    {
        if(vector[beggin1] < vector[beggin2]) {
            vector_aux[beggin_aux] = vector[beggin1];
            beggin1++;
        } else {
            vector_aux[beggin_aux] = vector[beggin2];
            beggin2++;
        }
        beggin_aux++;
    }
    while(beggin1 <= middle)
    {  //Caso ainda haja elementos na primeira metade
        vector_aux[beggin_aux] = vector[beggin1];
        beggin_aux++;
        beggin1++;
    }
    while(beggin2 <= end)
    {   //Caso ainda haja elementos na segunda metade
        vector_aux[beggin_aux] = vector[beggin2];
        beggin_aux++;
        beggin2++;
    }
    for(beggin_aux = beggin; beggin_aux <= end; ++beggin_aux)
    {    //Move os elementos de volta para o vetor original
        vector[beggin_aux] = vector_aux[beggin_aux-beggin];
    }

    free(vector_aux);
}
//Merge recursivo
void merge_recursive(int vector[], int middle, int end, int aux[])
{
    int i, j, k;
    if (i <= middle && (j > end || vector[i] < vector[j]))
    {
        aux[k] = vector[i];
        merge_recursive(vector, middle, end, aux);
    } else if (j <= end)
    {
        aux[k] = vector[j];
        merge_recursive(vector, middle, end, aux);
    }
}
//Merge sort recursivo
void merge_sort_recursive(int vector[], int beggin, int end)
{
    int size = end - beggin + 1;
    int *aux = (int*)malloc(size * sizeof(int));
    if (beggin < end) {
        int middle = (end + beggin)/2;
        merge_sort_recursive(vector, beggin, middle);
        merge_sort_recursive(vector, middle + 1, end);
        merge_recursive(vector, beggin, middle, aux);
    }
}

int main()
{
  int i;
  int vector[SIZE_VECTOR];

  for(i = 0; i < SIZE_VECTOR; ++i)
  {
      printf("Digite o lemento %d\n", i);
      scanf("%d", &vector[i]);
  }

  //Merge sort não recursivo
  merge_sort_recursive(vector,0,SIZE_VECTOR-1);

  printf("Vetor ordenado com merge sort:\n");
  for(i = 0; i < SIZE_VECTOR; ++i)
  {
    printf("Elemento %d --> %d\n", i, vector[i]);
  }
  return 0;
}
