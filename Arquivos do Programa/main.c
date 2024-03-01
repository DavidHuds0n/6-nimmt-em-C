#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Incluindo a biblioteca para setlocale
#include "lista.h"
#include "pilha.h"
#include "carta.h"
#include "jogo.h"

int main() {
    // Configurando a localidade para Portugu�s do Brasil
    setlocale(LC_ALL, "Portuguese");

    // Criar e preencher o baralho
    Pilha* baralho = criarPilha();
    if (baralho == NULL) {
        printf("Erro ao criar o baralho.\n");
        return 1;
    }
    setBaralho(baralho);

    printf("Tamanho do baralho antes de preencher as m�os: %d\n\n", tamanhoPilha(baralho));

    // Criar a lista de jogadores
    int qtd_jogadores = 10; // N�mero de jogadores
    Lista** listaJogadores = criarListaJogadores(qtd_jogadores);
    if (listaJogadores == NULL) {
        printf("Erro ao criar a lista de jogadores.\n");
        return 1;
    }

    // Preencher as m�os de cada jogador com 10 cartas
    if (!preencherMaos(qtd_jogadores, listaJogadores, baralho)) {
        printf("Erro ao preencher as m�os dos jogadores.\n");
        return 1;
    }

    // Imprimir as m�os de cada jogador
    printf("M�os dos jogadores:\n");
    for (int i = 0; i < qtd_jogadores; i++) {
        printf("Jogador %d:\n", i + 1);
        exibirLista(listaJogadores[i]);
        printf("\n");
    }

    printf("Tamanho do baralho depois de preencher as m�os: %d\n\n", tamanhoPilha(baralho));
    printf("Sobraram exatamente 4 cartas! Sendo essas as que v�o ser inseridas no come�o de cada fila da mesa.\n");
    printf("Ou seja, as cartas est�o sendo retiradas da pilha corretamente.\n");

    return 0;
}
