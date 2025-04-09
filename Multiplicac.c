#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

int main() {
    int matriz[FILAS][COLUMNAS];
    int vector[COLUMNAS];
    int resultado[FILAS];

    printf("Introduce los elementos de una matriz de %dx%d:\n", FILAS, COLUMNAS);
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nIntroduce los elementos de un vector de tamaño %d:\n", COLUMNAS);
    for (int i = 0; i < COLUMNAS; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &vector[i]);
    }

    for (int i = 0; i < FILAS; i++) {
        resultado[i] = 0;
    }

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }

    printf("\nEl resultado de la multiplicación es:\n");
    for (int i = 0; i < FILAS; i++) {
        printf("%d\n", resultado[i]);
    }

    return 0;
}i
