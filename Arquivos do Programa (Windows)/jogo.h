#ifndef JOGO_H
#define JOGO_H

#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "structs_auxiliares.h"

/* FUNÇÕES PARA A PREPARAÇÃO DO JOGO */

// Cria uma nova carta com número especificado
Carta criarCarta(int);

// Inicializa um baralho preenchendo uma pilha com as 104 cartas do baralho e as embaralha
void inicializarBaralho(Pilha*);

// Cria uma lista de jogadores com uma lista de cartas para cada um
Lista** criarListaJogadores(int);

// Distribui 10 cartas para cada jogador a partir do baralho
int distribuirCartasJogadores(Lista**, Pilha*, int);

// Cria um vetor de filas representando a mesa
Fila** criarMesa();

// Insere a primeira carta de cada fila da mesa
int inserirCartasMesa(Fila**, Pilha*);

// Configura as condições iniciais do jogo
int prepararJogo(int, Pilha**, Lista***, Fila***, Lista***);


/* FUNÇÕES PARA RODAR O JOGO */

// Retira as cartas de uma fila da mesa e as armazena em uma lista de cartas do jogador
int puxarCartasFila(Fila**, Lista**, int, int, int);

// Exibe o estado atual das filas e da mão do jogador
void exibirMesa(Fila **, Lista **, Lista **, Lista*);

// Joga o turno de cada jogador
void jogarTurno(int, Lista **, Lista *);

// Insere na mesa as cartas jogadas naquele turno
int inserirMesa(int, Fila**, Lista**, Lista*, Lista**);

// Função onde o jogo acontece
int jogar(int, Lista **, Fila **, Lista **);

// Contabiliza a pontuação de um jogador
int contarPontos(Lista *);

// Contabiliza e revela a pontuação de cada jogador
void fimJogo(int, Lista **);


/* FUNÇÕES PARA DEPURAÇÃO */

// Exibe as mãos de todos os jogadores para depuração
void exibirTudo(Lista **, int);

#endif /* JOGO_H */
