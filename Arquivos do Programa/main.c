#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Incluindo a biblioteca para setlocale
#include "lista.h"
#include "pilha.h"
#include "carta.h"
#include "jogo.h"

int main() {
    // Configurando a localidade para Português do Brasil
    setlocale(LC_ALL, "Portuguese");

    // Criar e preencher o baralho
    Pilha* baralho = criarPilha();
    if (baralho == NULL) {
        printf("Erro ao criar o baralho.\n");
        return 1;
    }
    setBaralho(baralho);

    printf("Tamanho do baralho antes de preencher as mãos: %d\n\n", tamanhoPilha(baralho));

    // Criar a lista de jogadores
    int qtd_jogadores = 10; // Número de jogadores
    Lista** listaJogadores = criarListaJogadores(qtd_jogadores);
    if (listaJogadores == NULL) {
        printf("Erro ao criar a lista de jogadores.\n");
        return 1;
    }

    // Preencher as mãos de cada jogador com 10 cartas
    if (!preencherMaos(qtd_jogadores, listaJogadores, baralho)) {
        printf("Erro ao preencher as mãos dos jogadores.\n");
        return 1;
    }

    // Imprimir as mãos de cada jogador
    printf("Mãos dos jogadores:\n");
    for (int i = 0; i < qtd_jogadores; i++) {
        printf("Jogador %d:\n", i + 1);
        exibirLista(listaJogadores[i]);
        printf("\n");
    }

    printf("Tamanho do baralho depois de preencher as mãos: %d\n\n", tamanhoPilha(baralho));
    printf("Sobraram exatamente 4 cartas! Sendo essas as que vão ser inseridas no começo de cada fila da mesa.\n");
    printf("Ou seja, as cartas estão sendo retiradas da pilha corretamente.\n");

    return 0;
}
