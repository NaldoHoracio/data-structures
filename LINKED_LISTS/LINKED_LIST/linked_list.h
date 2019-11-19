#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 5

struct node{
    int item;
    struct node *next_node;
};

/** 
 * Essa função tem o objetivo de criar a lista encadeada vazia 
 * @param
 *
 * @return 
 */
struct node* create_linked_list();

/** 
 * Essa função tem o objetivo de adicionar um nó
 * na cabeça da lista encadeada 
 * @param head
 * @param item
 *
 * @return 
 */
struct node* add(struct node *head, int item);

/** 
 * Essa função tem o objetivo de buscar um item
 * lista encadeada 
 * @param head
 * @param item
 *
 * @return 
 */
struct node* search(struct node *head, int item);

/** 
 * Essa função tem o objetivo de remover um nó da lista encadeada 
 * @param head
 * @param item
 *
 * @return 
 */
struct node* remove(struct node *head, int item);

/** 
 * Essa função verifica se a lista está vazia
 * @param head
 *
 * @return 
 */
int is_empty(struct node *head);


/** 
 * Essa função tem o objetivo de imprimir a lista encadeada
 * a partir da cabeça da lista
 * @param head
 * @param item
 *
 * @return 
 */
void print_linked_list(struct node *head);


