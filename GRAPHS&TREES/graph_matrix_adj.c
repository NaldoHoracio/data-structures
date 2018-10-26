#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_VERTEX 100

int edge[MAX_VERTEX][MAX_VERTEX];

//Adicionando uma aresta
void add_edge(int i, int j)
{

  edge[i][j] = 1; // ou true
}
//Removendo uma aresta
void remove_edge(int i, int j)
{
  edge[i][j] = 0; // ou false
}
//Verificando se a aresta existe
bool has_edge(int i, int j)
{
  return edge[i][j];
}

int main()
{
  int n_vextex, i, j, v1, v2;
  int continuar;
  printf("Digite o numero de vertices:\n");
  scanf("%d", &n_vextex);
  int matrix_adj[n_vextex][n_vextex] = {0};

  do {
    printf("Digite as arestas que deseja ligar:\n");
    scanf("%d%d", &v1, &v2);

    //Verifica se as arestas estao dentro do numero de vertices
    if(v1 >= 0 && v1 < MAX_VERTEX && v2 >= 0 && v2 < MAX_VERTEX)
    {
      for (i = 0; i < n_vextex; ++i)
      {
        for(j = 0; j < n_vextex; ++j)
        {
          if(v1 == i && v2 == j)
          {
            matrix_adj[i][j] = 1;
          }
        }
      }
    }
    printf("Deseja ligar mais vertices?(0 - Nao/ 1 - Sim)\n");
    scanf("%d", &continuar);
  } while(continuar == 1);

  printf("Arestas do grafo:\n");
  for (i = 0; i < n_vextex; ++i)
  {
    for(j = 0; j < n_vextex; ++j)
    {
      if(matrix_adj[i][j] == 1)
      {
        printf("Aresta (%d, %d)\n", i, j);
      }
    }
  }
  printf("It is ok!\n");
  return 0;
}
