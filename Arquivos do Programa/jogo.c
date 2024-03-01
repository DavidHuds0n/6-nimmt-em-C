#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "carta.h"
#include "jogo.h"

// Função para criar uma nova carta
Carta criarCarta(int numero, int jogador) {
    Carta novaCarta; // Cria uma nova carta
    novaCarta.numero = numero; // Define o número da carta
    novaCarta.jogador = jogador; // Define o jogador dono da carta

    // Cada carta tem pelo menos uma cabeça de boi
    novaCarta.bois = 1;

    // Condições especiais para atribuir cabeças de boi
    // Números terminados em 5 têm duas cabeças de boi
    if (numero % 10 == 5) {
        novaCarta.bois += 1;
    }

    // Múltiplos de 10 têm três cabeças de boi
    if (numero % 10 == 0 && numero != 0) {
        novaCarta.bois += 2;
    }

    // Dígitos repetidos (exceto 0) têm cinco cabeças de boi
    if(numero >= 11 && numero <= 99 && numero % 11 == 0) {
        novaCarta.bois += 4;
    }

    // O número 55 tem uma cabeça de boi adicional
    if(numero == 55){
        novaCarta.bois += 1;
    }

    // Retorna a nova carta criada
    return novaCarta;
}

// Função para criar o baralho preenchido e embaralhado
void setBaralho(Pilha* baralho){
    for(int i = 1; i <= 104 ; i++){
        Carta novaCarta = criarCarta(i, -1); // Todas as cartas são criadas inicialmente com o campo jogador = -1, pois não pertencem a nenhum jogador
        inserirPilha(baralho, novaCarta);
        embaralharPilha(baralho);
    }
}

// Função para criar uma lista de jogadores contendo as mãos de cada um
Lista** criarListaJogadores(int qtd_jogadores){
    // Verificar se qtd_jogadores é válida
    if (qtd_jogadores <= 0 || qtd_jogadores > 10) {
        printf("Número inválido de jogadores.\n");
        return NULL;
    }

    // Alocar memória para a lista de jogadores
    Lista** listaJogadores = (Lista**)malloc(sizeof(Lista*) * qtd_jogadores);
    if(listaJogadores == NULL) {
        printf("Erro ao alocar memória para lista de jogadores.\n");
        return NULL;
    }

    // Inicializar cada lista de jogador
    for(int i = 0 ; i < qtd_jogadores ; i++){
        listaJogadores[i] = criarLista();
        if(listaJogadores[i] == NULL) {
            printf("Erro ao criar lista de mão para jogador %d.\n", i);
            return NULL;
        }
    }

    return listaJogadores;
}

// Função para preencher as mãos de cada jogador com 10 cartas cada
int preencherMaos(int qtd_jogadores, Lista** listaJogadores, Pilha* baralho){
    // Verificar se a lista de jogadores e a pilha de baralho são válidas
    if (listaJogadores == NULL || baralho == NULL) {
        printf("Lista de jogadores ou pilha de baralho inválida.\n");
        return 0;
    }

    // Verificar se a quantidade de jogadores é válida
    if (qtd_jogadores <= 0 || qtd_jogadores > 10) {
        printf("Número inválido de jogadores.\n");
        return 0;
    }

    // Preencher as mãos de cada jogador com 10 cartas
    for(int i = 0 ; i < qtd_jogadores ; i++){
        for(int j = 0 ; j < 10 ; j++){
            Carta cartaRemovida;
            if (!removerPilha(baralho, &cartaRemovida)) {
                printf("Erro ao remover carta do baralho.\n");
                return 0;
            }

            cartaRemovida.jogador = i+1;

            if (!inserirOrdenado(listaJogadores[i], cartaRemovida)) {
                printf("Erro ao inserir carta na mão do jogador.\n");
                return 0;
            }

        }
    }

    return 1;
}


