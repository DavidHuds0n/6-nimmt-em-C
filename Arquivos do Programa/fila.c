#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "carta.h"


Fila* criarFila(){
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    if (fila != NULL){
        fila->inicio = NULL;
		fila->fim = NULL;
    }
    return fila;
}

int inserirFila(Fila *fila, Carta novosdados){
    if (fila == NULL){
        return 0;
    }
    else{
        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
		if (novo == NULL) return 0;
        novo->dados = novosdados;
        novo->prox = NULL;
		if(fila->fim == NULL){
			fila->inicio = novo;
		}
		else{
			fila->fim->prox = novo;
		}
		fila->fim = novo;
		return 1;
    }
}

int removerFila(Fila *fila, Carta *acessado){
    if (fila == NULL || fila->inicio == NULL){
         return 0;
    }
    else {
        Elemento *aux = fila->inicio;
        *acessado = fila->inicio->dados;
        fila->inicio = fila->inicio->prox;
		if (fila->inicio == NULL){
			fila->fim = NULL;
		}
        free(aux);
        return 1;
    }
}

int acessarFila(Fila *fila, Carta *acessado){
    if (fila == NULL || fila->inicio == NULL){
         return 0;
    }
    else {
        *acessado = fila->inicio->dados;
        return 1;
    }
}

int exibirFila(Fila *fila) {
    if (fila == NULL || fila->inicio == NULL) {
        return 0;
    }

    printf("Bois:   ");
    Elemento *aux = fila->inicio;
    while (aux != NULL) {
        printf(" {%d}     ", aux->dados.bois);
        aux = aux->prox;
    }
    printf("\n");

    printf("Numero: ");
    aux = fila->inicio;
    while (aux != NULL) {
        printf("[%3d] ", aux->dados.numero); // Usando a formatação %6d para imprimir com 6 caracteres
        aux = aux->prox;
        if (aux == NULL) {
            break;
        }
        printf("-> ");
    }
    printf("\n");

    printf("Index:  ");
    int cont = 1;
    aux = fila->inicio;
    while (aux != NULL) {
        printf("(%3d)    ", cont);
        aux = aux->prox;
        cont++;
    }
    printf("\n");

    return 1;
}


int tamanhoFila(Fila *fila){
    int tam = 0;
    if (fila == NULL || fila->inicio == NULL){
        return tam;
    }
    else {
        Elemento *aux = fila->inicio;
        while (aux != NULL){
            tam++;
            aux = aux->prox;
        }
        return tam;
    }
}

