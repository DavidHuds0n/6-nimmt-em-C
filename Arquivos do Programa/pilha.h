#include "jogo.h"

typedef struct elementoPilha *Pilha;

Pilha * criarPilha();

int inserirPilha(Pilha *, struct carta);

int removerPilha(Pilha *, struct carta *); // J� remove e acessa

void embaralharPilha(Pilha *);

int tamanhoPilha(Pilha *);


//////////////////////////
void exibirPilha(Pilha *);
// Exibir desnecess�rio, ta a� s� pra testes de controle
