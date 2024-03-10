#ifndef FILA_H
#define FILA_H

#include "carta.h"

// PERGUNTAR PRA ROBERTO SE ISSO PODE:
typedef struct elementoFila {
    struct carta dados;
    struct elemento *prox;
} Elemento;

struct fila {
	struct elementoFila *inicio;
	struct elementoFila *fim;
};
///////////////////////////////////////

typedef struct fila Fila;

Fila *criarFila();
int inserirFila(Fila*, Carta);
int removerFila(Fila*, Carta*);
int acessarFila(Fila*, Carta*);
int exibirFila(Fila*);
int tamanhoFila(Fila*);

#endif /* FILA_H */
