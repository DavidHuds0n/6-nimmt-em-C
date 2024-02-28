#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Para a função time
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "jogo.h"

int main() {
    // Criando uma lista de cartas
    Lista *lista = criarLista();

    // Criar algumas cartas para inserir na lista
    Carta carta1 = criarCarta(9, 1);
    Carta carta2 = criarCarta(15, 2);
    Carta carta3 = criarCarta(25, 3);
    Carta carta4 = criarCarta(10, 4);
    Carta carta5 = criarCarta(20, 5);

    // Inserindo as cartas na lista ordenadamente
    inserirOrdenado(lista, carta1);
    inserirOrdenado(lista, carta2);
    inserirOrdenado(lista, carta3);
    inserirOrdenado(lista, carta4);
    inserirOrdenado(lista, carta5);

    // Exibindo a lista de cartas
    printf("Lista de cartas:\n");
    exibirLista(lista);

    // Acessando uma carta da lista pelo índice
    Carta carta_acessada;
    int indice_acesso = 2;
    if (acessarIndice(lista, indice_acesso, &carta_acessada)) {
        printf("\nAcessando a carta com índice %d na lista:\n", indice_acesso);
        printf("Número: %d\n", carta_acessada.numero);
        printf("Bois: %d\n", carta_acessada.bois);
        printf("Jogador: %d\n", carta_acessada.jogador);
    } else {
        printf("\nErro ao acessar a carta com índice %d na lista.\n", indice_acesso);
    }

    // Removendo uma carta da lista
    printf("\nRemovendo a carta com índice 2 da lista...\n");
    removerIndice(lista, 2);

    // Exibindo a lista após a remoção
    printf("\nLista após remoção:\n");
    exibirLista(lista);

    // Exibindo a quantidade de cartas na lista
    printf("\nQuantidade de cartas na lista: %d\n", quantidadeLista(lista));

    // Criando uma pilha de cartas
    Pilha *pilha = criarPilha();

    // Inserindo algumas cartas na pilha
    inserirPilha(pilha, carta1);
    inserirPilha(pilha, carta2);
    inserirPilha(pilha, carta3);
    inserirPilha(pilha, carta4);
    inserirPilha(pilha, carta5);

    // Exibindo a pilha de cartas
    printf("\nPilha de cartas:\n");
    exibirPilha(pilha);

    // Embaralhando a pilha
    printf("\nEmbaralhando a pilha...\n");
    embaralharPilha(pilha);

    // Exibindo a pilha embaralhada
    printf("\nPilha de cartas embaralhada:\n");
    exibirPilha(pilha);

    // Removendo uma carta da pilha
    Carta carta_removida;
    if (removerPilha(pilha, &carta_removida)) {
        printf("\nCarta removida da pilha:\n");
        printf("Número: %d\n", carta_removida.numero);
        printf("Bois: %d\n", carta_removida.bois);
        printf("Jogador: %d\n", carta_removida.jogador);
    } else {
        printf("\nPilha vazia ou erro ao remover carta.\n");
    }

    // Exibindo a pilha após a remoção
    printf("\nPilha após remoção:\n");
    exibirPilha(pilha);

    // Exibindo o tamanho da pilha
    printf("\nTamanho da pilha: %d\n", tamanhoPilha(pilha));

    // Criando uma fila de cartas
    Fila *fila = criarFila();

    // Inserindo algumas cartas na fila
    inserirFila(fila, carta1);
    inserirFila(fila, carta2);
    inserirFila(fila, carta3);
    inserirFila(fila, carta4);
    inserirFila(fila, carta5);

    // Exibindo a fila de cartas
    printf("\nFila de cartas:\n");
    exibirFila(fila);

    // Removendo uma carta da fila
    if (removerFila(fila, &carta_removida)) {
        printf("\nCarta removida da fila:\n");
        printf("Número: %d\n", carta_removida.numero);
        printf("Bois: %d\n", carta_removida.bois);
        printf("Jogador: %d\n", carta_removida.jogador);
    } else {
        printf("\nFila vazia ou erro ao remover carta.\n");
    }

    // Exibindo a fila após a remoção
    printf("\nFila após remoção:\n");
    exibirFila(fila);

    // Exibindo o tamanho da fila
    printf("\nTamanho da fila: %d\n", tamanhoFila(fila));

    // Liberando a memória alocada para a lista, pilha e fila
    free(lista);
    free(pilha);
    free(fila);

    return 0;
}
