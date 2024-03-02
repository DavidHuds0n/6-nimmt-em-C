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

    /* PREPARA��O DO JOGO */

    // Cria e inicializa o baralho
    Pilha* baralho = criarPilha();
    inicializarBaralho(baralho);

    // Define a quantidade de jogadores
    int qtd_jogadores;
    do{
        printf("Defina quantos jogadores v�o participar desse jogo: ");
        scanf("%d", &qtd_jogadores);
        if(qtd_jogadores < 2 || qtd_jogadores > 10){
            printf("Quantidade inv�lida. Insira um valor dentro do interv�lo de 2 a 10 jogadores.\n\n");
        }
    }while(qtd_jogadores < 2 || qtd_jogadores > 10);
    printf("\n");

    // Cria lista de m�os dos jogadores e distribui cartas
    Lista** maosJogadores = criarListaJogadores(qtd_jogadores);
    if(maosJogadores == NULL){
        printf("Erro ao alocar mem�ria para lista de jogadores.\n");
        return 0;
    }
    if(!distribuirCartasJogadores(maosJogadores, baralho, qtd_jogadores)){
        printf("Erro ao distribuir as cartas do baralho para os jogadores.\n");
        return 0;
    }

    // Caso voc� queira visualizar as m�os dos jogadores:
    /*
    for(int i = 0 ; i < qtd_jogadores ; i++){
        printf("M�o do jogador %d:\n", i+1);
        exibirLista(maosJogadores[i]);
        printf("\n\n");
    }
    */

    // Cria e inicializa a mesa com as primeiras cartas das filas
    Fila** mesa = criarMesa();
    if (mesa == NULL){
        printf("Erro ao alocar mem�ria para mesa.\n");
        return 0;
    }
    if(!inserirCartasMesa(mesa, baralho)){
        printf("Erro ao inserir a primeira carta de cada fila da mesa.\n");
        return 0;
    }

    // Caso voc� queira visualizar as filas da mesa:
    /*
    for(int i = 0 ; i < 4 ; i++){
        printf("Fila %d:\n", i+1);
        exibirFila(mesa[i]);
        printf("\n\n");
    }
    */

    // Cria lista para armazenar as cartas puxadas dos jogadores
    Lista** colecaoCartasPuxadas = criarListaJogadores(qtd_jogadores);
    if(colecaoCartasPuxadas == NULL){
        printf("Erro ao alocar mem�ria para cole��o de cartas puxadas.\n");
        return 0;
    }

    printf("Se chegou at� aqui, t� rodando \\o/");

    /* JOGO */

    // Lista* cartasJogadas = criarLista();  // Poss�vel lista para armazenar as cartas jogadas durante uma rodada pelos jogadores

    return 0;
}
