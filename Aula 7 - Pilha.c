#include <stdio.h>

typedef struct{
    int top;
    int pilha[10];
} stru;
stru p;

int main(){

    printf("\n\n EMPILHANDO \n\n");
    p.top = 0;
    int i[10]={10, 20 ,30 ,40, 50, 60, 70, 80, 90, 100, 110}, j;
    for(j=0;j<11;j++){
        printf("\nEmpilhando valor %i na posicao %i", i[j], j);
        push(i[j]);
        printf("\n");
    }
    printf("\n\n DESEMPILHANDO \n\n");
    for(j=10;j>=0;j--){
        pop();
    }
}

void push(int i){
    if(p.top==10){
        printf("\n Pilha no limite.");
    } else {
        p.pilha[p.top]=i;
        p.top+=1;
        printf("\n Valor %i inserido na posicao %i", i, p.top);
    }
}

void pop(){
    if(p.top==0){
        printf("\n Pilha sem valores.\n\n");
        return(0);
    } else {
        p.top-=1;
        printf("\nValor %i da posicao %i desempilhado", p.pilha[p.top], p.top);
        p.pilha[p.top]=0;
    }
}
