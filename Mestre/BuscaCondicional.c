#include <stdio.h>

int main() {
int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int target = 5;
int found = 0;

for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        if (matriz[i][j] == target) {
            printf("Elemento %d encontrado na posição (%d, %d)\n",target, i, j);
            found = 1;
            break;
        }
    }
    if (found) break;
}

if (!found) {
    printf("Elemento %d não encontrado\n", target);
}

return 0;
}