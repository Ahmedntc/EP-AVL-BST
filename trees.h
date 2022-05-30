#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

//structs para avl e bst

typedef struct anode{
  int key;
  struct anode *esq;
  struct anode *dir;
  int alt;
}avlNo;


typedef struct bnode{
  int key;
  struct bnode *esq;
  struct bnode *dir;
}bstNo;


//As duas proximas funçoes retornam o minimo e o maximo entre dois valores respectivamente



int Max(int a, int b);


//calcula a media das alturas e dos tempos de execuçao para bst ou avl
void AVLcalculoDeMedias(int qtdArv, int qtdNos, int altura, double deltaMedio);

void BSTcalculoDeMedias(int qtdArv, int qtdNos, int altura, double deltaMedio);

//executa as inserçoes dos nos aleatorios
void BSTbenchmark(int qtdArv, int qtdNos);

void AVLbenchmark(int qtdArv, int qtdNos);


//cria um novo node  e seta seus ponteiros
bstNo *BSTnewNode(int key);

avlNo *AVLnewNode(int key);

//insere o no na direita ou esquerda de uma raiz ou node existente em uma arvore
bstNo *BSTinsertNode(bstNo *node, int key);

avlNo *AVLinsertNode(avlNo *node, int key);

//retornam o no de maior ou menor valor
avlNo *AVLmaxValueNode(avlNo *node);

avlNo *AVLminValueNode(avlNo *node);

bstNo *BSTminValueNode(bstNo*node);

bstNo *BSTmaxValueNode(bstNo *node);

//retorna a altura da arvore
int BSTgetAltArvore(bstNo *root);

int AVLgetAltArvore(avlNo *root);

//busca por um elemento com a chave dada 
bool BSTsearchElement(bstNo *root, int key);

bool AVLsearchElement(avlNo *root, int key);


//rotaçao a esquerda
avlNo *AVLdirRotate(avlNo *y);

//rotaçao a direita
avlNo *AVLesqRotate(avlNo *x);

//retorna o fator de balanceamento de um no
int AVLgetFb(avlNo *node);

//seta uma altura nova para um no
int AVLnewAlt(avlNo *node);

//retorna a altura atual de um no
int AVLgetAlt(avlNo *node);

//recalcula os fatores de balanceamento e executa as rotaçoes necessarias
avlNo *AVLrebalance(avlNo *root);











