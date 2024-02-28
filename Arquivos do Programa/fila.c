#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "jogo.h"

struct elementoFila {
    struct carta dados;
    struct elementoFila *prox;
};

typedef struct elementoFila Elemento;

Fila * criarFila(){
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila != NULL){
        *fila = NULL;
    }
    return fila;
}

int inserirFila(Fila *fila, struct carta novosdados){
    if (fila == NULL){
        return 0;
    }
    else if (*fila == NULL){
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        novo->dados = novosdados;
        novo->prox = NULL;
        *fila = novo;
        return 1;
    }
    else {
        Elemento *aux = *fila;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        novo->dados = novosdados;
        novo->prox = aux->prox;
        aux->prox = novo;
        return 1;
    }
}

int removerFila(Fila *fila, struct carta *acessado){
    if (fila == NULL || *fila == NULL){
         return 0;
    }
    else {
        Elemento *aux = *fila;
        *acessado = (*fila)->dados;
        *fila = aux->prox;
        free(aux);
        return 1;
    }
}

int acessarFila(Fila *fila, struct carta *acessado){
    if (fila == NULL || *fila == NULL){
         return 0;
    }
    else {
        *acessado = (*fila)->dados;
        return 1;
    }
}

int exibirFila(Fila *fila){
    if (fila == NULL || *fila == NULL){
        return 0;
    }
    else {
        Elemento *aux = *fila;
        while (aux != NULL){
            printf ("%d, %d, %d\n", aux->dados.bois, aux->dados.numero, aux->dados.jogador);
            aux = aux->prox;
        }
        return 1;
    }
}

int tamanhoFila(Fila *fila){
    int tam = 0;
    if (fila == NULL || *fila == NULL){
        return tam;
    }
    else {
        Elemento *aux = *fila;
        while (aux != NULL){
            tam++;
            aux = aux->prox;
        }
        return tam;
    }
}

