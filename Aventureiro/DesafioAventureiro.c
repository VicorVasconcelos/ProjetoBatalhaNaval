
#include <stdio.h>

/*
 * Batalha Naval - Nível Aventureiro
 * Tabuleiro 10x10, quatro navios de tamanho 3:
 * - Dois lineares (horizontal/vertical)
 * - Dois diagonais (↘ e ↙)
 * Representação:
 *   0 = água
 *   3 = parte do navio
 *
 * Regras deste nível:
 * - Coordenadas definidas no código (sem input do usuário).
 * - Validação de limites e de sobreposição.
 * - Impressão do tabuleiro completa.
 *
 * Observação: evitamos o uso de 'const' para manter compatibilidade com seu estágio atual de estudos.
 */

#define TAM 10
#define AGUA 0
#define NAVIO 3

/* Imprime o tabuleiro 10x10 com cabeçalhos de linha/coluna para facilitar a visualização */
void imprimir_tabuleiro(int tab[TAM][TAM]) {
    int i, j;
    printf("   ");
    for (j = 0; j < TAM; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    for (i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (j = 0; j < TAM; j++) {
            printf("%2d ", tab[i][j]);
        }
        printf("\n");
    }
}

/* Inicializa todo o tabuleiro com 0 (água) */
void inicializar_tabuleiro(int tab[TAM][TAM]) {
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tab[i][j] = AGUA;
        }
    }
}

/* Verifica se um navio linear (horizontal/vertical) cabe sem sair dos limites e sem sobrepor */
int verifica_linear(int tab[TAM][TAM], int lin, int col, int horizontal, int tamanho) {
    int k;
    if (horizontal) {
        if (col + tamanho - 1 >= TAM) return 0;
        for (k = 0; k < tamanho; k++) {
            if (tab[lin][col + k] != AGUA) return 0;
        }
    } else { /* vertical */
        if (lin + tamanho - 1 >= TAM) return 0;
        for (k = 0; k < tamanho; k++) {
            if (tab[lin + k][col] != AGUA) return 0;
        }
    }
    return 1;
}

/* Posiciona navio linear (horizontal=1, vertical=0). Retorna 1 em sucesso, 0 em falha */
int posicionar_linear(int tab[TAM][TAM], int lin, int col, int horizontal, int tamanho) {
    int k;
    if (!verifica_linear(tab, lin, col, horizontal, tamanho)) return 0;

    if (horizontal) {
        for (k = 0; k < tamanho; k++) tab[lin][col + k] = NAVIO;
    } else {
        for (k = 0; k < tamanho; k++) tab[lin + k][col] = NAVIO;
    }
    return 1;
}

/* Verifica se um navio diagonal cabe (dir=0: ↘; dir=1: ↙) e não sobrepõe */
int verifica_diagonal(int tab[TAM][TAM], int lin, int col, int dir, int tamanho) {
    int k, r, c;
    for (k = 0; k < tamanho; k++) {
        r = lin + k;                 /* sempre anda 1 para baixo por segmento */
        c = (dir == 0) ? (col + k)   : (col - k);
        if (r < 0 || r >= TAM || c < 0 || c >= TAM) return 0;
        if (tab[r][c] != AGUA) return 0;
    }
    return 1;
}

/* Posiciona navio diagonal (dir=0: ↘; dir=1: ↙). Retorna 1 em sucesso, 0 em falha */
int posicionar_diagonal(int tab[TAM][TAM], int lin, int col, int dir, int tamanho) {
    int k, r, c;
    if (!verifica_diagonal(tab, lin, col, dir, tamanho)) return 0;

    for (k = 0; k < tamanho; k++) {
        r = lin + k;
        c = (dir == 0) ? (col + k) : (col - k);
        tab[r][c] = NAVIO;
    }
    return 1;
}

int main() {
    int tabuleiro[TAM][TAM];
    int ok;

    /* Parâmetros gerais */
    int tamanho_navio = 3;

    /* 1) Inicializa o tabuleiro */
    inicializar_tabuleiro(tabuleiro);

    /* 2) Define posições dos 4 navios (sem input do usuário) */
    /* Navio A: horizontal de (1,2) a (1,4) */
    ok = posicionar_linear(tabuleiro, 1, 2, 1, tamanho_navio);
    if (!ok) {
        printf("Falha ao posicionar Navio A (horizontal).\n");
        return 1;
    }

    /* Navio B: vertical de (5,7) a (7,7) */
    ok = posicionar_linear(tabuleiro, 5, 7, 0, tamanho_navio);
    if (!ok) {
        printf("Falha ao posicionar Navio B (vertical).\n");
        return 1;
    }

    /* Navio C: diagonal ↘ começando em (3,3): (3,3)-(4,4)-(5,5) */
    ok = posicionar_diagonal(tabuleiro, 3, 3, 0, tamanho_navio);
    if (!ok) {
        printf("Falha ao posicionar Navio C (diagonal ↘).\n");
        return 1;
    }

    /* Navio D: diagonal ↙ começando em (7,5): (7,5)-(8,4)-(9,3) */
    ok = posicionar_diagonal(tabuleiro, 7, 5, 1, tamanho_navio);
    if (!ok) {
        printf("Falha ao posicionar Navio D (diagonal ↙).\n");
        return 1;
    }

    /* 3) Imprime o tabuleiro final */
    printf("=== Batalha Naval - Nivel Aventureiro ===\n");
    printf("Legenda: 0=agua, 3=navio (tamanho %d)\n\n", tamanho_navio);
    imprimir_tabuleiro(tabuleiro);

    return 0;
}
