#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "carta.h"
#include "jogo.h"

// Fun��o para criar uma nova carta
Carta criarCarta(int numero, int jogador) {
    Carta novaCarta; // Cria uma nova carta
    novaCarta.numero = numero; // Define o n�mero da carta
    novaCarta.jogador = jogador; // Define o jogador dono da carta

    // Cada carta tem pelo menos uma cabe�a de boi
    novaCarta.bois = 1;

    // Condi��es especiais para atribuir cabe�as de boi
    // N�meros terminados em 5 t�m duas cabe�as de boi
    if (numero % 10 == 5) {
        novaCarta.bois += 1;
    }

    // M�ltiplos de 10 t�m tr�s cabe�as de boi
    if (numero % 10 == 0 && numero != 0) {
        novaCarta.bois += 2;
    }

    // D�gitos repetidos (exceto 0) t�m cinco cabe�as de boi
    if(numero >= 11 && numero <= 99 && numero % 11 == 0) {
        novaCarta.bois += 4;
    }

    // O n�mero 55 tem uma cabe�a de boi adicional
    if(numero == 55){
        novaCarta.bois += 1;
    }

    // Retorna a nova carta criada
    return novaCarta;
}

// Fun��o para criar o baralho preenchido e embaralhado
void setBaralho(Pilha* baralho){
    for(int i = 1; i <= 104 ; i++){
        Carta novaCarta = criarCarta(i, -1); // Todas as cartas s�o criadas inicialmente com o campo jogador = -1, pois n�o pertencem a nenhum jogador
        inserirPilha(baralho, novaCarta);
        embaralharPilha(baralho);
    }
}

// Fun��o para criar uma lista de jogadores contendo as m�os de cada um
Lista** criarListaJogadores(int qtd_jogadores){
    // Verificar se qtd_jogadores � v�lida
    if (qtd_jogadores <= 0 || qtd_jogadores > 10) {
        printf("N�mero inv�lido de jogadores.\n");
        return NULL;
    }

    // Alocar mem�ria para a lista de jogadores
    Lista** listaJogadores = (Lista**)malloc(sizeof(Lista*) * qtd_jogadores);
    if(listaJogadores == NULL) {
        printf("Erro ao alocar mem�ria para lista de jogadores.\n");
        return NULL;
    }

    // Inicializar cada lista de jogador
    for(int i = 0 ; i < qtd_jogadores ; i++){
        listaJogadores[i] = criarLista();
        if(listaJogadores[i] == NULL) {
            printf("Erro ao criar lista de m�o para jogador %d.\n", i);
            return NULL;
        }
    }

    return listaJogadores;
}

// Fun��o para preencher as m�os de cada jogador com 10 cartas cada
int preencherMaos(int qtd_jogadores, Lista** listaJogadores, Pilha* baralho){
    // Verificar se a lista de jogadores e a pilha de baralho s�o v�lidas
    if (listaJogadores == NULL || baralho == NULL) {
        printf("Lista de jogadores ou pilha de baralho inv�lida.\n");
        return 0;
    }

    // Verificar se a quantidade de jogadores � v�lida
    if (qtd_jogadores <= 0 || qtd_jogadores > 10) {
        printf("N�mero inv�lido de jogadores.\n");
        return 0;
    }

    // Preencher as m�os de cada jogador com 10 cartas
    for(int i = 0 ; i < qtd_jogadores ; i++){
        for(int j = 0 ; j < 10 ; j++){
            Carta cartaRemovida;
            if (!removerPilha(baralho, &cartaRemovida)) {
                printf("Erro ao remover carta do baralho.\n");
                return 0;
            }

            cartaRemovida.jogador = i+1;

            if (!inserirOrdenado(listaJogadores[i], cartaRemovida)) {
                printf("Erro ao inserir carta na m�o do jogador.\n");
                return 0;
            }

        }
    }

    return 1;
}


