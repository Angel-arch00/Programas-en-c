#include <stdio.h>

void ingresarMatriz(int matriz[3][3]) {
    printf("Ingresa los numeros para la matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirVector(int vector[3]) {
    for (int i = 0; i < 3; i++) {
        printf("Resultado[%d] = %d\n", i, vector[i]);
    }
}

void multiplicarMatrizVector(int matriz[3][3]) {
    int vector[3], resultado[3] = {0, 0, 0};

    printf("\nIngresa los valores del vector:\n");
    for (int i = 0; i < 3; i++) {
        printf("Vector[%d]: ", i);
        scanf("%d", &vector[i]);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }

    printf("\nResultado de la multiplicacion:\n");
    imprimirVector(resultado);
}

int main() {
    int matriz[3][3];

    ingresarMatriz(matriz);
    multiplicarMatrizVector(matriz);

    return 0;
}
