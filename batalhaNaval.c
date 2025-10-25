//Criei desafio batalha naval aventureiro
#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0};
    int tamanhoNavio = 3;
    int navio[3] = {3, 3, 3};

    int linhaInicialH = 2, colunaInicialH = 1;
    int linhaInicialV = 5, colunaInicialV = 7;
    int linhaInicialD1 = 0, colunaInicialD1 = 0;
    int linhaInicialD2 = 0, colunaInicialD2 = 9;

    for (int i = 0; i < tamanhoNavio; i++) {
        if (colunaInicialH + i < 10 && tabuleiro[linhaInicialH][colunaInicialH + i] == 0) {
            tabuleiro[linhaInicialH][colunaInicialH + i] = navio[i];
        }
    }

    for (int i = 0; i < tamanhoNavio; i++) {
        if (linhaInicialV + i < 10 && tabuleiro[linhaInicialV + i][colunaInicialV] == 0) {
            tabuleiro[linhaInicialV + i][colunaInicialV] = navio[i];
        }
    }

    for (int i = 0; i < tamanhoNavio; i++) {
        if (linhaInicialD1 + i < 10 && colunaInicialD1 + i < 10 &&
            tabuleiro[linhaInicialD1 + i][colunaInicialD1 + i] == 0) {
            tabuleiro[linhaInicialD1 + i][colunaInicialD1 + i] = navio[i];
        }
    }

    for (int i = 0; i < tamanhoNavio; i++) {
        if (linhaInicialD2 + i < 10 && colunaInicialD2 - i >= 0 &&
            tabuleiro[linhaInicialD2 + i][colunaInicialD2 - i] == 0) {
            tabuleiro[linhaInicialD2 + i][colunaInicialD2 - i] = navio[i];
        }
    }

    printf("BATALHA NAVAL AVENTUREIRO\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
