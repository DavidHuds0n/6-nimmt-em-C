#ifndef JOGO_H
#define JOGO_H

#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "carta.h"

/* FUNÇÕES PARA A PREPARAÇÃO DO JOGO */
Carta criarCarta(int);                                  // Cria uma nova carta com número especificado

void inicializarBaralho(Pilha*);                        // Preenche uma pilha com as 104 cartas do baralho e as embaralha
Lista** criarListaJogadores(int);                       // Cria uma lista de jogadores com uma lista de cartas para cada um
int distribuirCartasJogadores(Lista**, Pilha*, int);    // Distribui 10 cartas para cada jogador a partir do baralho
Fila** criarMesa();                                     // Cria um vetor de filas representando a mesa
int inserirCartasMesa(Fila**, Pilha*);                  // Insere a primeira carta de cada fila

/* FUNÇÕES PARA RODAR O JOGO */
int puxarCartasFila(Fila**, Lista**, int, int);         // Retira as cartas de uma fila da mesa e as armazena em uma lista de cartas puxadas do jogador

int jogarPartida(Fila**, Lista**, Lista**, int);        /* Roda uma partida, com input do jogador 1 e gera inputs aleatórios para bots.
                                                        /* Insere cartas nas filas da mesa e, se necessário, puxa cartas de uma fila para a coleção de um jogador. */

#endif /* JOGO_H */
