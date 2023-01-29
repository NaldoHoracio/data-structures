#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct double_node
{
    int item;
    struct double_node *next_node;
    struct double_node *previous_node;
};

/** 
 * Essa função tem o objetivo de criar a lista duplamente encadeada
 * @param
 *
 * @return
 */
struct double_node* create_double_linked_list();

/** 
 * Essa função verifica se a lista está vazia
 * @param head
 *
 * @return 
 */
int is_empty(struct double_node *head);

/** 
 * Essa função tem o objetivo de adicionar um nó
 * na cabeça da lista encadeada 
 * @param head
 * @param item
 *
 * @return 
 */
struct double_node* add(struct double_node *head, int item);

/** 
 * Essa função tem o objetivo de buscar um item
 * lista encadeada 
 * @param head
 * @param item
 *
 * @return 
 */
struct double_node* search(struct double_node *head, int item);

/** 
 * Essa função tem o objetivo de remover um nó da lista encadeada 
 * @param head
 * @param item
 *
 * @return 
 */
struct double_node* remove(struct double_node *head, int item);


/** 
 * Essa função tem o objetivo de imprimir a lista encadeada
 * a partir da cabeça
 * @param head
 * @param item
 *
 * @return 
 */
void print_doubly_linked_list_foward(struct double_node *head);

/** 
 * Essa função tem o objetivo de imprimir a lista encadeada
 * a partir da cauda
 * @param head
 * @param item
 *
 * @return 
 */
void print_doubly_linked_list_backward(struct double_node *head);

