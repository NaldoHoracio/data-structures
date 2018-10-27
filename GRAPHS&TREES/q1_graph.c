#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_VERTEX 100

/*
bool edge[MAX_VERTEX][MAX_VERTEX];
//Adicionando uma aresta
void add_edge(bool edge[][], int i, int j)
{
  edge[i][j] = true; // ou true
}
//Removendo uma aresta
void remove_edge(bool edge[][MAX_VERTEX], int i, int j)
{
  edge[i][j] = false; // ou false
}
//Verificando se a aresta existe
bool has_edge(bool edge[][MAX_VERTEX], int i, int j)
{
  return (edge[i][j]);
}
*/
int main()
{
  int n_vertex, i, j, v1, v2;
  int continuar;
  printf("Digite o numero de vertices:\n");
  scanf("%d", &n_vertex);
  bool matrix_adj[n_vertex][n_vertex];

  // Inicializando a matriz de adjacência
  for(i = 0; i < n_vertex; ++i)
  {
    for(j = 0; j < n_vertex; ++j) matrix_adj[i][j] = false;
  }

  do {
    printf("Digite as arestas que deseja ligar:\n");
    scanf("%d%d", &v1, &v2);

    //Verifica se as arestas estao dentro do numero de vertices
    if(v1 >= 0 && v1 < n_vertex && v2 >= 0 && v2 < n_vertex)
    {
      matrix_adj[v1][v2] = true;
    }
    printf("Deseja ligar mais vertices?(0 - Nao/ 1 - Sim)\n");
    scanf("%d", &continuar);
  } while(continuar == 1);
  /*
  printf("Arestas do grafo:\n");
  for (i = 0; i < n_vertex; ++i)
  {
    for(j = 0; j < n_vertex; ++j)
    {
      if(matrix_adj[i][j] == true)
      {
        printf("Aresta (%d, %d)\n", i, j);
        printf("")
      }
    }
  }
  */

  for(i = 0; i < n_vertex; ++i)
  {
    for(j = 0; j < n_vertex; ++j)printf("%d ", matrix_adj[i][j]);
    printf("\n");
  }
  return 0;
}
