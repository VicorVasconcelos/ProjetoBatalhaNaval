#include <stdio.h>

#define TAMANHO 10
#define AGUA 0
#define NAVIO 3
#define TAM_NAVIO 3

void init_tabuleiro(int tab[TAMANHO][TAMANHO]) {
    int i, j;
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tab[i][j] = AGUA;
        }
    }
}

int pode_colocar_horizontal(int tab[TAMANHO][TAMANHO], int linha, int coluna, int tamanho) {
    int i;
    if (linha < 0 || linha >= TAMANHO) return 0;
    if (coluna < 0 || (coluna + tamanho) > TAMANHO) return 0;
    for (i = 0; i < tamanho; i++) {
        if (tab[linha][coluna + i] != AGUA) return 0;
    }
    return 1;
}

int pode_colocar_vertical(int tab[TAMANHO][TAMANHO], int linha, int coluna, int tamanho) {
    int i;
    if (coluna < 0 || coluna >= TAMANHO) return 0;
    if (linha < 0 || (linha + tamanho) > TAMANHO) return 0;
    for (i = 0; i < tamanho; i++) {
        if (tab[linha + i][coluna] != AGUA) return 0;
    }
    return 1;
}

void posiciona_horizontal(int tab[TAMANHO][TAMANHO], int linha, int coluna, int navio[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        tab[linha][coluna + i] = navio[i];
    }
}

void posiciona_vertical(int tab[TAMANHO][TAMANHO], int linha, int coluna, int navio[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        tab[linha + i][coluna] = navio[i];
    }
}

void imprime_tabuleiro(int tab[TAMANHO][TAMANHO]) {
    int i, j;
    printf("Batalha Naval — Nível Novato\n");
    printf("----------------------------------------------\n");

    printf("   ");
    for (j = 0; j < TAMANHO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (i = 0; i < TAMANHO; i++) {
        printf("%d  ", i);
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int tabuleiro[TAMANHO][TAMANHO];

    int navio_horizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navio_vertical[TAM_NAVIO]   = {NAVIO, NAVIO, NAVIO};

    int h_linha = 2, h_coluna = 4;
    int v_linha = 5, v_coluna = 1;

    init_tabuleiro(tabuleiro);

    if (!pode_colocar_horizontal(tabuleiro, h_linha, h_coluna, TAM_NAVIO)) {
        printf("Erro: navio horizontal fora do limite ou sobrepondo outro navio.\n");
        return 1;
    }
    posiciona_horizontal(tabuleiro, h_linha, h_coluna, navio_horizontal, TAM_NAVIO);

    if (!pode_colocar_vertical(tabuleiro, v_linha, v_coluna, TAM_NAVIO)) {
        printf("Erro: navio vertical fora do limite ou sobrepondo outro navio.\n");
        return 1;
    }
    posiciona_vertical(tabuleiro, v_linha, v_coluna, navio_vertical, TAM_NAVIO);

    imprime_tabuleiro(tabuleiro);

    return 0;
}