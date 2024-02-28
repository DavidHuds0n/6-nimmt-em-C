#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"
#include "pilha.h"
#include "jogo.h"

int main()
{
    //teste criando lista:
    Pilha *pilha;
    pilha = NULL;
    pilha = criarPilha();
    if (*pilha == NULL){
        printf ("fila criada com sucesso.\n");
    }

    //teste de inserir na fila:
    struct carta carta1;
    carta1.bois = 1;
    carta1.jogador = 3;
    carta1.numero = 7;
    struct carta carta2;
    carta2.bois = 6;
    carta2.jogador = 4;
    carta2.numero = 17;
    struct carta carta3;
    carta3.bois = 7;
    carta3.jogador = 9;
    carta3.numero = 10;
    inserirPilha(pilha, carta1);
    inserirPilha(pilha, carta2);
    inserirPilha(pilha, carta3);

    //teste do exibir:
    exibirPilha(pilha);

    embaralharPilha(pilha);

    exibirPilha(pilha);

    embaralharPilha(pilha);

    exibirPilha(pilha);


    printf ("\nEssa pilha tem %d cartas.", tamanhoPilha(pilha));

    struct carta acessar;
    //acessarFila(fila, &acessar);

    removerPilha(pilha, &acessar);
    exibirPilha(pilha);

    printf ("\n\n\n%d, %d, %d", acessar.bois, acessar.numero, acessar.jogador);

    return 0;
}
