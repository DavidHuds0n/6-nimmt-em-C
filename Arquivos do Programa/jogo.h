#ifndef JOGO_H
#define JOGO_H

// Defini��o da estrutura Carta
typedef struct carta {
    int numero; // Varia de 1 a 104
    int bois;   // Varia de 1 a 7
    int jogador; // Indica o dono dessa carta
} Carta;

// Fun��o para criar uma nova carta
Carta criarCarta(int, int);

#endif /* JOGO_H */

