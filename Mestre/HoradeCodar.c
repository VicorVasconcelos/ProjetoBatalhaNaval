#include <stdio.h>

#define LINHA 5
#define COLUNA 5

int main() {
int matriz[LINHA][COLUNA];
int target = 9;
int found = 0;
int soma = 1;

for (int i = 0; i < LINHA; i++) {
    for (int j = 0; j < COLUNA; j++) {
        matriz[i][j] = soma;
        soma++;
        printf("%d ", matriz[i][j]);
    }
    printf("\n");
}

for (int i = 0; i < LINHA; i++) {
    for (int j = 0; j < COLUNA; j++) {
        if (matriz[i][j] == target) {
            printf("O valor %d encontrado no Indice (%d, %d)\n",target, i, j);
            found = 1;
            break;
        }
    }
    if (found) break;
}

if (!found) {
    printf("O valor %d não foi encontrado\n", target);
}

return 0;
}