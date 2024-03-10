#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pilha.h"
#include "carta.h"

struct elementoPilha {
    struct carta dados;
    struct elementoPilha *prox;
};

typedef struct elementoPilha Elemento;

Pilha *criarPilha(){
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha != NULL){
        *pilha = NULL;
    }
    return pilha;
}

int inserirPilha(Pilha *pilha, Carta novosdados){
    if (pilha == NULL){
        return 0;
    }
    else {
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        if (novo == NULL) return 0;
        novo->dados = novosdados;
        novo->prox = *pilha;
        *pilha = novo;
        return 1;
    }
}

int removerPilha(Pilha *pilha, Carta *acessado) {
    if (pilha == NULL || *pilha == NULL){
         return 0;
    }
    else {
        Elemento *aux = *pilha;
        *acessado = (*pilha)->dados;
        *pilha = aux->prox;
        free(aux);
        return 1;
    }
}

void embaralharPilha(Pilha *pilha){
    // Inicializa a semente para a geração de números aleatórios
    srand(time(NULL));

    int random, cont;
    Elemento *aux = *pilha;
    Elemento *aux2;
    struct carta guardar;
    for (int i = 0; i < (tamanhoPilha(pilha) - 1); i++){
        random = rand()%(tamanhoPilha(pilha));
        aux2 = *pilha;
        cont = 0;
        while (aux2 != NULL && cont < random){
            aux2 = aux2->prox;
            cont++;
        }
        guardar = aux->dados;
        aux->dados = aux2->dados;
        aux2->dados = guardar;
        aux = aux->prox;
    }
}

int tamanhoPilha(Pilha *pilha){
    int tam = 0;
    if (pilha == NULL || *pilha == NULL){
        return tam;
    }
    else {
        Elemento *aux = *pilha;
        while (aux != NULL){
            tam++;
            aux = aux->prox;
        }
        return tam;
    }
}
