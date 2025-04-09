#include <stdio.h>

#define FILAS 2
#define COLUMNAS 2

int mcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplificarFraccion(int *numerador, int *denominador) {
    int divisor = mcd(*numerador, *denominador);
    *numerador /= divisor;
    *denominador /= divisor;
}

void ingresarMatriz(int numerador[FILAS][COLUMNAS], int denominador[FILAS][COLUMNAS], const char *nombre) {
    printf("Introduce los elementos de la matriz %s (numerador y denominador):\n", nombre);
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Elemento [%d][%d] - Numerador: ", i, j);
            scanf("%d", &numerador[i][j]);
            printf("Elemento [%d][%d] - Denominador: ", i, j);
            scanf("%d", &denominador[i][j]);
        }
    }
}

void multiplicarMatrices(int num1[FILAS][COLUMNAS], int den1[FILAS][COLUMNAS], int num2[FILAS][COLUMNAS], int den2[FILAS][COLUMNAS], int resNum[FILAS][COLUMNAS], int resDen[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            resNum[i][j] = num1[i][j] * num2[i][j];
            resDen[i][j] = den1[i][j] * den2[i][j];
            simplificarFraccion(&resNum[i][j], &resDen[i][j]);
        }
    }
}

void imprimirMatriz(int numerador[FILAS][COLUMNAS], int denominador[FILAS][COLUMNAS]) {
    printf("\nEl resultado de la multiplicacion (simplificado) es:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Elemento [%d][%d]: %d/%d\n", i, j, numerador[i][j], denominador[i][j]);
        }
    }
}

int main() {
    int matriz1Numerador[FILAS][COLUMNAS], matriz1Denominador[FILAS][COLUMNAS];
    int matriz2Numerador[FILAS][COLUMNAS], matriz2Denominador[FILAS][COLUMNAS];
    int resultadoNumerador[FILAS][COLUMNAS], resultadoDenominador[FILAS][COLUMNAS];

    ingresarMatriz(matriz1Numerador, matriz1Denominador, "1");
    ingresarMatriz(matriz2Numerador, matriz2Denominador, "2");
    multiplicarMatrices(matriz1Numerador, matriz1Denominador, matriz2Numerador, matriz2Denominador, resultadoNumerador, resultadoDenominador);
    imprimirMatriz(resultadoNumerador, resultadoDenominador);

    return 0;
}

