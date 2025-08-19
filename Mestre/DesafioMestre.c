#include <stdio.h>
#include <stdlib.h> // Para abs()

/*
 * Batalha Naval - Nível Mestre
 * Tabuleiro 10x10 com navios e habilidades especiais.
 *
 * Símbolos:
 * 0 = Água
 * 3 = Navio
 * 4 = Habilidade: Cone
 * 7 = Habilidade: Cruz
 * 8 = Habilidade: Octaedro
 */

#define TAM 10
#define AGUA 0
#define NAVIO 3

#define CONE 4
#define CRUZ 7
#define OCTAEDRO 8

#define HAB_TAM 5 // Tamanho da matriz de habilidade (5x5 para centralizar os padrões 3x5)

/* Imprime o tabuleiro com cabeçalhos e legenda. */
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

/* Inicializa o tabuleiro com água. */
void inicializar_tabuleiro(int tab[TAM][TAM]) {
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tab[i][j] = AGUA;
        }
    }
}

/* Verifica se navio linear cabe e não sobrepõe. */
int verifica_linear(int tab[TAM][TAM], int lin, int col, int horizontal, int tamanho) {
    int k;
    if (horizontal) {
        if (col + tamanho - 1 >= TAM) return 0;
        for (k = 0; k < tamanho; k++) {
            if (tab[lin][col + k] != AGUA) return 0;
        }
    } else {
        if (lin + tamanho - 1 >= TAM) return 0;
        for (k = 0; k < tamanho; k++) {
            if (tab[lin + k][col] != AGUA) return 0;
        }
    }
    return 1;
}

/* Posiciona navio linear. */
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

/* Verifica se navio diagonal cabe e não sobrepõe. */
int verifica_diagonal(int tab[TAM][TAM], int lin, int col, int dir, int tamanho) {
    int k, r, c;
    for (k = 0; k < tamanho; k++) {
        r = lin + k;
        c = (dir == 0) ? (col + k) : (col - k);
        if (r < 0 || r >= TAM || c < 0 || c >= TAM) return 0;
        if (tab[r][c] != AGUA) return 0;
    }
    return 1;
}

/* Posiciona navio diagonal. */
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

/* Gera a matriz para a habilidade Cone (padrão 3x5). */
void gerar_cone(int matriz_cone[HAB_TAM][HAB_TAM]) {
    int i, j;
    for (i = 0; i < HAB_TAM; i++) {
        for (j = 0; j < HAB_TAM; j++) {
            matriz_cone[i][j] = AGUA;
        }
    }
    int cone_pattern[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };
    int row_offset = (HAB_TAM - 3) / 2;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            matriz_cone[i + row_offset][j] = cone_pattern[i][j];
        }
    }
}

/* Gera a matriz para a habilidade Cruz (padrão 3x5). */
void gerar_cruz(int matriz_cruz[HAB_TAM][HAB_TAM]) {
    int i, j;
    for (i = 0; i < HAB_TAM; i++) {
        for (j = 0; j < HAB_TAM; j++) {
            matriz_cruz[i][j] = AGUA;
        }
    }
    int cruz_pattern[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };
    int row_offset = (HAB_TAM - 3) / 2;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            matriz_cruz[i + row_offset][j] = cruz_pattern[i][j];
        }
    }
}

/* Gera a matriz para a habilidade Octaedro (padrão 3x5). */
void gerar_octaedro(int matriz_octa[HAB_TAM][HAB_TAM]) {
    int i, j;
    for (i = 0; i < HAB_TAM; i++) {
        for (j = 0; j < HAB_TAM; j++) {
            matriz_octa[i][j] = AGUA;
        }
    }
    int octa_pattern[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    int row_offset = (HAB_TAM - 3) / 2;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            matriz_octa[i + row_offset][j] = octa_pattern[i][j];
        }
    }
}

/* Aplica uma habilidade no tabuleiro principal. */
void aplicar_habilidade(int tabuleiro[TAM][TAM], int habilidade_matriz[HAB_TAM][HAB_TAM],
                        int centro_lin, int centro_col, int valor_habilidade) {
    int offset = HAB_TAM / 2;
    int i, j;
    int tab_lin, tab_col;

    for (i = 0; i < HAB_TAM; i++) {
        for (j = 0; j < HAB_TAM; j++) {
            tab_lin = centro_lin - offset + i;
            tab_col = centro_col - offset + j;

            if (tab_lin >= 0 && tab_lin < TAM && tab_col >= 0 && tab_col < TAM) {
                if (habilidade_matriz[i][j] == 1) {
                    tabuleiro[tab_lin][tab_col] = valor_habilidade;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int ok;
    int tamanho_navio = 3;

    int cone_matriz[HAB_TAM][HAB_TAM];
    int cruz_matriz[HAB_TAM][HAB_TAM];
    int octaedro_matriz[HAB_TAM][HAB_TAM];

    inicializar_tabuleiro(tabuleiro);

    // Posicionamento dos navios
    ok = posicionar_linear(tabuleiro, 1, 2, 1, tamanho_navio);
    if (!ok) { printf("Falha ao posicionar Navio A.\n"); return 1; }
    ok = posicionar_linear(tabuleiro, 5, 7, 0, tamanho_navio);
    if (!ok) { printf("Falha ao posicionar Navio B.\n"); return 1; }
    ok = posicionar_diagonal(tabuleiro, 3, 3, 0, tamanho_navio);
    if (!ok) { printf("Falha ao posicionar Navio C.\n"); return 1; }
    ok = posicionar_diagonal(tabuleiro, 7, 5, 1, tamanho_navio);
    if (!ok) { printf("Falha ao posicionar Navio D.\n"); return 1; }

    // Geração e aplicação das habilidades
    gerar_cone(cone_matriz);
    aplicar_habilidade(tabuleiro, cone_matriz, 2, 2, CONE);

    gerar_cruz(cruz_matriz);
    aplicar_habilidade(tabuleiro, cruz_matriz, 6, 4, CRUZ);

    gerar_octaedro(octaedro_matriz);
    aplicar_habilidade(tabuleiro, octaedro_matriz, 8, 8, OCTAEDRO);

    // Impressão final do tabuleiro
    printf("=== Batalha Naval - Nivel Mestre ===\n");
    printf("Legenda:\n  0 = agua\n  3 = navio\n  4 = area de efeito (Cone)\n  7 = area de efeito (Cruz)\n  8 = area de efeito (Octaedro)\n\n");
    imprimir_tabuleiro(tabuleiro);

    return 0;
}
