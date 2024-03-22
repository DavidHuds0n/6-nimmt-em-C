#ifndef LISTA_H
#define LISTA_H

#include "structs_auxiliares.h"

typedef struct elemento *Lista;

Lista *criarLista();
int inserirOrdenado(Lista*, Carta);
int acessarIndice(Lista*, int, Carta*);
int removerIndice(Lista*, int);
int exibirLista(Lista*);
int tamanhoLista(Lista*);

#endif /* LISTA_H */
