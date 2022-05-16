#include "trees.h"

//funcao geral

void BSTcalculoDeMedias(int qtdArv, double altura, double deltaMedio)
{
    double alturaMedia = altura / qtdArv;
    double tempoMedio = deltaMedio / qtdArv;
}

void AVLcalculoDeMedias(int qtdArv, double altura, double deltaMedio)
{
    double alturaMedia = altura / qtdArv;
    double tempoMedio = deltaMedio / qtdArv;
}




//-------------------------------------------------FUNÇOES PARA  BST--------------------------------------------------------------------//
void BSTbenchmark(int qtdArv, int qtdNos)
{
    srand(time(NULL));
    clock_t bstIni, bstEnd;
    double  deltaT, deltaTotal;
    double altura, alturaTotal;
    bstNo *BSTbench;
    
    for(int i = 0; i <= qtdArv; i++)
    {
        bstIni = clock();
        for(int i = 0; i <= qtdNos; i++)
        {
            int randKey = rand();
            BSTbench = BSTnewNode(randKey);
            BSTinsertNode(BSTbench, randKey);
        }
        bstEnd = clock();

        deltaT = ((double) (bstEnd - bstIni)/CLOCKS_PER_SEC);
        deltaTotal += deltaT;

        altura = BSTgetAltArvore(BSTbench); 
        alturaTotal += altura;

        BSTcalculoDeMedias(qtdArv, alturaTotal, deltaTotal);
    } 
}

bstNo *BSTnewNode(int key){
    bstNo *node = (bstNo * )malloc(sizeof(bstNo));
    node->key = key;
    node->esq = NULL;
    node->dir = NULL;

    return node;
}

bstNo *BSTinsertNode(bstNo *node, int key){
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->esq = insertNode(node->esq, key);
    else if (key > node->key)
        node->dir = insertNode(node->dir, key);
    else
        return node;
}

bstNo *BSTdeleteNode(bstNo *alvo, int key){

    if(alvo==NULL)
        return NULL;
    if (key > alvo->key)
        alvo->dir = BSTdeleteNode(alvo->dir, key);
    else if(key < alvo->key)
        alvo->esq = BSTdeleteNode(alvo->esq, key);
    else
    {
        if(alvo->dir==NULL && alvo->esq==NULL)
        {
            free(alvo);
            return NULL;
        }
        else if(alvo->esq==NULL || alvo->dir==NULL)
        {
            bstNo *aux;
            if(alvo->esq==NULL)
                aux = alvo->dir;
            else
                aux = alvo->esq;
            
            return alvo;
            free(alvo);
        }
        else
        {
            bstNo *aux = BSTminValueNode(alvo->dir);
            alvo->key = aux->key;
            alvo->dir = BSTdeleteNode(alvo->dir, aux->key);
        }
    }
    return alvo;
}

void BSTpreOrder(bstNo *root) {
    if (root != NULL) 
    {
        printf("%d ", root->key);
        preOrder(root->esq);
        preOrder(root->dir);
    }
}

void BSTinOrder(bstNo *root) {
    if (root != NULL) 
    {
        inOrder(root->esq);
        printf("%d ", root->key);
        inOrder(root->dir);
  }
}

void BSTposOrder(bstNo *root) {

    if (root != NULL) 
    {
        posOrder(root->esq);
        posOrder(root->dir);
        printf("%d ", root->key);
    }
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

double BSTgetAltArvore(bstNo*node){
    if(node != NULL)
    {
        int h = 1;
        while(node->dir !=NULL)
        {
            node = node->dir;
            h++;
        }    
        return h;
    }
    return 0;    
}

//-------------------------------------------------FUNÇOES PARA AVL--------------------------------------------------------------//
void AVLbenchmark(int qtdArv, int qtdNos)
{
    srand(time(NULL));
    clock_t avlIni, avlEnd;
    double  deltaT, deltaTotal;
    double altura, alturaTotal;
    avlNo *AVLbench;
    
    for(int i = 0; i <= qtdArv; i++)
    {
        avlIni = clock();
        for(int i = 0; i <= qtdNos; i++)
        {
            int randKey = rand();
            AVLbench = AVLnewNode(randKey);
            AVLinsertNode(AVLbench, randKey);
        }
        avlEnd = clock();

        deltaT = ((double) (avlEnd - avlIni)/CLOCKS_PER_SEC);
        deltaTotal += deltaT;

        altura = AVLgetAltArvore(AVLbench); 
        alturaTotal += altura;

        AVLcalculoDeMedias(qtdArv, alturaTotal, deltaTotal);
    } 
}


avlNo *AVLnewNode(int key) {
    avlNo *node = (avlNo * )malloc(sizeof(avlNo));
    node->key = key;
    node->esq = NULL;
    node->dir = NULL;
    node->alt;
    
    return node;
}

avlNo *AVLdirRotate(avlNo *y) {
    avlNo *x = y->esq;
    avlNo *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->alt = AVLnewAlt(y);
    x->alt = AVLnewAlt(x);

    return x;
}

avlNo *AVLesqRotate(avlNo *x) {
    avlNo *y = x->dir;
    avlNo *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->alt = AVLnewAlt(x);
    y->alt = AVLnewAlt(y);

    return y;
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

void AVLrebalance(avlNo *root)
{
    int fb = AVLgetFb(root);
    if (fb > 1 && getfb(root->esq) >= 0)
        return dirRotate(root);

    if (fb > 1 && getfb(root->esq) < 0) 
    {
        root->esq = esqRotate(root->esq);
        return dirRotate(root);
    }

    if (fb < -1 && getfb(root->dir) <= 0)
        return esqRotate(root);

    if (fb < -1 && getfb(root->dir) > 0) 
    {
        root->dir = dirRotate(root->dir);
        return esqRotate(root);
    }

}

avlNo *AVLinsertNode(avlNo *node, int key) {
  
    if (node == NULL)
        return (AVLnewNode(key));
    if (key < node->key)
        node->esq = AVLinsertNode(node->esq, key);
    else if (key > node->key)
        node->dir = AVLinsertNode(node->dir, key);
    else
        return node;

    node->alt = AVLnewAlt(node);
    AVLrebalance(node);

    return node;
}

avlNo *AVLdeleteNode(avlNo *alvo, int key) {

    if (alvo == NULL)
        return alvo;

    if (key < alvo->key)
        alvo->esq = AVLdeleteNode(alvo->esq, key);

    else if (key > alvo->key)
        alvo->dir = AVLdeleteNode(alvo->dir, key);

    else {
        if ((alvo->esq == NULL) || (alvo->dir == NULL)) 
        {
            avlNo *aux = alvo->esq ? alvo->esq : alvo->dir;

            if (aux == NULL) 
            {
                aux = alvo;
                alvo = NULL;
            }else
                *alvo = *aux;
                free(aux);
        } else 
        {
            avlNo *aux = AVLminValueNode(alvo->dir);
            alvo->key = aux->key;
            alvo->dir = AVLdeleteNode(alvo->dir, aux->key);
        }
    }
    if (alvo == NULL)
        return alvo;
    
    alvo->alt = AVLnewAlt(alvo);
    AVLrebalance(alvo);

    return alvo;
}

void AVLpreOrder(avlNo *root) {
    if (root != NULL) 
    {
        printf("%d ", root->key);
        preOrder(root->esq);
        preOrder(root->dir);
    }
}

void AVLinOrder(avlNo *root) {
    if (root != NULL) 
    {
        intPreOrder(root->esq);
        printf("%d ", root->key);
        intPreOrder(root->dir);
  }
}

void AVLposOrder(avlNo *root) {
    if (root != NULL) 
    {
        posOrder(root->esq);
        posOrder(root->dir);
        printf("%d ", root->key);
    }
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

int min(int a, int b) {
  return (a < b) ? a : b;
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

int AVLgetAltArvore(bstNo*node){
    int h = 1;
    while(node->dir !=NULL)
        node = node->dir;
        h++;
    return h;    
}