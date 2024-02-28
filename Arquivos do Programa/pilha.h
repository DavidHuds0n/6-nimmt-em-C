#ifndef PILHA_H
#define PILHA_H

#include "jogo.h"

typedef struct elementoPilha *Pilha;

Pilha *criarPilha();

int inserirPilha(Pilha*, Carta);

int removerPilha(Pilha*, Carta*); // J� remove e acessa

void embaralharPilha(Pilha*);

int tamanhoPilha(Pilha*);

void exibirPilha(Pilha*);
// Exibir desnecess�rio, ta a� s� pra testes de controle

#endif /* PILHA_H */
