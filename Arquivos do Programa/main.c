#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "carta.h"
#include "jogo.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    Pilha *baralho = NULL;
    Lista **maosJogadores = NULL;
    Fila **mesa = NULL;
    Lista **colecaoCartasPuxadas = NULL;
    Lista *cartasTurno = NULL;

    // Define a quantidade de jogadores
    int qtd_jogadores;
    do{
        printf("Defina quantos jogadores v�o participar desse jogo: ");
        scanf("%d", &qtd_jogadores);
        if(qtd_jogadores < 2 || qtd_jogadores > 10){
            printf("Quantidade inv�lida. Insira um valor dentro do intervalo de 2 a 10 jogadores.\n\n");
        }
    }while(qtd_jogadores < 2 || qtd_jogadores > 10);
    printf("\n");

    /* PREPARA��O DO JOGO */
    if (!prepararJogo(qtd_jogadores, &baralho, &maosJogadores, &mesa, &colecaoCartasPuxadas)){
        printf ("\nN�o foi poss�vel preparar o jogo corretamente.");
        return 0;
    }
    exibirMesa(mesa, maosJogadores, colecaoCartasPuxadas, cartasTurno);
    // exibirTudo(maosJogadores, qtd_jogadores);

    /* JOGO */
    // Armazena as cartas que foram puxadas (as de pontua��o) por cada jogador
    jogar(qtd_jogadores, baralho, maosJogadores, mesa, colecaoCartasPuxadas);

    return 0;
}
