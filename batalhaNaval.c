//Criei desafio batalha naval mestre
#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0};   // 0 = água, 3 = navio, 5 = área de habilidade
    int tamanhoNavio = 3;
    int navio[3] = {3,3,3};

    int linhaH = 2, colunaH = 1;
    int linhaV = 5, colunaV = 7;
    int linhaD1 = 0, colunaD1 = 0;
    int linhaD2 = 0, colunaD2 = 9;

    for (int i = 0; i < tamanhoNavio; i++) {
        if (linhaH >= 0 && linhaH < 10 && colunaH + i < 10 && colunaH + i >= 0)
            tabuleiro[linhaH][colunaH + i] = navio[i];
    }

    for (int i = 0; i < tamanhoNavio; i++) {
        if (linhaV + i < 10 && linhaV + i >= 0 && colunaV >= 0 && colunaV < 10)
            tabuleiro[linhaV + i][colunaV] = navio[i];
    }

    for (int i = 0; i < tamanhoNavio; i++) {
        if (linhaD1 + i < 10 && colunaD1 + i < 10)
            tabuleiro[linhaD1 + i][colunaD1 + i] = navio[i];
    }

    for (int i = 0; i < tamanhoNavio; i++) {
        if (linhaD2 + i < 10 && colunaD2 - i >= 0)
            tabuleiro[linhaD2 + i][colunaD2 - i] = navio[i];
    }

    const int S = 5;
    int cone[S][S];
    int cruz[S][S];
    int octaedro[S][S];
    int centro = S / 2; // 2

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            if (i <= centro && ( (j - centro) <= i ) && ( (centro - j) <= i )) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            if (i == centro || j == centro) cruz[i][j] = 1;
            else cruz[i][j] = 0;
        }
    }

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            int distManhattan = (i > centro ? i - centro : centro - i) + (j > centro ? j - centro : centro - j);
            if (distManhattan <= centro) octaedro[i][j] = 1;
            else octaedro[i][j] = 0;
        }
    }

    int origemConeLinha = 1, origemConeColuna = 4;      // exemplo
    int origemCruzLinha = 6, origemCruzColuna = 2;      // exemplo
    int origemOctLinha = 4, origemOctCol = 7;           // exemplo


    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            if (cone[i][j] == 1) {
                int linha = origemConeLinha + (i - centro);
                int coluna = origemConeColuna + (j - centro);
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    if (tabuleiro[linha][coluna] == 0) tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            if (cruz[i][j] == 1) {
                int linha = origemCruzLinha + (i - centro);
                int coluna = origemCruzColuna + (j - centro);
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    if (tabuleiro[linha][coluna] == 0) tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            if (octaedro[i][j] == 1) {
                int linha = origemOctLinha + (i - centro);
                int coluna = origemOctCol + (j - centro);
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    if (tabuleiro[linha][coluna] == 0) tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    
    printf("BATALHA NAVAL MESTRE\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}