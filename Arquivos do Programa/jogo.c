#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "carta.h"
#include "jogo.h"

#define QTD_CARTAS 104  // Quantidade de cartas do baralho
#define MAO_INIT 10     // Quantidade inicial de cartas na m�o de um jogador
#define QTD_FILAS 4     // Quantidade de filas na mesa
#define MAX_ROUNDS 10   // Quantidade m�xima de partidas do jogo

/* FUN��ES PARA A PREPARA��O DO JOGO */

/* Cria uma nova carta com n�mero e jogador especificados */
Carta criarCarta(int numero) {
    Carta novaCarta;
    novaCarta.numero = numero; // Define o n�mero da carta
    novaCarta.jogador = -1; // Define o jogador dono da carta

    /* Define a quantidade de cabe�as de boi com base no n�mero da carta */
    novaCarta.bois = 1; // Toda carta tem pelo menos 1 boi
    if (numero % 10 == 5) novaCarta.bois += 1; // Terminadas em 5 tem 2 bois
    if (numero % 10 == 0 && numero != 0) novaCarta.bois += 2; // M�ltiplos de 10 tem 3 bois
    if (numero >= 11 && numero <= 99 && numero % 11 == 0) novaCarta.bois += 4; // D�gitos repetidos (exceto 0) tem 5 bois
    if (numero == 55) novaCarta.bois += 1; // N�mero 55 � um caso especial (termina em 5 e tem digitos repetidos), logo tem 7 bois

    return novaCarta;
}

/* Preenche uma pilha com as 104 cartas do baralho e as embaralha */
void inicializarBaralho(Pilha* baralho){
    for(int i = 1; i <= QTD_CARTAS ; i++){
        Carta novaCarta = criarCarta(i); // -1 signifca que n�o h� jogador associado � carta
        inserirPilha(baralho, novaCarta);
    }
    embaralharPilha(baralho);
}

/* Cria uma lista de jogadores com uma lista de cartas para cada um */
Lista** criarListaJogadores(int qtd_jogadores){
    /* Aloca mem�ria para a lista de jogadores */
    Lista** listaJogadores = (Lista**)malloc(sizeof(Lista*) * qtd_jogadores);
    if(listaJogadores == NULL) return NULL;

    /* Inicializa a lista de cada jogador */
    for(int i = 0 ; i < qtd_jogadores ; i++){
        listaJogadores[i] = criarLista();
        if(listaJogadores[i] == NULL) return NULL;
    }

    return listaJogadores;
}

/* Distribui 10 cartas para cada jogador a partir do baralho */
int distribuirCartasJogadores(Lista** maosJogadores, Pilha* baralho, int qtd_jogadores){
    /* Distribui 10 cartas para cada jogador */
    for(int i = 0 ; i < qtd_jogadores ; i++){
        for(int j = 0 ; j < MAO_INIT ; j++){
            Carta cartaRemovida;
            if (!removerPilha(baralho, &cartaRemovida)) return 0;

            cartaRemovida.jogador = i;

            if (!inserirOrdenado(maosJogadores[i], cartaRemovida)) return 0;
        }
    }

    return 1;
}

/* Cria um vetor de filas representando a mesa */
Fila** criarMesa(){
    Fila** mesa = (Fila**)malloc(sizeof(Fila*) * QTD_FILAS);
    if (mesa == NULL) return NULL;

    /* Inicializa cada fila da mesa */
    for(int i = 0 ; i < QTD_FILAS ; i++){
        mesa[i] = criarFila();
        if (mesa[i] == NULL) return NULL;
    }

    return mesa;
}

/* Insere a primeira carta de cada fila da mesa */
int inserirCartasMesa(Fila** mesa, Pilha* baralho){
    /* Insere uma carta do baralho em cada fila da mesa */
    for(int i = 0 ; i < QTD_FILAS ; i++){
        Carta cartaRemovida;
        if(!removerPilha(baralho, &cartaRemovida)) return 0;
        if(!inserirFila(mesa[i], cartaRemovida)) return 0;
    }

    return 1;
}

/* FUN��ES PARA RODAR O JOGO */

/* Retira as cartas de uma fila da mesa e as armazena em uma lista de cartas do jogador */
int puxarCartasFila(Fila** mesa, Lista** colecaoCartasPuxadas, int indiceJogador, int indiceFilaMesa){
    /* Verifica se o �ndice do jogador est� dentro do intervalo v�lido */
    if (indiceJogador < 0 || indiceJogador > 9) {
        printf("�ndice de jogador inv�lido.\n");
        return 0; // Retorna 0 indicando falha
    }

    /* Verifica se o �ndice da fila est� dentro do intervalo v�lido */
    if (indiceFilaMesa < 0 || indiceFilaMesa >= 4) {
        printf("�ndice de fila inv�lido.\n");
        return 0; // Retorna 0 indicando falha
    }

    int qtd_Fila = tamanhoFila(mesa[indiceFilaMesa]);
    for(int i = 0 ; i < qtd_Fila ; i++){
        Carta cartaRemovida;
        if (!removerFila(mesa[indiceFilaMesa], &cartaRemovida)) {
        printf("Erro ao remover carta da fila.\n");
        return 0; // Retorna 0 indicando falha
        }
        if (!inserirOrdenado(colecaoCartasPuxadas[indiceJogador], cartaRemovida)) {
            printf("Erro ao inserir carta na cole��o do jogador.\n");
            return 0; // Retorna 0 indicando falha
        }
    }

    return 1;
}
