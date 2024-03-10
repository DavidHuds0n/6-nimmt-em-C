#ifndef PILHA_H
#define PILHA_H

#include "carta.h"

typedef struct elementoPilha *Pilha;

Pilha *criarPilha();
int inserirPilha(Pilha*, Carta);
int removerPilha(Pilha*, Carta*); // Já remove e acessa
void embaralharPilha(Pilha*);
int tamanhoPilha(Pilha*);

#endif /* PILHA_H */
