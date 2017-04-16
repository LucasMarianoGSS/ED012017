#include <stdio.h>

int main(){
    int i, j, vetor[10], matriz[3][4];

    printf("Digite os 10 numeros do vetor:");
    for(i=0;i<10;i++){
        scanf("%i", &vetor[i]);
    }
    printf("\nImpriminto o vetor:\n");
    for(i=0;i<10;i++){
        printf(" %i", vetor[i]);
    }
    printf("\n\nDigite os 12 numeros da matriz:");
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            scanf("%i", &matriz[i][j]);
        }
    }
    printf("\nImprimindo a matriz:");
    for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<4;j++){
            printf("%i", matriz[i][j]);
        }
    }
    printf("\n\n");
}
