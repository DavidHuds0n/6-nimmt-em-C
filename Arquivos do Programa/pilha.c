#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pilha.h"
#include "jogo.h"

struct elementoPilha {
    struct carta dados;
    struct elementoPilha *prox;
};

typedef struct elementoPilha Elemento;

Pilha *criarPilha(){
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    if (pilha != NULL){
        *pilha = NULL;
    }
    return pilha;
}

int inserirPilha(Pilha *pilha, struct carta novosdados){
    if (pilha == NULL){
        return 0;
    }
    else {
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        novo->dados = novosdados;
        novo->prox = *pilha;
        *pilha = novo;
        return 1;
    }
}

int removerPilha(Pilha *pilha, struct carta *acessado) {
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
    int random, cont;
    Elemento *aux, *aux2;
    for (int i = 0; i < (tamanhoPilha(pilha) - 1); i++){
        aux = *pilha;
        cont = 0;
        while (aux != NULL && cont < i){
            aux = aux->prox;
            cont++;
        }
        random = rand()%104;
        aux2 = *pilha;
        cont = 0;
        Elemento *guardar = (Elemento *)malloc(sizeof(Elemento));
        while (aux2 != NULL && cont < random){
            aux2 = aux2->prox;
            cont++;
        }
        guardar->dados = aux->dados;
        aux->dados = aux2->dados;
        aux2->dados = guardar->dados;
        free(guardar);
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

void exibirPilha(Pilha *pilha){
    if (pilha == NULL || *pilha == NULL){
        return;
    }
    else {
        Elemento *aux = *pilha;
        while (aux != NULL){
            printf ("%d, %d, %d\n", aux->dados.bois, aux->dados.numero, aux->dados.jogador);
            aux = aux->prox;
        }
        return;
    }
}
