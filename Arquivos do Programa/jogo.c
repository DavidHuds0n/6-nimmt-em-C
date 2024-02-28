#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

// Função para criar uma nova carta
Carta criarCarta(int numero, int jogador) {
    Carta novaCarta; // Cria uma nova carta
    novaCarta.numero = numero; // Define o número da carta
    novaCarta.jogador = jogador; // Define o jogador dono da carta

    // Cada carta tem pelo menos uma cabeça de boi
    novaCarta.bois = 1;

    // Condições especiais para atribuir cabeças de boi
    // Números terminados em 5 têm duas cabeças de boi
    if (numero % 10 == 5) {
        novaCarta.bois += 1;
    }

    // Múltiplos de 10 têm três cabeças de boi
    if (numero % 10 == 0 && numero != 0) {
        novaCarta.bois += 2;
    }

    // Dígitos repetidos (exceto 0) têm cinco cabeças de boi
    if(numero >= 11 && numero <= 99 && numero % 11 == 0) {
        novaCarta.bois += 4;
    }

    // O número 55 tem uma cabeça de boi adicional
    if(numero == 55){
        novaCarta.bois += 1;
    }

    // Retorna a nova carta criada
    return novaCarta;
}
