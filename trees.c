#include "trees.h"


//-----------------------------------------------------MIN MAX---------------------------------------------------------------------------//
int Max(int a, int b) {
  return (a > b) ? a : b;
}

//-------------------------------------------------FUNÇOES DE CALCULO DE MEDIA DE ALTURA E TEMPO-------------------------------------------------------------------//
void AVLcalculoDeMedias(int qtdArv, int qtdNos, int altura, double deltaT)
{
    printf("\n------------------------------------------------------------\n");
    printf("\nIniciando teste com %lf Arvores AVL e %lf Elementos em cada", qtdArv, qtdNos);
    int alturaMedia = altura / qtdArv;
    double tempoMedio = deltaT / qtdArv;
    printf("\nAltura Media AVL: %d", alturaMedia);
    printf("\nTempo medio AVL: %lf\n", tempoMedio);
    

    BSTbenchmark(qtdArv,  qtdNos);
}

void BSTcalculoDeMedias(int qtdArv, int qtdNos, int altura, double deltaT)
{
    printf("\n------------------------------------------------------------\n");
    printf("\nIniciando teste com %lf Arvores BST e %lf Elementos em cada", qtdArv, qtdNos);
    int alturaMedia = altura / qtdArv;
    double tempoMedio = deltaT / qtdArv;
    printf("\nAltura Media BST: %d", alturaMedia );
    printf("\nTempo medio BST: %lf\n", tempoMedio);
    
}

//----------------------------------------BENCHMARKERS---------------------------------------------------------------//

void BSTbenchmark(int qtdArv, int qtdNos)
{
    srand(time(NULL));
    clock_t bstIni, bstEnd;
    double deltaTotal = 0;
    int randKey, altura, alturaTotal = 0;
    
    for(int i = 0; i < qtdArv; i++)
    {
        bstNo *BSTbench = NULL;
        bstIni = clock();
        for(int k = 0; k < qtdNos; k++)
        {
            randKey = rand() % 900 + 1;
            while(BSTsearchElement(BSTbench, randKey)){
                randKey = rand() % 900 + 1;
            }
            BSTbench = BSTinsertNode(BSTbench, randKey);
        }
        bstEnd = clock();
        deltaTotal += ((double) (bstEnd - bstIni)/CLOCKS_PER_SEC);

        altura = BSTgetAltArvore(BSTbench); 
        alturaTotal += altura;   
    }
    BSTcalculoDeMedias(qtdArv, qtdNos, alturaTotal, deltaTotal);
}

void AVLbenchmark(int qtdArv, int qtdNos)
{
    srand(time(NULL));
    clock_t avlIni, avlEnd;
    double  deltaTotal = 0;
    int randKey = 0 , altura = 0, alturaTotal = 0;
    
    for(int i = 0; i <= qtdArv; i++)
    {
        avlNo *AVLroot = NULL;
        avlIni = clock();
        for(int k = 0; k <= qtdNos; k++)
        {
            randKey = rand() % 900 + 1;
            while(AVLsearchElement(AVLroot, randKey)){        
                randKey = rand() % 900 + 1;
            }
            avlNo *AVLroot = AVLinsertNode(AVLroot, randKey);
        }
        avlEnd = clock();
        deltaTotal += ((double) (avlEnd - avlIni)/CLOCKS_PER_SEC);
        
        
        altura = AVLgetAltArvore(AVLroot); 
        alturaTotal += altura;  
        free(AVLroot);
    }
    AVLcalculoDeMedias(qtdArv, qtdNos, alturaTotal, deltaTotal);  
 }
//-------------------------------------------------FUNÇOES PARA  BST--------------------------------------------------------------------//

bstNo *BSTnewNode(int key){
    bstNo *node = (bstNo *)malloc(sizeof(bstNo));
    if (node) {
        node->key = key;
        node->esq = NULL;
        node->dir = NULL;
        return node;
    }
    return NULL;
    
}

bstNo *BSTinsertNode(bstNo *node, int key){
    if (node == NULL)
        return (BSTnewNode(key));
    if (key < node->key)
        node->esq = BSTinsertNode(node->esq, key);
    else if (key > node->key)
        node->dir = BSTinsertNode(node->dir, key);
    
    return node;
}


bstNo *BSTminValueNode(bstNo*node) {
    bstNo *curr = node;
    while (curr->esq != NULL)
        curr = curr->esq;
    return curr;
}

bstNo *BSTmaxValueNode(bstNo *node) {
    bstNo *curr = node;
    while (curr->dir != NULL)
        curr = curr->dir;
    return curr;
}

int BSTgetAltArvore(bstNo*root){
    if (root == NULL)
        return 0;
    else 
    {
        return Max(BSTgetAltArvore(root->esq), BSTgetAltArvore(root->dir)) + 1;    
    } 
    return 0;
}

bool BSTsearchElement(bstNo *root, int key){
    if(root == NULL)
        return false;
    if(root->key == key){
        return true;
    }
    else if(root->key < key)
        BSTsearchElement(root->dir, key);
    else
        BSTsearchElement(root->esq, key);
    return NULL;   
}
//-------------------------------------------------FUNÇOES PARA AVL--------------------------------------------------------------//


avlNo *AVLnewNode(int key) {
    avlNo *node = (avlNo *)malloc(sizeof(avlNo));
    if (node) {
        node->key = key;
        node->esq = NULL;
        node->dir = NULL;
        node->alt = 1;
        return node;
    }
    return NULL;
}

avlNo *AVLdirRotate(avlNo *root) {
  if (root == NULL) return root;
  avlNo *x = root->esq;
  avlNo *T2 = x->dir;

  x->dir = root;
  root->esq = T2;

  root->alt = AVLnewAlt(root);
  x->alt = AVLnewAlt(x);

  return x;
}

avlNo *AVLesqRotate(avlNo *root) {
  if (root == NULL) return root;
  avlNo *x = root->dir;
  avlNo *T2 = x->esq;

  x->esq = root;
  root->dir = T2;

  root->alt = AVLnewAlt(root);
  x->alt = AVLnewAlt(x);

  return x;
}

int AVLgetFb(avlNo *node) {
    if (node == NULL)
        return 0;
    return AVLgetAlt(node->esq) - AVLgetAlt(node->dir);
}

int AVLnewAlt(avlNo *node){
    return 1 + Max(AVLgetAlt(node->esq), AVLgetAlt(node->dir));
}

int AVLgetAlt(avlNo *node){
    if (node == NULL)
        return 0;
    return node->alt;
}

avlNo *AVLrebalance(avlNo *root)
{
    int fb = AVLgetFb(root);
    if (fb == 2){
         if(AVLgetFb(root->esq) < 0){
            root->esq = AVLesqRotate(root);
        }
        root = AVLdirRotate(root);
    }
        if (fb == -2){
         if(AVLgetFb(root->dir) > 0){
            root->dir = AVLdirRotate(root);
        }
        root = AVLesqRotate(root);
    }
    return root;

}

avlNo *AVLinsertNode(avlNo *root, int key) {
    if (root == NULL){ 
        return AVLnewNode(key);
    }
    if (key > root->key){
        root->dir = AVLinsertNode(root->dir, key);
    }
    else if (key < root->key){
        root->esq = AVLinsertNode(root->esq, key);
    }
    else{
        return root;
    }


    root->alt = AVLnewAlt(root);
    int fb = AVLgetFb(root);

    if (fb == 2){
         if(AVLgetFb(root->esq) < 0){
            root->esq = AVLesqRotate(root);
        }
        root = AVLdirRotate(root);
    }
        if (fb == -2){
         if(AVLgetFb(root->dir) > 0){
            root->dir = AVLdirRotate(root);
        }
        root = AVLesqRotate(root);
    }
    return root;
}


avlNo *AVLminValueNode(avlNo *node) {
    avlNo *curr = node;
    while (curr->esq != NULL)
        curr = curr->esq;
    return curr;
}

avlNo *AVLmaxValueNode(avlNo *node) {
    avlNo *curr = node;
    while (curr->dir != NULL)
        curr = curr->dir;
    return curr;
}

int AVLgetAltArvore(avlNo*root){
    if (root == NULL)
        return 0;
    else 
    {
        return Max(AVLgetAltArvore(root->dir), AVLgetAltArvore(root->esq)) + 1;    
    }
    return 0;
}

bool AVLsearchElement(avlNo *root, int key){
    if(root == NULL)
        return false;
    if(root->key == key){
        return true;
    }
    else if(root->key < key)
        return AVLsearchElement(root->dir, key);
    else
        return AVLsearchElement(root->esq, key);   
}