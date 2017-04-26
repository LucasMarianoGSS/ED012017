#include <stdio.h>
#include <stdlib.h>

int push(int flag, int *ponteiro, int num){
    if(num>4){
        realloc(ponteiro, num*sizeof(int));
        ponteiro[num]=flag;
        return(1);
    }else{
        ponteiro[num]=flag;
        return(1);
    }
}

int main(){
    int *ponteiro = (int *)malloc(5*sizeof(int)), temp, flag=1, num=0, num2=0;

    printf("\nVetor inicialmente com tamanho 5");
    while(flag!=0){
        printf("\n\nDigite um numero a ser adicionado na pilha\n");
        printf("ou 0 para terminar:");
        scanf("%d", &flag);
        if(flag==0){
        }else{
            num2=push(flag, ponteiro, num);
            if(num2==1){
                printf("Valor %d alocado na %do posicao.\n", ponteiro[num], num);
                num++;
            }else{
                printf("\nErro na alocacao.");
            }
        }
    }
    free(ponteiro);
    printf("\n\nPrograma encerrado.\n\n");
    return(0);
}
