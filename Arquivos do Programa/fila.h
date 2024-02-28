#ifndef FILA_H
#define FILA_H

#include "jogo.h"

typedef struct fila Fila;

Fila *criarFila();

int inserirFila(Fila*, Carta);

int removerFila(Fila*, Carta*);

int acessarFila(Fila*, Carta*);

int exibirFila(Fila*);

int tamanhoFila(Fila*);

#endif /* FILA_H */
