#include <stdio.h>

void llenarMatriz(int matriz[3][3]) {
    printf("Ingresa los numeros:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int matriz[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void transponerMatriz(int matriz[3][3], int transpuesta[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }
}

int main() {
    int matriz[3][3], transpuesta[3][3];

    llenarMatriz(matriz);
    transponerMatriz(matriz, transpuesta);
    
    printf("\nMatriz ingresada:\n");
    imprimirMatriz(matriz);
    
    printf("\nMatriz transpuesta:\n");
    imprimirMatriz(transpuesta);

    return 0;
}
