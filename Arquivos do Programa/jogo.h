#ifndef JOGO_H
#define JOGO_H

#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "carta.h"

// Fun��o para criar uma nova carta
Carta criarCarta(int, int);

// Fun��o para preencher uma pilha com as cartas do baralho
void setBaralho(Pilha*);

// Fun��o para criar uma lista de jogadores contendo as m�os (listas) de cada um
Lista** criarListaJogadores(int);

// Fun��o para preencher as m�os de cada jogador com 10 cartas
int preencherMaos(int, Lista**, Pilha*);

#endif /* JOGO_H */

