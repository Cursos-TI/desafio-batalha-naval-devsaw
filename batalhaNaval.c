//Criei desafio batalha naval novato
#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    int tabuleiro[10][10] = {0};
    int tamanhoNavio = 3;

    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};

    int linhaInicialNavio1 = 2;
    int colunaInicialNavio1 = 4;

    int linhaInicialNavio2 = 6;
    int colunaInicialNavio2 = 1;

    for (int i = 0; i < tamanhoNavio; i++) {
        if (colunaInicialNavio1 + i < 10) {
            tabuleiro[linhaInicialNavio1][colunaInicialNavio1 + i] = navio1[i];
        }
    }


    for (int i = 0; i < tamanhoNavio; i++) {
        if (linhaInicialNavio2 + i < 10) {
            if (tabuleiro[linhaInicialNavio2 + i][colunaInicialNavio2] == 0) {
                tabuleiro[linhaInicialNavio2 + i][colunaInicialNavio2] = navio2[i];
            }
        }
    }

    printf("BATALHA NAVAL\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
