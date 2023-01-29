#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 100

//Struct grafo usando lista de adjacência

//Lista de adjacência
struct Adj_List
{
  int item;
  Adj_List *next_node;
};
//Definindo lista encadeada
typedef struct Adj_List adj_list_ed;

//Criando struct tipo grafo
struct Graph
{
  adj_list_ed *vertices[MAX_SIZE];
  int visited[MAX_SIZE];
};

//Definindo tipo grafo
typedef struct Graph graph_ed;

//Criando um grafo
graph_ed* create_graph()
{
  graph_ed *graph = (graph_ed*) malloc(sizeof(graph_ed));
  int i;
  for (i = 1; i <= MAX_SIZE - 1; i++)
  {
    graph->vertices[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

//Criando a lista de adjacência com um item
adj_list_ed* create_adj_list(int item)
{
  adj_list_ed *new_adj_list = (adj_list_ed*) malloc(sizeof(adj_list_ed));
  new_adj_list->item = item;
  new_adj_list->next_node = NULL;
  return new_adj_list;
}

//Adicionando uma aresta ao grafo
void add_edge(graph_ed *graph, int vertex1, int vertex2)
{
  adj_list_ed *vertex = create_adj_list(vertex2);
  vertex->next_node = graph->vertices[vertex1];
  graph->vertices[vertex1] = vertex;
  //Undirected graph. Edge to the other direction as well.
  vertex = create_adj_list(vertex1);
  vertex->next_node = graph->vertices[vertex2];
  graph->vertices[vertex2] = vertex;
}

//Algoritmo de busca em profundidade
void dfs(graph_ed *graph, int source);

//Algoritmo de busca em largura
void bfs(graph_ed *graph, int source);

//Imprimindo um grafo
void print_graph(graph_ed *graph);

int main()
{
  return 0;
}
