#include "jogo.h"

typedef struct elementoFila *Fila;

Fila * criarFila();

int inserirFila(Fila *, struct carta);

int removerFila(Fila *, struct carta *);

int acessarFila(Fila *, struct carta *);

int exibirFila(Fila *);

int tamanhoFila(Fila *);

