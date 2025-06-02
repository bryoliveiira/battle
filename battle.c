#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int tamanho_navio = 3;

    int linhaH = 1;
    int colunaH = 2;

    if (colunaH + tamanho_navio <= 10) {
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linhaH][colunaH + i] = 3;
        }
    }

    int linhaV = 5;
    int colunaV = 6;
    int pode_colocar = 1;

    if (linhaV + tamanho_navio <= 10) {
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linhaV + i][colunaV] == 3) {
                pode_colocar = 0; 
            }
        }

        if (pode_colocar == 1) {
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        }
    }

    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
