#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

int main() {
    char matriz[FILAS][COLUMNAS][20];
    printf("Ingrese %d palabras:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Palabra [%d][%d]: ", i, j);
            scanf("%19s", matriz[i][j]); 
        }
    }

    printf("\nMatriz de palabras:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("|%-20s", matriz[i][j]);
        }
    printf("\n");
    }

    return 0;
}


