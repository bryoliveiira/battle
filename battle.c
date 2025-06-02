#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int tamanho_navio = 3;

    int l1 = 1, c1 = 1;
    if (c1 + tamanho_navio <= 10) {
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[l1][c1 + i] = 3;
        }
    }

    int l2 = 5, c2 = 7;
    int sobreposicao2 = 0;
    if (l2 + tamanho_navio <= 10) {
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[l2 + i][c2] == 3) sobreposicao2 = 1;
        }
        if (!sobreposicao2) {
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[l2 + i][c2] = 3;
            }
        }
    }

    int l3 = 0, c3 = 0;
    int sobreposicao3 = 0;
    if (l3 + tamanho_navio <= 10 && c3 + tamanho_navio <= 10) {
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[l3 + i][c3 + i] == 3) sobreposicao3 = 1;
        }
        if (!sobreposicao3) {
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[l3 + i][c3 + i] = 3;
            }
        }
    }

    int l4 = 2, c4 = 9;
    int sobreposicao4 = 0;
    if (l4 + tamanho_navio <= 10 && c4 - (tamanho_navio - 1) >= 0) {
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[l4 + i][c4 - i] == 3) sobreposicao4 = 1;
        }
        if (!sobreposicao4) {
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[l4 + i][c4 - i] = 3;
            }
        }
    }

    printf("\nTabuleiro 10x10 com 4 navios (horizontal, vertical e diagonais):\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
