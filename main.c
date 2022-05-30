#include "trees.c"



int main()
{ 
    int opt;
    double qtdArvore , qtdNos; 
    do{
        printf("\nMENU");
        printf("\n-----------------------------");
        printf("\n1-Iniciar novo teste!");
        printf("\nSua escolha: ");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:     
                printf("\nNumero de Arvores para o teste: ");
                scanf("%lf", &qtdArvore);
                printf("\nNumero de elemntos para cada arvore: ");
                scanf("%lf", &qtdNos);
                AVLbenchmark(qtdArvore, qtdNos);
                break;
            default:
                printf("\nOpcao inexistente tente novamente!");
                break;
        }


    }while(opt != 0);
    return 0;
}
