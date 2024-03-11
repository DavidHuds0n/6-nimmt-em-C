#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "carta.h"
#include "jogo.h"

#define QTD_CARTAS 104  // Quantidade de cartas do baralho
#define MAO_INIT 10     // Quantidade inicial de cartas na m�o de um jogador
#define QTD_FILAS 4     // Quantidade de filas na mesa
#define MAX_ROUNDS 10   // Quantidade m�xima de partidas do jogo
#define TICK 1          // Quantidade de segundos para o sleep

/* FUN��ES PARA A PREPARA��O DO JOGO */

Carta criarCarta(int numero) {
    Carta novaCarta;
    novaCarta.numero = numero; // Define o n�mero da carta
    novaCarta.jogador = -1; // Define o jogador dono da carta

    // Define a quantidade de cabe�as de boi com base no n�mero da carta
    novaCarta.bois = 1; // Toda carta tem pelo menos 1 boi
    if (numero % 10 == 5) novaCarta.bois += 1; // Terminadas em 5 tem 2 bois
    if (numero % 10 == 0 && numero != 0) novaCarta.bois += 2; // M�ltiplos de 10 tem 3 bois
    if (numero >= 11 && numero <= 99 && numero % 11 == 0) novaCarta.bois += 4; // D�gitos repetidos (exceto 0) tem 5 bois
    if (numero == 55) novaCarta.bois += 1; // N�mero 55 � um caso especial (termina em 5 e tem digitos repetidos), logo tem 7 bois

    return novaCarta;
}

void inicializarBaralho(Pilha* baralho){
    for(int i = 1; i <= QTD_CARTAS ; i++){
        Carta novaCarta = criarCarta(i);
        inserirPilha(baralho, novaCarta);
    }
    embaralharPilha(baralho);
}

Lista** criarListaJogadores(int qtd_jogadores){
    // Aloca mem�ria para a lista de jogadores
    Lista** listaJogadores = (Lista**)malloc(sizeof(Lista*) * qtd_jogadores);
    if(listaJogadores == NULL) return NULL;

    // Inicializa a lista de cada jogador
    for(int i = 0 ; i < qtd_jogadores ; i++){
        listaJogadores[i] = criarLista();
        if(listaJogadores[i] == NULL) return NULL;
    }

    return listaJogadores;
}

int distribuirCartasJogadores(Lista** maosJogadores, Pilha* baralho, int qtd_jogadores){
    for(int i = 0 ; i < qtd_jogadores ; i++){
        for(int j = 0 ; j < MAO_INIT ; j++){
            Carta cartaRemovida;
            if (!removerPilha(baralho, &cartaRemovida)) return 0;

            cartaRemovida.jogador = i;

            if (!inserirOrdenado(maosJogadores[i], cartaRemovida)) return 0;
        }
    }
    return 1;
}

Fila** criarMesa(){
    Fila** mesa = (Fila**)malloc(sizeof(Fila*) * QTD_FILAS);
    if (mesa == NULL) return NULL;

    // Inicializa cada fila da mesa
    for(int i = 0 ; i < QTD_FILAS ; i++){
        mesa[i] = criarFila();
        if (mesa[i] == NULL) return NULL;
    }
    return mesa;
}

int inserirCartasMesa(Fila** mesa, Pilha* baralho){
    for(int i = 0 ; i < QTD_FILAS ; i++){
        Carta cartaRemovida;
        if(!removerPilha(baralho, &cartaRemovida)) return 0;
        if(!inserirFila(mesa[i], cartaRemovida)) return 0;
    }
    return 1;
}

int prepararJogo (int qtd_jogadores, Pilha **baralho, Lista ***maosJogadores, Fila ***mesa, Lista ***colecaoCartasPuxadas){
    // Cria e inicializa o baralho
    *baralho = criarPilha();
    if (*baralho == NULL){
        printf ("Erro ao alocar mem�ria para o baralho.\n");
        return 0;
    }
    inicializarBaralho(*baralho);

    // Cria lista de m�os dos jogadores e distribui cartas
    *maosJogadores = criarListaJogadores(qtd_jogadores);
    if(*maosJogadores == NULL){
        printf("Erro ao alocar mem�ria para lista de jogadores.\n");
        return 0;
    }
    if(!distribuirCartasJogadores(*maosJogadores, *baralho, qtd_jogadores)){
        printf("Erro ao distribuir as cartas do baralho para os jogadores.\n");
        return 0;
    }

    // Cria e inicializa a mesa com cada fila contendo uma carta
    *mesa = criarMesa();
    if (*mesa == NULL){
        printf("Erro ao alocar mem�ria para mesa.\n");
        return 0;
    }
    if(!inserirCartasMesa(*mesa, *baralho)){
        printf("Erro ao inserir a primeira carta de cada fila da mesa.\n");
        return 0;
    }

    // Cria lista para armazenar as cartas puxadas dos jogadores
    *colecaoCartasPuxadas = criarListaJogadores(qtd_jogadores);
    if(*colecaoCartasPuxadas == NULL){
        printf("Erro ao alocar mem�ria para cole��o de cartas puxadas.\n");
        return 0;
    }

    return 1;
}

/* FUN��ES PARA RODAR O JOGO */

int puxarCartasFila(Fila** mesa, Lista** colecaoCartasPuxadas, int indiceJogador, int indiceFilaMesa, int qtd_jogadores){
    // Verifica se o �ndice do jogador est� dentro do intervalo v�lido
    if (indiceJogador < 0 || indiceJogador >= qtd_jogadores) {
        printf("�ndice de jogador inv�lido.\n");
        return 0;
    }

    // Verifica se o �ndice da fila est� dentro do intervalo v�lido
    if (indiceFilaMesa < 0 || indiceFilaMesa >= QTD_FILAS) {
        printf("�ndice de fila inv�lido.\n");
        return 0;
    }

    int qtd_Fila = tamanhoFila(mesa[indiceFilaMesa]);
    for(int i = 0 ; i < qtd_Fila ; i++){
        Carta cartaRemovida;
        if (!removerFila(mesa[indiceFilaMesa], &cartaRemovida)) {
        printf("Erro ao remover carta da fila.\n");
        return 0;
        }
        if (!inserirOrdenado(colecaoCartasPuxadas[indiceJogador], cartaRemovida)) {
            printf("Erro ao inserir carta na cole��o do jogador.\n");
            return 0;
        }
    }

    return 1;
}

void exibirMesa(Fila** mesa, Lista **maosJogadores, Lista **colecaoCartasPuxadas, Lista* cartasTurno){
    // Exibe as cartas jogadas no turno
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    printf ("[CARTAS JOGADAS NESSE TURNO]\n");
    if(!exibirFila(cartasTurno)){
        printf("(Nenhuma carta foi jogada ainda)\n");
    }
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");

    // Exibe as filas que est�o na mesa
    for(int i = 0 ; i < 4 ; i++){
        printf("[FILA %d]\n", i+1);
        if(tamanhoFila(mesa[i]) != 0) exibirFila(mesa[i]);
        else printf("(Jogador pegou as cartas da fila)\n");

        printf("\n");
    }
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");

    // Exibe a m�o do jogador
    printf("[SUA M�O]\n");
    if(!exibirLista(maosJogadores[0])){
        printf("(Voc� jogou todas as suas cartas)\n");
    }
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");

    // Exibe a cole��o do jogador
    printf("[SUA COLE��O]\n");
    if(!exibirLista(colecaoCartasPuxadas[0])){
        printf("(Voc� n�o pegou nenhuma carta)\n");
    }
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
}

void jogarTurno(int qtd_jogadores, Lista **maosJogadores, Lista *cartasTurno){
    int escolha;
    Carta guardar;

    // Usu�rio escolhe a carta que vai jogar
    do {
        printf ("\Digite o indice da carta que voc� quer jogar: ");
            scanf ("%d", &escolha);
            escolha--;
        if (escolha < 0 || escolha > tamanhoLista(maosJogadores[0])-1) {
            printf ("Escolha um n�mero v�lido.\n");
        }
    } while (escolha < 0 || escolha > tamanhoLista(maosJogadores[0])-1);

    // Adiciona a carta escolhida pelo jogador no vetor de cartas jogadas no turno
    acessarIndice(maosJogadores[0], escolha, &guardar);
    removerIndice(maosJogadores[0], escolha);
    inserirOrdenado(cartasTurno, guardar);

    // Os bots escolher�o uma carta aleat�ria
    for (int i = 1; i < qtd_jogadores; i++){
        escolha = rand()%(tamanhoLista(maosJogadores[i]));

        // Adiciona a carta escolhida pelo bot no vetor de cartas jogadas no turno
        acessarIndice(maosJogadores[i], escolha, &guardar);
        removerIndice(maosJogadores[i], escolha);
        inserirOrdenado(cartasTurno, guardar);
    }
}

int inserirMesa(int qtd_jogadores, Fila **mesa, Lista **colecaoCartasPuxadas, Lista *cartasTurno, Lista **maosJogadores){
    Carta guardarUltima;
    Carta guardarCarta;

    for (int i = 0; i < qtd_jogadores; i++){ // Quantidade de cartas que foram jogadas naquele turno depende dos jogadores

        int dif = 104; // A maior diferen�a poss�vel � 103
        int index = -1; // -1 representa que ainda n�o h� uma fileira para a carta ser inserida

        for (int j = 0; j < QTD_FILAS; j++){ // Analisa o �ltimo elemento de cada fila para saber onde vai adicionar
            guardarUltima = mesa[j]->fim->dados;
            acessarIndice(cartasTurno, i, &guardarCarta);
            int newDif = (guardarCarta.numero) - (guardarUltima.numero);
            if (newDif < dif && newDif > 0){
                dif = newDif;
                index = j;
            }
        }

        // Caso a carta jogada pelo player n�o possa ser inserida
        if (index == -1){
            int escolha;
            if (guardarCarta.jogador == 0){
                do {
                    printf ("\nA carta que voc� escolheu n�o pode ser inserida. Escolha uma fila de cartas para puxar: ");
                    scanf ("%d", &escolha);
                } while (escolha < 1 || escolha > 4);
                escolha--;
                if (!puxarCartasFila(mesa, colecaoCartasPuxadas, guardarCarta.jogador, escolha, qtd_jogadores)){
                    printf ("N�o foi poss�vel inserir a carta.");
                    return 0;
                }
            }
            else {
                escolha = rand()%4;
                if (!puxarCartasFila(mesa, colecaoCartasPuxadas, guardarCarta.jogador, escolha, qtd_jogadores)){
                    printf ("N�o foi poss�vel escolher essa fileira.");
                    return 0;
                }
            }
            sleep(TICK);
            system("cls");
            exibirMesa(mesa, maosJogadores, colecaoCartasPuxadas, cartasTurno);
            sleep(TICK);
            if (!inserirFila(mesa[escolha], guardarCarta)){
                printf ("N�o foi poss�vel inserir a carta.");
                return 0;
            }
        }

        // Caso o jogador seja obrigado a inserir uma carta numa fila de tamanho 5
        else if (tamanhoFila(mesa[index]) == 5){
            if (!puxarCartasFila(mesa, colecaoCartasPuxadas, guardarCarta.jogador, index, qtd_jogadores)){
                printf ("Erro ao pegar a cole��o de cartas.");
            }
            sleep(TICK);
            system("cls");
            exibirMesa(mesa, maosJogadores, colecaoCartasPuxadas, cartasTurno);
            sleep(TICK);
            if (!inserirFila(mesa[index], guardarCarta)){
                printf ("N�o foi poss�vel inserir a carta.");
                return 0;
            }
        }

        // Caso a carta possa ser inserida na fila normalmente
        else {
            inserirFila(mesa[index], guardarCarta);
        }
        sleep(TICK);
        system("cls");
        exibirMesa(mesa, maosJogadores, colecaoCartasPuxadas, cartasTurno);
        sleep(TICK);
    }
    return 1;
}

int jogar(int qtd_jogadores, Pilha *baralho, Lista **maosJogadores, Fila **mesa, Lista **colecaoCartasPuxadas){

    for (int i = 0; i < MAX_ROUNDS; i++){ // N�mero de rodadas at� acabar a m�o de todos os jogadores
        // Cria a fila que vai conter as cartas que ser�o jogadas nesse turno:
        Lista *cartasTurno = criarLista();
            if (cartasTurno == NULL){
                printf ("Erro ao alocar mem�ria para as cartas jogadas em cada turno.\n");
                return 0;
            }

        // Joga o turno de todos os jogadores da partida
        jogarTurno(qtd_jogadores, maosJogadores, cartasTurno);

        if (!inserirMesa(qtd_jogadores, mesa, colecaoCartasPuxadas, cartasTurno, maosJogadores)) return 0;

        printf ("\n");
        exibirMesa(mesa, maosJogadores, colecaoCartasPuxadas, cartasTurno);
        // exibirTudo (maosJogadores, qtd_jogadores);

        // Libera as cartas do turno para que novas sejam criadas e utilizada
        free(cartasTurno);

    }

    fimJogo(qtd_jogadores, colecaoCartasPuxadas);
}

int contarPontos (Lista *cartasPuxadas){
    Elemento *aux = *cartasPuxadas;
    int pontos = 0;
    while (aux != NULL){
        pontos = pontos + aux->dados.bois;
        aux = aux->prox;
    }
    return pontos;
}

void fimJogo (int qtd_jogadores, Lista **colecaoCartasPuxadas){
    system("cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    for (int i = 0; i < qtd_jogadores; i++){
        printf ("[COLE��O DO JOGADOR %d]\n", (i + 1));
        if (!exibirLista(colecaoCartasPuxadas[i])){
            printf ("(N�o pegou nenhuma carta)\n");
        }
        printf ("\nSua pontua��o final � %d.\n", contarPontos(colecaoCartasPuxadas[i]));
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    }
}

/* FUN��ES PARA DEPURA��O */

void exibirTudo(Lista **maosJogadores, int qtd_jogadores) {
    for(int i = 0 ; i < qtd_jogadores ; i++){
        printf("[M�O DO JOGADOR %d]\n", i+1);
        exibirLista(maosJogadores[i]);
        printf("\n\n");
    }
}
