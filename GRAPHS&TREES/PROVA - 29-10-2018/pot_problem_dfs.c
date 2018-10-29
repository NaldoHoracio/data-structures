#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 100

//n is no of vertices and graph is sorted in array G[10][10]
int n_vertex;
bool graph_matrix_adj[MAX_SIZE][MAX_SIZE],visited[MAX_SIZE];

void pot_problem_dfs(int i)
{
    bool visited[i] = true;
    int j;
    printf("%d",i);

    for(j = 0;j < n_vertex; ++j)
       if(!visited[j] && graph_matrix_adj[i][j] ==  true)
            pot_problem_dfs(j);
}

void main()
{
    int i, j, v1, v2;
    int continuar = 1;
    printf("Digite o numero de vertices:");
    scanf("%d", &n_vertex);

    // Inicializando matriz de adjacência
    for(i = 0; i < n_vertex; ++i)
    {
      for(j = 0; j < n_vertex; ++j)
        graph_matrix_adj[i][j] = false;
    }

    printf("\nEntre com os vertices da matriz de adjacencia:");
    do{
      printf("Vertice v1:\n");
      scanf("%d", &v1);
      printf("Vertice v2:\n");
      scanf("%d", &v2);
      graph_matrix_adj[v1][v2] = true;
      printf("Continuar? (0 - Nao/1 - Sim):\n");
      scanf("%d", &continuar);
    }while(continuar == 1);

    //visited is initialized to zero
   for(i = 0; i < n_vertex; ++i)
        visited[i] = false;

    pot_problem_dfs(0);
}
