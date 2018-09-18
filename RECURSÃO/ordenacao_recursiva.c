/*
* Alterando código de ordenação para forma recursiva
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE_VECTOR 5

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

//Bubble sort não recursivo
void bubble_sort_no_recursive(int *vector, int lenght)
{
  int i, j, temp;

  for(i = 0; i < (lenght - 1); ++i)
  {
    for(j = (i+1); j < lenght; ++j)
    {
      //Trocando os valores
      if(vector[j] < vector[i])
      {
        swap(&vector[i], &vector[j]);
      }
    }
  }
}

//Bubble sort na forma recursiva
void bubble_sort_recursive(int *vector, int lenght)
{
  int i = 0, j, temp;
  if(i >= (lenght-1))
  {
    return;
  }else{
    if(j >= lenght)
    {
      bubble_sort_recursive(i+1,i+2);
    }else{

    }
  }
}

int main()
{
  int i;
  int vector[SIZE_VECTOR];

  for(i = 0; i < SIZE_VECTOR; ++i)
  {
    printf("Digite o elemento %d do vetor:\n", i);
    scanf("%d", &vector[i]);
  }
  //Aplicando bubble_sort_no_recursive
  bubble_sort_no_recursive(vector,SIZE_VECTOR);

  printf("Vetor ordenado com bubble sort:\n");
  for(i = 0; i < SIZE_VECTOR; ++i)
  {
    printf("Elemento %d -- %d\n", i, vector[i]);
  }

  return 0;
}
