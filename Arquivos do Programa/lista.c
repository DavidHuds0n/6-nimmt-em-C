#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "jogo.h"

struct elementoLista{
    struct carta dados; //define a carta e seus dados como parte do elemento
    struct elementoLista *prox; //define o apontamento para o pr�ximo elemento da lista
};

typedef struct elementoLista Elemento; //define Elemento como um tipo

Lista * criarLista(){ //cria��o da lista de m�o de cartas
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL){
        *lista = NULL;
    }
    return lista;
}

int inserirOrdenado(Lista *lista, Carta novosdados){ //inserir as cartas de maneira ordenada na m�o
    if (lista == NULL){
        return 0;
    }
    else if (*lista == NULL){
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        novo->dados = novosdados;
        novo->prox = NULL;
        *lista = novo;
        return 1;
    }
    else {
        Elemento *aux = *lista;
        Elemento *ant = *lista;
        while (aux != NULL && novosdados.numero > aux->dados.numero){
            ant = aux;
            aux = aux->prox;
        }
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        novo->dados = novosdados;
        novo->prox = aux;
        ant->prox = novo;
        return 1;
    }
}

int acessarIndice(Lista *lista, int indice, Carta *acessado){ //acessa e obtem a carta com o �ndice
    indice -= 1;

    if (lista == NULL || *lista == NULL){
         return 0;
    }
    else {
        int cont = 0;
        Elemento *aux = *lista;
        while (aux != NULL && cont < indice){
            aux = aux->prox;
            cont++;
        }
        if (aux != NULL){
            *acessado = aux->dados;
        }
        return 1;
    }
}

int removerIndice(Lista *lista, int indice){
    indice -= 1;

    if (lista == NULL || *lista == NULL){
        return 0;
    }
    else if (indice > (quantidadeLista(lista) - 1)){
        return 0;
    }
    else if (indice == 0){
        Elemento *aux = *lista;
        *lista = aux->prox;
        free(aux);
    }
    else {
        int cont = 0;
        Elemento *aux = *lista;
        Elemento *ant = *lista;
        while (aux != NULL && cont < indice){
            ant = aux;
            aux = aux->prox;
            cont++;
        }
        ant->prox = aux->prox;
        free(aux);
        return 1;
    }
}

int exibirLista(Lista *lista){
    if (lista == NULL || *lista == NULL){
        return 0;
    }

    printf("Bois:   ");
    Elemento *aux = *lista;
    while(aux != NULL){
        printf(" {%d}     ", aux->dados.bois);
        aux = aux->prox;
    }
    printf("\n");

    printf("Numero: ");
    aux = *lista;
    while(aux != NULL){
        printf("[%3d] ", aux->dados.numero);
        aux = aux->prox;
        if(aux == NULL){
            break;
        }
        printf("-> ");
    }
    printf("\n");

    printf("Index:  ");
    int cont = 1;
    aux = *lista;
    while(aux != NULL){
        printf(" (%d)     ", cont);
        aux = aux->prox;
        cont++;
    }
    printf("\n");

    return 1;
}


int quantidadeLista(Lista *lista){ //acessa a quantidade de cartas na m�o
    int cont = 0;
    if (lista == NULL || *lista == NULL){
        return cont;
    }
    else {
        Elemento *aux = *lista;
        while (aux != NULL){
            cont++;
            aux = aux->prox;
        }
        return cont;
    }
}
