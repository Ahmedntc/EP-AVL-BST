#include "trees.h"


//-----------------------------------------------------MIN MAX---------------------------------------------------------------------------//
int max(int a, int b) {
  return (a > b) ? a : b;
}

int min(int a, int b) {
  return (a < b) ? a : b;
}
//-------------------------------------------------FUNÇOES DE CALCULO DE MEDIA DE ALTURA E TEMPO-------------------------------------------------------------------//
void AVLcalculoDeMedias(double qtdArv, double qtdNos, double altura, double deltaT)
{
    printf("\n------------------------------------------------------------\n");
    printf("\nIniciando teste com %lf Arvores AVL e %lf Elementos em cada", qtdArv, qtdNos);
    double alturaMedia = altura / qtdArv;
    double tempoMedio = deltaT / qtdArv;
    printf("\nAltura Media AVL: %lf", alturaMedia);
    printf("\nTempo medio AVL: %lf\n", tempoMedio);
    

    BSTbenchmark(qtdArv,  qtdNos);
}

void BSTcalculoDeMedias(double qtdArv, double qtdNos, double altura, double deltaT)
{
    printf("\n------------------------------------------------------------\n");
    printf("\nIniciando teste com %lf Arvores BST e %lf Elementos em cada", qtdArv, qtdNos);
    double alturaMedia = altura / qtdArv;
    double tempoMedio = deltaT / qtdArv;
    printf("\nAltura Media BST: %lf", alturaMedia );
    printf("\nTempo medio BST: %lf\n", tempoMedio);
    
}

//----------------------------------------BENCHMARKERS---------------------------------------------------------------//
void treeMeasurer(){
    double qtdArvore , qtdNos;
    printf("\nNumero de Arvores para o teste: ");
    scanf("%lf", &qtdArvore);
    printf("\nNumero de elemntos para cada arvore: ");
    scanf("%lf", &qtdNos);

    AVLbenchmark(qtdArvore, qtdNos);
}

void BSTbenchmark(int qtdArv, int qtdNos)
{
    srand(time(NULL));
    clock_t bstIni, bstEnd;
    double deltaTotal = 0;
    double randKey = 0, altura = 0, alturaTotal = 0;
    
    for(int i = 0; i < qtdArv; i++)
    {
        bstNo *BSTbench;
        bstIni = clock();
        for(int k = 0; k < qtdNos; k++)
        {
            randKey = rand() % qtdNos + 1;
            while(BSTsearchElement(BSTbench, randKey) != false){
                randKey = rand() % qtdNos + 1;
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
    double randKey = 0 , altura = 0, alturaTotal = 0;
    
    
    printf("oiii ");
    for(int i = 0; i <= qtdArv; i++)
    {
        avlNo *AVLroot;
        avlIni = clock();
        printf("oiii ");
        for(int k = 0; k <= qtdNos; k++)
        {
            randKey = rand() % qtdNos + 1;
            while(AVLsearchElement(AVLroot, randKey) != false){        
                randKey = rand() % qtdNos + 1;
                printf("oiii %lf", randKey);
            }
            
            
            printf("oiii %lf", randKey);
            AVLroot = AVLinsertNode(AVLroot, randKey);
        }
        avlEnd = clock();
        deltaTotal += ((double) (avlEnd - avlIni)/CLOCKS_PER_SEC);
        
        
        altura = AVLgetAltArvore(AVLroot); 
        alturaTotal += altura;  
    }
    AVLcalculoDeMedias(qtdArv, qtdNos, alturaTotal, deltaTotal); 
 }
//-------------------------------------------------FUNÇOES PARA  BST--------------------------------------------------------------------//

bstNo *BSTnewNode(int key){
    bstNo *node = malloc(sizeof(struct bnode));
    node->key = key;
    node->esq = NULL;
    node->dir = NULL;

    return node;
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

double BSTgetAltArvore(bstNo*root){
    if (root == NULL)
        return 0;
    else 
    {
        double esqAlt = BSTgetAltArvore(root->esq);
        double dirAlt = BSTgetAltArvore(root->dir);
        return max(esqAlt, dirAlt) + 1;    
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
}
//-------------------------------------------------FUNÇOES PARA AVL--------------------------------------------------------------//


avlNo *AVLnewNode(int key) {
    printf("ola");
    avlNo *node = malloc(sizeof(struct anode));
    node->key = key;
    node->esq = NULL;
    node->dir = NULL;
    node->alt = 1;
    
    return node;
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
    return 1 + max(AVLgetAlt(node->esq), AVLgetAlt(node->dir));
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
    printf("oi1 %d", root->key); 
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

double AVLgetAltArvore(avlNo*root){
    if (root == NULL)
        return 0;
    else 
    {
        return max(AVLgetAltArvore(root->dir), AVLgetAltArvore(root->esq)) + 1;    
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