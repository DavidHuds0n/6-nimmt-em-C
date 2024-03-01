#ifndef JOGO_H
#define JOGO_H

#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "carta.h"

// Função para criar uma nova carta
Carta criarCarta(int, int);

// Função para preencher uma pilha com as cartas do baralho
void setBaralho(Pilha*);

// Função para criar uma lista de jogadores contendo as mãos (listas) de cada um
Lista** criarListaJogadores(int);

// Função para preencher as mãos de cada jogador com 10 cartas
int preencherMaos(int, Lista**, Pilha*);

#endif /* JOGO_H */

