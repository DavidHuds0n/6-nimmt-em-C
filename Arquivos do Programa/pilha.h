#include "jogo.h"

typedef struct elementoPilha *Pilha;

Pilha * criarPilha();

int inserirPilha(Pilha *, struct carta);

int removerPilha(Pilha *, struct carta *); // Já remove e acessa

void embaralharPilha(Pilha *);

int tamanhoPilha(Pilha *);


//////////////////////////
void exibirPilha(Pilha *);
// Exibir desnecessário, ta aí só pra testes de controle
