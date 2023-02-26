#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//Inserir em uma árvore binária de forma ordenada
//Elementos à esquerda: menores
//Elementos à direita: maiores
/*
se tree == NULL
  aloca nó
  raix <- x
  left <- NULL
  right <- NULL
se não se (a->raiz > x)
  insere(a->left,x)
else insere(a->right,x)
*/
//Retornar as folhas da árvore
/*
if(a != NULL && a->right == NULL && a->left == NULL)
  escreve(a->info)
else if( a != NULL && a->right != NULL && a->left == NULL)
  folha(a->right)
else if(a != NULL && a->right == NULL && a->left != NULL)
  folha(a->left)
else
{
  folha(a->right)
  folha(a->left)
}
*/
