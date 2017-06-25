#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int semente=1;
char jogando='s', lado1[10][20], lado2[10][20], tab1[10][20], tab2[10][20];

typedef struct {
    int pontos;
    int restantes;
    int tentativas;
    int bombas;
    int bombash;
    int espioes;
} estru;

void setar(){
    int i, j;
    for(i=0;i<10;i++){
        for(j=0;j<20;j++){
            lado1[i][j]='#';
        }
    }
    for(i=0;i<10;i++){
        for(j=0;j<20;j++){
            lado2[i][j]='#';
        }
    }
    for(i=0;i<10;i++){
        for(j=0;j<20;j++){
            tab1[i][j]='.';
        }
    }
    for(i=0;i<10;i++){
        for(j=0;j<20;j++){
            tab2[i][j]='.';
        }
    }
}

void limpar(){
    system("clear");
}

int sort(int num){
    semente++;
    srand(clock()*time(NULL)*semente);
    return(rand()%num);
}

void main(){
    system("title BATALHA NAVAL");
    char press;
    int ress;
    do{
        logo(1);
        press = getchar();
        getchar();
        while ((press!= 'a')&&(press!= 'A')&&(press!= 'b')&&(press!= 'B')&&(press!= 'c')&&(press!= 'C')){
            printf("\n\n                    Escolha invalida. Tente novamente: ");
            press = getchar();
            getchar();
        }
        setar();
        estru placar1 = {0, 50, 50, 1, 0, 0};
        estru placar2 = {0, 50, 50, 1, 0, 0};
        navios(lado1, 2, 8, 'P'); navios(lado2, 2, 8, 'P');
        navios(lado1, 2, 7, 'C'); navios(lado2, 2, 7, 'C');
        navios(lado1, 3, 5, 'F'); navios(lado2, 3, 5, 'F');
        navios(lado1, 5, 1, 'S'); navios(lado2, 5, 1, 'S');
        navios(lado1, 5, 1, 'M'); navios(lado2, 5, 1, 'M');
        navios(lado1, 10, 1, '>'); navios(lado2, 10, 1, '>');
        navios(lado1, 1, 1, '='); navios(lado2, 1, 1, '=');

        if ((press=='a')||(press=='A')){
            int vetorx[4], vetory[4];
            do {
                ress=rodada(tab1, lado2, 1, &placar1);
                if(jogando=='f'){
                    fim(ress, 1, &placar1, &placar2);
                } else {
                    ress=rodadaCOM(&placar2);
                    if(jogando=='f'){
                        fim(ress, 2, &placar2, &placar1);
                    }
                }
            } while (jogando!='f');
        } else if ((press=='b')||(press=='B')){
            do {
                ress=rodada(tab1, lado2, 1, &placar1);
                if(jogando=='f'){
                    fim(ress, 1, &placar1, &placar2);
                } else {
                    ress=rodada(tab2, lado1, 2, &placar2);
                    if(jogando=='f'){
                        fim(ress, 2, &placar2, &placar1);
                    }
                }
            } while (jogando!='f');
        }else if ((press=='c')||(press=='C')){
            limpar();
            logo(2);
            printf("     > Esse Batalha Naval foi modificado com novas ferramentas. O objetivo ainda e' eliminar\n");
            printf("todos os navios inimigos, mas a condicao de vitoria se da pela pontuacao acumulada, de modo que \n");
            printf("o jogador que mesmo tendo destruido todos os navios inimigos ainda pode perder.\n");
            printf("Alem da vitoria por pontos, o jogador tambem ganha automaticamente quando o oponente fica sem tentativas.\n\n     ");
            printf("> Recursos extras podem ser encontrados pelo mapa. Eles lhe darao novas ferramentas de destruicao:\n");
            printf("- Bomba Atomica = Destroi 1 unidade de distancia ao redor da coordenada escolhida. (Ativacao: 100 0)\n");
            printf("- Bomba H = Mais forte qua a bomba atomica, destroi 2 unidades de distancia. (Ativacao: 100 100)\n");
            printf("- Espioes = Limpa completamente uma coluna. (Ativacao: 50 50");
            printf("\n\n\n     > Lucas Mariano G. S. Souza / 160133670");
        }
        printf("\n     Deseja continuar jogando (S/N)? ");
        jogando=getchar();
        getchar();
        while ((jogando!= 's')&&(jogando!= 'S')&&(jogando!= 'n')&&(jogando!= 'S')){
            printf("\n\n     Escolha invalida. Tente novamente: ");
            jogando=getchar();
            getchar();
        }
        limpar();
    } while((jogando=='s')||(jogando=='S'));
    printf("\n\n\n     Programa encerrado.\n\n\n");
}

int fim(int ress, int num, estru *placar, estru *placarOpn){
    limpar();
    logo(2);
    if(ress==0){
        printf("\n\n    O jogador %i perdeu pois acabaram suas tentativas.", num);
    }else if(ress==1){
        if(placar->pontos>placarOpn->pontos){
            printf("\n\n   O jogador %i ganhou na pontuacao, de %i a' %i", num, placar->pontos, placarOpn->pontos);
        } else if((placarOpn->pontos)>(placar->pontos)){
            printf("\n\n   O jogador %i perdeu na pontuacao, de %i a' %i", num, placarOpn->pontos, placar->pontos);
        } else if(placar->pontos==placarOpn->pontos){
            printf("\n     O jogador %i empatou com %i pontos.", num, placar->pontos);
        }
    }
}

void navios(char lado[][20], int num, int tam, char letra){
    int linha, coluna, dimen, flag=0, flag2=0, i, j;

    do{
        flag2=0;
        linha = sort(9);
        coluna = sort(19);
        dimen = sort(19);
        if(lado[linha][coluna]!='#'){
            dimen=21;
        }
        if(dimen<9){
            if((linha+tam)>9){
                flag2=1;
            }
            for(i=0;i<tam;i++){
                if(lado[linha+i][coluna]!='#'){
                    flag2=1;
                }
            }
            if(flag2==0){
                for(j=0;j<tam;j++){
                    lado[linha+j][coluna]=letra;
                }
                flag++;
            }
        } else if (dimen<20) {
            if((coluna+tam)>19){
                flag2=1;
            }
            for(i=0;i<tam;i++){
                if(lado[linha][coluna+i]!='#'){
                    flag2=1;
                }
            }
            if(flag2==0){
                for(j=0;j<tam;j++){
                    lado[linha][coluna+j]=letra;

                }
                flag++;
            }
        }
    } while (flag<num);
}

int rodada(char tab[][20],char lado[][20], int num, estru *placar){
    int i, j, tirox, tiroy;

    limpar();
    logo(3,num, tab, &*placar);
    printf("\n                Este e' o mapa do seu oponente.\n Digite as coordenadas no formato 00 00 para onde quer atirar: ");
    do{
        scanf("%i %i", &tirox, &tiroy);
        if((tirox==100)&&(tiroy==0)&&(placar->bombas>0)){
            printf("\n Digite as novamente as coordenadas para a bomba nuclear: ");
            scanf("%i %i", &tirox, &tiroy);
            while((tirox<1)||(tirox>8)||(tiroy<1)||(tiroy>18)){
                printf("\n Fora da area de cobertura, evite as extremidades.\n Tente novamente: ");
                scanf("%i %i", &tirox, &tiroy);
            }
            limpar();
            placar->bombas-=1;
            for(i=-1;i<2;i++){
                for(j=-1;j<2;j++){
                    if(tab[tirox+i][tiroy+j]=='.'){
                        tiro(tirox+i, tiroy+j, tab, lado, &*placar, 0);
                    }
                    tab[tirox+i][tiroy+j]=lado[tirox+i][tiroy+j];
                }
            }
            printf("\n");
            placar->tentativas -= 1;
            logo(3,num, tab, &*placar);
            printf("[ENTER TO CONTINUE]");
            getchar();
            getchar();
            i=0;
        }else if((tirox==100)&&(tiroy==100)&&(placar->bombash>0)){
            printf("\n Digite as novamente as coordenadas para a bomba H: ");
            scanf("%i %i", &tirox, &tiroy);
            while((tirox<2)||(tirox>7)||(tiroy<2)||(tiroy>17)){
                printf("\n Fora da area de cobertura, evite as extremidades.\n Tente novamente: ");
                scanf("%i %i", &tirox, &tiroy);
            }
            limpar();
            placar->bombash-=1;
            for(i=-2;i<3;i++){
                for(j=-2;j<3;j++){
                    if(tab[tirox+i][tiroy+j]=='.'){
                        tiro(tirox+i, tiroy+j, tab, lado, &*placar, 0);
                        tab[tirox+i][tiroy+j]=lado[tirox+i][tiroy+j];
                    }
                }
            }
            placar->tentativas -= 1;
            logo(3,num, tab, &*placar);
            printf("[ENTER TO CONTINUE]");
            getchar();
            getchar();
            i=0;
        }else if((tirox==50)&&(tiroy==50)&&(placar->espioes>0)){
            printf("\n Digite a coluna a ser sabotada: ");
            scanf("%i", &tiroy);
            while((tiroy<0)||(tiroy>19)){
                printf("Fora da area de cobertura. tente novamente: ");
                scanf("%i", &tiroy);
            }
            limpar();
            placar->espioes-=1;
            for(i=0;i<10;i++){
                if(tab[i][tiroy]=='.'){
                    tiro(i, tiroy, tab, lado, &*placar, 0);
                    tab[i][tiroy]=lado[i][tiroy];
                }
            }
            printf("\n");
            placar->tentativas -= 1;
            logo(3,num, tab, &*placar);
            printf("[ENTER TO CONTINUE]");
            getchar();
            getchar();
            i=0;
        }else if((tab[tirox][tiroy]=='.')&&(tirox>=0)&&(tiroy>=0)&&(tirox<=9)&&(tiroy<=19)){
            placar->tentativas -= 1;
            tab[tirox][tiroy]=lado[tirox][tiroy];
            limpar();
            tiro(tirox, tiroy, tab, lado, &*placar, 0);
            logo(3,num, tab, &*placar);
            printf("[ENTER TO CONTINUE]");
            getchar();
            getchar();
            i=0;
        } else {
            printf("\n  As coordenadas ja foram escolhidas ou nao existem. Tente outras: ");
            i=99;
        }
    } while(i==99);

        if(placar->tentativas<=0){
            jogando='f';
            return(0);
        }else if(placar->restantes==0){
            jogando='f';
            return(1);
        } else {
            return(2);
    }
}

void tiro(int tirox, int tiroy, char tab[][20], char lado[][20], estru *placar, int flag){

    if(lado[tirox][tiroy]=='#'){
        printf("\n      Voce acertou a agua. Nenhum ponto creditado ou debitado.");
    }else if(lado[tirox][tiroy]=='P'){ placar->pontos += 25; placar->restantes -= 1;
        printf("\n    > Voce acertou um Porta-Avioes. +25 pontos creditados.");
    }else if(lado[tirox][tiroy]=='C'){ placar->pontos += 25; placar->restantes -= 1;
        printf("\n    > Voce acertou um Contratorpedeiro. +25 pontos creditados.");
    }else if(lado[tirox][tiroy]=='F'){ placar->pontos += 25; placar->restantes -= 1;
        printf("\n    > Voce acertou uma Fragata. +25 pontos creditados.");
    }else if(lado[tirox][tiroy]=='S'){ placar->pontos += 25; placar->restantes -= 1;
        printf("\n    > Voce acertou Submarino. +25 pontos creditados.");
    }else if(lado[tirox][tiroy]=='='){ placar->tentativas -= 5; placar->pontos -= 100;
        printf("\n\n\n     XXX VOCE ATINGIU UMA EMBARCACAO CIVIL!!! <<<  -100 pontos e -5 tentativas debitadas. XXX\n\n");
    }else if(lado[tirox][tiroy]=='M'){ placar->tentativas -= 2; placar->pontos -= 25;
        printf("\n    X Voce acertou uma mina! -25 pontos e -2 tentativas debitadas.");
    }else if(lado[tirox][tiroy]=='>'){
        printf("\n  >>> Voce encontrou recursos extras! Escolha o que deseja receber: ");
        printf("\n\n   [A] = 1 Bomba H\n   [B] = 2 Bombas Atomicas\n   [C] = +100 pontos\n   [D] = +10 tentativas\n   [E] = +2 espioes\n   [F] = +5 minas no campo inimigo\n   >>> ");
        char temp;
        if(flag==1){
            flag=sort(5);
            if(flag==0){temp='a';}
            if(flag==1){temp='b';}
            if(flag==2){temp='c';}
            if(flag==3){temp='d';}
            if(flag==4){temp='e';}
            if(flag==5){temp='f';}
        } else {
            do{
            temp=getchar();
            }while((temp==' ')||(temp=='\n'));
        }
        if((temp=='a')||(temp=='A')){
            placar->bombash++;
        } else if((temp=='b')||(temp=='B')){
            placar->bombas+=2;
        } else if((temp=='c')||(temp=='C')){
            placar->pontos+=100;
        } else if((temp=='d')||(temp=='D')){
            placar->tentativas += 10;
        } else if((temp=='e')||(temp=='E')){
            placar->espioes +=2;
        } else if((temp=='f')||(temp=='F')){
            if(tab==tab1){ int i, j, flag=0;
                for(i=0;i<9;i++){
                    for(j=0;j<19;j++){
                        if(lado1[i][j]=='#'){
                            flag++;
                        }
                    }
                }
                if(flag>9){
                    navios(lado1, 5, 1, 'M');
                } else {
                    printf("Impossivel aplicar recurso: Existem menos de 10 coordenadas.");
                }
            }
            if (tab==tab2){ int i, j, flag=0;
                for(i=0;i<9;i++){
                    for(j=0;j<19;j++){
                        if(lado1[i][j]=='#'){
                            flag++;
                        }
                    }
                }
                if(flag>9){
                    navios(lado2, 5, 1, 'M');
                } else {
                    printf("Impossivel aplicar recurso: Existem menos de 10 coordenadas.");
                }
            }
        } else {
            printf("\nOh oh, parece que o char = %c nao foi reconhecido\n", temp);
        }
    } else {
        printf("\n\n Oh oh, parece que ocorreu um erro.\n\n");
        printf("A matriz retornou um char invalido: '%c'", lado[tirox][tiroy]);
    }
}

int rodadaCOM(estru *placar){
    limpar();
    int i, j, tirox, tiroy;

    do {
        tirox=sort(9);
        tiroy=sort(19);
    }while(tab2[tirox][tiroy]!='.');

    if((tirox>1)&&(tiroy<18)&&(tirox<8)&&(tiroy>1)&&(placar->bombash>0)){
        placar->bombash-=1;
        for(i=-2;i<3;i++){
            for(j=-2;j<3;j++){
                if(tab2[tirox+i][tiroy+j]=='.'){
                    tiro(tirox+i, tiroy+j, tab2, lado1, &*placar, 1);
                    tab2[tirox+i][tiroy+j]=lado1[tirox+i][tiroy+j];
                }
            }
        }
        placar->tentativas -= 1;
        logo(3,2, tab2, &*placar);
        printf("[ENTER TO CONTINUE]");
        getchar();

    } else if((tirox>0)&&(tiroy<19)&&(tirox<9)&&(tiroy>0)&&(placar->bombas>0)){
        placar->bombas-=1;
        for(i=-1;i<2;i++){
            for(j=-1;j<2;j++){
                if(tab2[tirox+i][tiroy+j]=='.'){
                    tiro(tirox+i, tiroy+j, tab2, lado1, &*placar, 1);
                }
                tab2[tirox+i][tiroy+j]=lado1[tirox+i][tiroy+j];
            }
        }
    printf("\n");
    placar->tentativas -= 1;
    logo(3,2, tab2, &*placar);
    printf("[ENTER TO CONTINUE]");
    getchar();


    }else if(placar->espioes>0){
        placar->espioes-=1;
        for(i=0;i<10;i++){
            if(tab2[i][tiroy]=='.'){
                tiro(i, tiroy, tab2, lado1, &*placar, 1);
                tab2[i][tiroy]=lado1[i][tiroy];
            }
        }
        printf("\n");
        placar->tentativas -= 1;
        logo(3,2, tab2, &*placar);
        printf("[ENTER TO CONTINUE]");
        getchar();

    }else if((tirox>0)&&(tiroy>0)&&(tirox<9)&&(tiroy<19)){
        placar->tentativas -= 1;
        tab2[tirox][tiroy]=lado1[tirox][tiroy];
        limpar();
        tiro(tirox, tiroy, tab2, lado1, &*placar, 1);
        logo(3,2, tab2, &*placar);
        printf("[ENTER TO CONTINUE]");
        getchar();
    } else {
        printf("\n  Erro na escolha de coordenadas. ");
    }

    if(placar->tentativas<=0){
        jogando='f';
        return(0);
    }else if(placar->restantes==0){
        jogando='f';
        return(1);
    } else {
        return(2);
    }
}

int logo(int num, int num2, char tab[][20], estru *placar){
    if(num==1){
        printf("__________    _____ ___________ _____   .____      ___ ___     _____    \n");
        printf("\\______   \\  /  _  \\\\__    ___//  _  \\  |    |    /   |   \\   /  _  \\   \n");
        printf(" |    |  _/ /  /_\\  \\ |    |  /  /_\\  \\ |    |   /    ~    \\ /  /_\\  \\  \n");
        printf(" |    |   \\/    |    \\|    | /    |    \\|    |___\\    Y    //    |    \\ \n");
        printf(" |______  /\\____|__  /|____| \\____|__  /|_______ \\\\___|_  / \\____|__  / \n");
        printf("        \\/         \\/                \\/         \\/      \\/          \\/  \n");
        printf("          _______      _____ ____   ____ _____   .____                  \n");
        printf("          \\      \\    /  _  \\\\   \\ /   //  _  \\  |    |                 \n");
        printf("          /   |   \\  /  /_\\  \\\\   Y   //  /_\\  \\ |    |                 \n");
        printf("         /    |    \\/    |    \\\\     //    |    \\|    |___              \n");
        printf("         \\____|__  /\\____|__  / \\___/ \\____|__  /|_______ \\             \n");
        printf("                 \\/         \\/                \\/         \\/             \n");
        printf("\n\n                            MODO DE JOGO\n\n                    |> 1 PLAYER     [PRESS A]\n                    |> 2 PLAYERS    [PRESS B]");
        printf("\n                    |> TUTORIAL     [PRESS C]");
        printf("\n                             ===>");
    }else if(num==2){
        printf("                                 0_,-.__ \n");
        printf("                                 |_.-._/ \n");
        printf("                                 |_--..\\ \n");
        printf("                                 |__--_/ \n");
        printf("     |''   ``\\                   | \n");
        printf("     |        \\                  |          \n");
        printf("     |         \\                 |        \n");
        printf("  ___,,,,,---==````\\        |M] \\ | ;|\\ |> \n");
        printf("            _   _   \\   ___,|H,,---==````````bno, \n");
        printf("     o  O  (_) (_)   \\ /          _     AWA / \n");
        printf("                      /         _(+)_  dM  / \n");
        printf("       \\@_,,,,,,---==``   \\      \\\\|//  M / \n");
        printf(" --''''``                         ===    / \n");
        printf("                                       // \n");
        printf("                                     ,'_____________________ \n");
        printf("    \\    \\    \\     \\               ,/~~~~~~~~~~~~~~~~~~~~~~ \n");
        printf("                          _____    ,'  ~~~   .-````-.~~~~~~ \n");
        printf("       .-````-.           ///==---   /`-._ ..-'      -.__..- \n");
        printf("             `-.__..-' =====\\\\\\\\\\\\ V/  .---\\. \n");
        printf("                       ~~~~~~~~~~~~, _',--/_.\\  .-````-. \n");
        printf("                             .-````-.___` --  \\|  \n");
    }else if(num==3){
        int alfa[10]={0,1,2,3,4,5,6,7,8,9}, i, j;
        printf("\n\n                           RODADA DO JOGADOR %i\n\n", num2);
        printf("     0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19\n");
        for(i=0;i<10;i++){
            printf("  %i ", alfa[i]);
            for(j=0;j<20;j++){
                printf(" %c ", tab[i][j]);
            }
            if(i==0){printf(" |> Pontuacao: %i", placar->pontos);}
            if(i==1){printf(" |> Alvos: %i", placar->restantes);}
            if(i==2){printf(" |");}if(i==3){printf(" |");}
            if(i==4){printf(" |> Tentativas: %i", placar->tentativas);}
            if(i==5){printf(" |> Bombas H: %i", placar->bombash);}
            if(i==6){printf(" |");}if(i==7){printf(" |");}
            if(i==8){printf(" |> Bombas Atomicas: %i", placar->bombas);}
            if(i==9){printf(" |> Espioes: %i", placar->espioes);}
            printf("\n\n");
        }
    }
}
