#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

// Fun��o para criar uma nova carta
Carta criarCarta(int numero, int jogador) {
    Carta novaCarta; // Cria uma nova carta
    novaCarta.numero = numero; // Define o n�mero da carta
    novaCarta.jogador = jogador; // Define o jogador dono da carta

    // Cada carta tem pelo menos uma cabe�a de boi
    novaCarta.bois = 1;

    // Condi��es especiais para atribuir cabe�as de boi
    // N�meros terminados em 5 t�m duas cabe�as de boi
    if (numero % 10 == 5) {
        novaCarta.bois += 1;
    }

    // M�ltiplos de 10 t�m tr�s cabe�as de boi
    if (numero % 10 == 0 && numero != 0) {
        novaCarta.bois += 2;
    }

    // D�gitos repetidos (exceto 0) t�m cinco cabe�as de boi
    if(numero >= 11 && numero <= 99 && numero % 11 == 0) {
        novaCarta.bois += 4;
    }

    // O n�mero 55 tem uma cabe�a de boi adicional
    if(numero == 55){
        novaCarta.bois += 1;
    }

    // Retorna a nova carta criada
    return novaCarta;
}
