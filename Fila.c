#include <stdio.h>

typedef struct{
    int top;
    int tail;
    int fila[10];
} stru;
stru p;

int main(){

    printf("\n\n EMPILHANDO \n\n");
    p.top = 1;
    p.tail = 0;
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
    if(p.top==p.tail){
        printf("\nFila cheia.");
    } else if(p.top>9){
        p.top=0;
        push(i);
    } else {
        p.fila[p.top]=i;
        printf("\nvalor %i empilhado na posicao %i", i, p.top);
        p.top+=1;
    }
}

void pop(){
    if(p.tail>9){
        p.tail=0;
    }
    else {
        p.tail+=1;
        printf("\nValor %i desempilhado da posicao %i", p.fila[p.tail], p.tail);
        p.fila[p.tail]=0;
    }
}
