#include "jogo.h"

typedef struct elementoLista *Lista; //define uma lista de elementos (cartas) como um tipo
//a lista de cartas serve para: as cartas adquiridas pelo jogador, mão do jogador, cartas jogadas em uma rodada.

Lista * criarLista();

int inserirOrdenado(Lista *, struct carta);

int acessarIndice(Lista *, int, struct carta *);

int removerIndice(Lista *, int);

int exibirLista(Lista *);

int quantidadeLista(Lista *);
