#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PEDRA 1
#define PAPEL 2
#define TESOURA 3

int jogador;     // pontos do jogador
int computador;  // pontos do computador 


void imprimeItem(int item){
    if(item == PEDRA){
        printf("PEDRA");
    }
    else if(item == PAPEL){
        printf("PAPEL");
    }
    else{
        printf("TESOURA");
    }
}


/*
    Funcao que verifica qual jogador ganhou e retorna 1 ou 2
    retorna 0 ao empatar
*/


int verifica(int p1, int p2){

    int ganhador;
    if(p1 == p2){ //empate
        ganhador = 0;
    }

    if(p1==PEDRA && p2==TESOURA){ ganhador = 1; }
    if(p1==PEDRA && p2==PAPEL){ ganhador = 2; }

    if(p1==PAPEL && p2==PEDRA){ ganhador = 1; }
    if(p1==PAPEL && p2==TESOURA){ ganhador = 2; }

    if(p1==TESOURA && p2==PAPEL){ ganhador = 1; }
    if(p1==TESOURA && p2==PEDRA){ ganhador = 2; }

    return ganhador;
}


// Onde o jogo é executado ->


void jogo(){

    int itemJogador;
    int itemComputador;
    
    printf("\n Escolha 1.Pedra 2.Papel 3.Tesoura \n Item: ");
    scanf("%d", &itemJogador); //jogador faz sua escolha
    
    itemComputador = rand()%3+1; //computador faz uma escolha aleatoria 

    printf("\n  carregando"); // Exibir a Palavra Loading na tela em branco
        for(int i=0;i < 1; i++){ // abrir um laço de repetição com for
            system("sleep 01"); // pausa de 1 segundo
            printf("."); // escrever 1 "." na tela
            fflush(stdout); // atualizar a tela
        }

    //mostra quem escolheu oque
    printf("\n\n Voce -> ");
    imprimeItem(itemJogador);  // imprime o que o jogador escolheu
    printf(" x ");
    imprimeItem(itemComputador); // imprime o que o computador escolheu
    printf(" <- Computador.\n");

    //verifica quem ganhou
    int ganhador = verifica(itemJogador, itemComputador);

    //mostra o ganhador
    printf("\n");
    if(ganhador == 1){
        printf(" VOCE GANHOU!\n");
        jogador++;
    }
    else if(ganhador == 2){
        printf(" COMPUTADOR GANHOU!\n");
        computador++;
    }
    else{
        printf(" EMPATOU!\n");
    }
    printf("\n");
}

int main(){
    
    srand(time(NULL)); //usado para gerar numeros aleatorios diferentes
    system("clear"); // Limpar a tela

    printf("-------------------------------------------------------------------------------\n");
    printf("                           PEDRA - PAPEL - TESOURA                             \n");
    printf("-------------------------------------------------------------------------------\n");

    int i = 1;
    while(i == 1){ // Fica rodando o jogo até o jogador não quiser jogar mais 
        
        jogo(); // chama a função para rodar o jogo
        
        printf("  carregando"); // Exibir a Palavra Loading na tela em branco
        for(i=0;i < 3; i++){ // abrir um laço de repetição com for
            system("sleep 01"); // pausa de 1 segundo
            printf("."); // escrever 1 "." na tela
            fflush(stdout); // atualizar a tela
        }

        printf("\n\n-------------------------------------------------------------------------------\n");
        printf("------------------------- Deseja jogar novamente? -----------------------------\n");
        printf("Aperte (1) para jogar novamente e (0) para sair do jogo:\n");
        scanf("%d",&i);
        printf("-------------------------------------------------------------------------------\n");
        
    }
    
    printf(" ------------- <Total de Pontos> ------------------\n");
    printf("         Voce: %d \n", jogador);
    printf("   Computador: %d \n", computador);
    printf("\n Bye Bye!!");

    return 0;
}