#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED

// Definição da estrutura Carta
typedef struct carta {
    int numero; // Varia de 1 a 104
    int bois;   // Varia de 1 a 7
    int jogador; // Indica o dono dessa carta
} Carta;

// Definição da estrutura Elemento
typedef struct elemento{
    struct carta dados; // Define a carta e seus dados como parte do elemento
    struct elemento *prox; // Define o apontamento para o próximo elemento
} Elemento;

#endif // CARTA_H_INCLUDED
