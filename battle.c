#include <stdio.h>


#define TAM 10
#define TAM_HABILIDADE 5

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTABULEIRO:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int tipo) {
    for (int i = 0; i < 3; i++) {
        int l = linha, c = coluna;

        if (tipo == 1) c += i;           
        else if (tipo == 2) l += i;      
        else if (tipo == 3) { l += i; c += i; }     
        else if (tipo == 4) { l += i; c -= i; }     

        if (l >= 0 && l < TAM && c >= 0 && c < TAM && tabuleiro[l][c] == 0) {
            tabuleiro[l][c] = 3;
        }
    }
}

void gerarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

void gerarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

void gerarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int centro_linha, int centro_coluna) {
    int offset = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int l = centro_linha - offset + i;
            int c = centro_coluna - offset + j;

            if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[l][c] == 0) {
                    tabuleiro[l][c] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);

    posicionarNavio(tabuleiro, 1, 1, 1);  
    posicionarNavio(tabuleiro, 5, 7, 2);  
    posicionarNavio(tabuleiro, 0, 0, 3);  
    posicionarNavio(tabuleiro, 2, 9, 4);  

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 6, 3);     
    aplicarHabilidade(tabuleiro, cruz, 3, 6);      
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  

    exibirTabuleiro(tabuleiro);

    return 0;
}
