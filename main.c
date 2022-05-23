#include <stdio.h>
#include <stdlib.h>
#include "trees.c"





int main()
{
    int opt; 
    double qtdArvore, qtdNos;

    do{
        printf("MENU");
        printf("\n1-Iniciar novo teste!");
        printf("\n2-Sair!");
        printf("\nSua escolha: ");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
                treeMeasurer();
                break;
            default:
                break;
        }


    }while(opt != 2);
    return 0;
}
