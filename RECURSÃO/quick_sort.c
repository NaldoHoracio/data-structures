#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE_VECTOR 5

void swap_function(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void quick_sort_no_recursive(int *vector, int began, int end)
{
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = vector[(began + end) / 2];
	while(i <= j)
	{
		while(vector[i] < pivo && i < end)
		{
			i++;
		}
		while(vector[j] > pivo && j > began)
		{
			j--;
		}
		if(i <= j)
		{
			swap_function(&vector[i], &vector[j]);
			i++;
			j--;
		}
	}
	if(j > began)
		quick_sort_no_recursive(vector, began, j+1);
	if(i < end)
		quick_sort_no_recursive(vector, i, end);
}

//Partition
int partition(int *vector, int left, int right)
{
  int i;
  int middle = left;   // m: indice do ponto médio

	i = left + 1;
	if(i <= right)
	{
		if(vector[i] < vector[left])
		{
		 middle++;
		 swap_function(&vector[i], &vector[middle]);
		}
		i++;
	}
	swap_function(&vector[left],&vector[middle]);
  return middle;
}

//Quick sort recursivo
void quick_sort_recursive(int *vector, int began, int end)
{
  int middle;

  //Caso base
  if(began >= end) return;
	//Pivô
	middle = partition(vector,began,end);
  //Ordena até SIZE_VECTOR - 1
  quick_sort_recursive(vector,began,middle-1);
  //Ordena de SIZE_VECTOR
  quick_sort_recursive(vector,middle+1,end);
}

int main()
{
  int i, vector[SIZE_VECTOR];
  printf("Digite os numeros:\n");

  for(i = 0; i < SIZE_VECTOR; ++i)
  {
    scanf("%d", &vector[i]);
  }
  //Usando quick_sort nao recursivo
  quick_sort_no_recursive(vector,0,SIZE_VECTOR);
  printf("Vetor ordenado com quick sort:\n");
  for(i = 0; i < SIZE_VECTOR; ++i)
  {
    printf("Elemento %d --> %d\n", i, vector[i]);
  }
}
