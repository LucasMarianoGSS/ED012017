#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char Nome[15];
    char Email[15];
    int Telefone;
    struct no *prox;

}no;


int main(){
    no *head = (no *) malloc(sizeof(no));
    head->prox = NULL;
    strcpy(head->Nome, "a");
    int i=0;

    do{
        printf("***************************\n");
        printf("Digite a opcao desejada:\n\n");
        printf("1 - Mostrar contatos\n");
        printf("2 - Buscar contato\n");
        printf("3 - Inserir contato\n");
        printf("4 - Editar contato\n");
        printf("5 - Excluir contato\n\n");
        printf("0 - Encerrar programa\n\n >>");
        scanf("%d", &i);
        if((i>5)||(i<0)){
            printf("Opcao invalida. Tente novamente.\n\n");
        }

        if(i==0){
            return(0);
        }else if(i==1){
            system("cls");
            mostra(head);
            system("cls");
        }else if(i==2){
            system("cls");
            busca(head);
            system("cls");
        }else if(i==3){
            system("cls");
            insere(head);
            system("cls");
        }else if(i==4){
            system("cls");
            edita(head);
            system("cls");
        }else if(i==5){
            system("cls");
            remover(head);
            system("cls");
        }

    }while(i != 0);
}

void busca(no *head){
    no *lista = head;
    int i=0;
    char string[15];

    if(head->prox==NULL){
        printf("Nao pode buscar em uma agenda vazia");
        printf("\n\n   [Enter]");
        getchar();
        getchar();
        return(0);

    }
    printf("Digite o nome a ser buscado: ");
    do{
        scanf("%s", &string);
            if((strlen(string)>15)){
                printf("\nNome inválido. Max 15 chars.");
            }
        strlwr(string);
    }while(strlen(string)>15);

    do{
        lista = lista->prox;
        i++;
    }while((strcmp(lista->Nome, string)!=0) && (lista->prox != NULL));

    if(strcmp(lista->Nome, string)==0){
        printf("\n\nContato encontrado:\n");
        printf("   |  Nome  %s \n", lista->Nome);
        printf(" %d |  Email %s \n", i, lista->Email);
        printf("   |  Telef %d", lista->Telefone);
        printf("\n\n   [Enter]");
        getchar();
        getchar();
    } else {
        printf("\n\nContato nao encontrado.\n\n   [Enter]");
        getchar();
        getchar();
    }
}

void mostra(no *head){
    no *lista = head->prox;
    int i = 1;

    if(head->prox == NULL){
        printf("\n\nAgenda vazia.");
        printf("\n\n\n   [Enter]\n");
        getchar();
        getchar();
        return(0);
    }

    printf("\n");
    do{
        printf("   |  Nome  %s \n", lista->Nome);
        printf(" %d |  Email %s \n", i, lista->Email);
        printf("   |  Telef %d\n\n", lista->Telefone);
        lista = lista->prox;
        i++;
    }while(lista!=NULL);
    printf("\n\n\n   [Enter]");
    getchar();
    getchar();
}

void insere(no *head){

    no *atual = (no *) malloc(sizeof(no));
    no *tmp = head;
    no *tmp2 = head;

    do{
        printf("\nNome: ");
        scanf("%s", &atual->Nome);
            if((strlen(atual->Nome)>15)){
                printf("\nNome inválido. Max 15 chars.");
            }
        strlwr(atual->Nome);
    }while(strlen(atual->Nome)>15);

    do{
        printf("\nEmail: ");
        scanf("%s", &atual->Email);
            if((strlen(atual->Nome)>15)){
                printf("\nEmail inválido. Max 15 chars.");
            }
    }while(strlen(atual->Nome)>15);

    do{
        printf("\nTelefone: ");
        getchar();
        scanf("%d", &atual->Telefone);
            if(atual->Telefone > 9999999999){
                printf("\nTelefone inválido. Max 10 chars.");
            }
    }while(atual->Telefone > 9999999999);

    while((tmp!=NULL)&&(strcmp(atual->Nome,tmp->Nome)>0)){
        tmp2 = tmp;
        tmp = tmp->prox;
    }
    atual->prox = tmp;
    tmp2->prox = atual;

    printf("\nContato adicionado!\n\n");
    printf("\n\n   [Enter]");
    getchar();
    getchar();
    return(0);
}

void edita(no *head){
    no *lista = head;
    int i=0, num=0;

    printf("Digite o numero do contato para editar:");
    scanf("%d", &num);

    do{
        lista = lista->prox;
        i++;
    }while((num!=i)&&(lista != NULL));

    if(lista == NULL){
        printf("\n\nContato Inexistente.");
        getchar();
        getchar();
        return(0);
    }
    printf("\n\nContato a ser editado: \n");
    printf("   |  Nome  %s \n", lista->Nome);
    printf(" %d |  Email %s \n", i, lista->Email);
    printf("   |  Telef %d\n\n", lista->Telefone);

    do{
        printf("Digite o novo nome:");
        scanf("%s", &lista->Nome);
            if((strlen(lista->Nome)>15)){
                printf("\nNome inválido. Max 15 chars.");
            }
        strlwr(lista->Nome);
    }while(strlen(lista->Nome)>15);

    do{
        printf("Digite o novo email:");
        scanf("%s", &lista->Email);
            if((strlen(lista->Nome)>15)){
                printf("\nEmail inválido. Max 15 chars.");
            }
    }while(strlen(lista->Nome)>15);

    do{
        printf("Telefone: ");
        getchar();
        scanf("%d", &lista->Telefone);
            if(lista->Telefone > 9999999999){
                printf("\nTelefone inválido. Max 10 chars.");
            }
    }while(lista->Telefone > 9999999999);

    printf("\n\nContato editado: \n");
    printf("   |  Nome  %s \n", lista->Nome);
    printf(" %d |  Email %s \n", i, lista->Email);
    printf("   |  Telef %d\n\n", lista->Telefone);
    printf("\n\n\n   [Enter]");
    getchar();
    getchar();
    return(0);
}

void remover(no *head){
    no *killer = head;
    no *antes = killer;
    int num=0, i=0;
    char letra;

    printf("Digite o numero do contato a remover: ");
    scanf("%d", &num);

    do{
        antes=killer;
        killer = killer->prox;
        i++;
    }while((i!=num)&&(killer!=NULL));
    if(killer==NULL){
        printf("\n\nContato nao encontrado.");
        getchar();
        getchar();
        return(0);
    }else{
        printf("\n\nContato a ser removido:\n");
        printf("   |  Nome  %s \n", killer->Nome);
        printf(" %d |  Email %s \n", i, killer->Email);
        printf("   |  Telef %d\n\n", killer->Telefone);
        printf("\nTem certeza? [s/n]");
        getchar();
        scanf("%c", &letra);
        if((letra=='s')||(letra=='S')){
            antes->prox = killer->prox;
            free(killer);
            printf("\n\nContato excluido.");
            getchar();
            getchar();
            return(0);
        }else if((letra=='n')||(letra=='N')){
            return(0);
        }else{
            printf("Letra invalida.");
            getchar();
            getchar();
            return(0);
        }
    }
}
