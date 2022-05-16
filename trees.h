#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct node{
  int key;
  struct node *esq;
  struct node *dir;
  int alt;
}avlNo;

typedef struct node{
  int key;
  struct node *esq;
  struct node *dir;
}bstNo;




//

bstNo *BSTnewNode(int key);

bstNo *BSTinsertNode(bstNo *node, int key);

bstNo *BSTdeleteNode(bstNo *alvo, int key);




//


avlNo *AVLnewNode(int key);

avlNo *AVLdirRotate(avlNo *y);

avlNo *AVLesqRotate(avlNo *x);

int AVLgetFb(avlNo *node);

int AVLnewAlt(avlNo *node);

int AVLgetAlt(avlNo *node);

void AVLrebalance(avlNo *root);

avlNo *AVLinsertNode(avlNo *node, int key);

avlNo *AVLdeleteNode(avlNo *alvo, int key);

//As duas proximas funçoes retornam o minimo e o maximo entre dois valores respectivamente
int min(int a, int b);

int max(int a, int b);



