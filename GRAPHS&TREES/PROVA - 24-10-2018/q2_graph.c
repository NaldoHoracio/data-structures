#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_VERTEX 100

// Lista encadeada
//Estrutura node
struct Node
{
  int item;
  Node *next_node;
};
//Definindo tipo node
typedef struct Node node_ed;
//Criando a lista encadeada - modo 1
node_ed* create_linked_list_ed()
{
  return NULL;
}
//Lista vazia
int is_empty_ed(node_ed *head)
{
  return (head == NULL);
}
//Adicionando elemento no começo da fila
node_ed* add_on_head_ed(node_ed *head, int item)
{
  node_ed *new_node = (node_ed*)malloc(sizeof(node_ed));
  new_node->item = item;
  new_node->next_node = head;
  return new_node;
}

//Imprimindo a lista - forma nao recursiva
void print_linked_list_no_recursive_ed(node_ed *head)
{
  while(head != NULL)
  {
    printf("%d\n", head->item);
    head = head->next_node;
  }
}
// Tamanho de uma lista
int size_linked_list(node_ed *head)
{
  int size_list = 0;
  while(head != NULL)
  {
    size_list++;
    head = head->next_node;
  }
  return size_list;
}

bool validing_string(char c)
{
  return (c == '0' || c == '1' || c == '2' || c == '3' || c == '4'|| c == '5' || c == '6' || c == '7' || c == '8' || c == '9') ? true : false;
}
int main()
{
  char n_vertex_aux[20], v1_aux[20], v2_aux[20];
  int i, j, n_vertex, v1, v2;
  int continuar;
  printf("Digite o numero de vertices:\n");
  scanf("%s", n_vertex_aux);
  getchar();//Lendo o \n

  //Verificando se a string é válida
  for(i = 0; i < strlen(n_vertex_aux); ++i)
  {
    if(validing_string(n_vertex_aux[i]))
    {
      continue;
    }else{
      printf("Número de vértices inválidos!\n");
      break;
    }
  }

  //Convertendo string para o inteiro
  n_vertex = atoi(n_vertex_aux);

  bool matrix_adj[n_vertex][n_vertex];

  // Inicializando a matriz de adjacência
  for(i = 0; i < n_vertex; ++i)
  {
    for(j = 0; j < n_vertex; ++j) matrix_adj[i][j] = false;
  }

  do {
    printf("Digite as arestas que deseja ligar:\n");
    printf("Aresta v1:\n");
    scanf("%s", v1_aux);
    getchar();//Lendo o \n
    //Verificando se a string é válida
    for(i = 0; i < strlen(v1_aux); ++i)
    {
      if(validing_string(v1_aux[i]))
      {
        continue;
      }else{
        printf("Vértice inválido!\n");
        break;
      }
    }
    v1 = atoi(v1_aux);
    printf("Aresta v2:\n");
    scanf("%s", v2_aux);
    getchar();//Lendo o \n
    //Verificando se a string é válida
    for(i = 0; i < strlen(v2_aux); ++i)
    {
      if(validing_string(v2_aux[i]))
      {
        continue;
      }else{
        printf("Vértice inválido!\n");
        break;
      }
    }
    v2 = atoi(v2_aux);

    //Verifica se as arestas estao dentro do numero de vertices
    if(v1 >= 0 && v1 < n_vertex && v2 >= 0 && v2 < n_vertex)
    {
      matrix_adj[v1][v2] = true;
    }
    printf("Deseja ligar mais vertices?(0 - Nao/ 1 - Sim)\n");
    scanf("%d", &continuar);
  } while(continuar == 1);

  node_ed *ll_vertex_is_adj = create_linked_list_ed();

  // Verificando se o vértice á adjacente aos demais
  for(i = 0; i < n_vertex; ++i)
  {
    int cont_lines = 0, cont_rows = 0;
    for(j = 0; j < n_vertex; ++j)
    {
      // Se o vertice da linha i se liga ao vértice na coluna j, soma 1 ao contador (uma aresta sai da linha i para a coluna j)
      if(matrix_adj[i][j] == true) cont_lines++;
      // Se o vértice da linha j se liga ao vértice da coluna i, soma 1 ao contador (o vértice recebe uma aresta)
      if(matrix_adj[j][i] == true) cont_rows++;
    }
    // Verificando se o vertice é adjacente aos demais
    if(cont_lines == (n_vertex - 1) && cont_rows == (n_vertex - 1))
    {
      ll_vertex_is_adj = add_on_head_ed(ll_vertex_is_adj, i);
    }

  }
  printf("\n");
  // Se o numero de elementos na lista é igual ao numero de vertices
  // Então o grafo é completo
  if(size_linked_list(ll_vertex_is_adj) == n_vertex)
  return 0;
}
