#include <stdio.h>

#define MAX 10 

void multiplicarMatrices(int n, int A[MAX][MAX], int B[MAX][MAX], int resultado[MAX][MAX]) {
    int temp[MAX][MAX] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                temp[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = temp[i][j];
        }
    }
}

void ingresarMatriz(int n, int matriz[MAX][MAX]) {
    printf("\nIntroduce los elementos de la matriz (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void inicializarIdentidad(int n, int matriz[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = (i == j) ? 1 : 0;
        }
    }
}

void elevarMatriz(int n, int matriz[MAX][MAX], int exponente, int resultado[MAX][MAX]) {
    if (exponente == 0) {
        inicializarIdentidad(n, resultado);
        return;
    }
    int temp[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = matriz[i][j];
        }
    }
    for (int p = 1; p < exponente; p++) {
        multiplicarMatrices(n, resultado, matriz, temp);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                resultado[i][j] = temp[i][j];
            }
        }
    }
}

void imprimirMatriz(int n, int matriz[MAX][MAX]) {
    printf("\nLa matriz resultante es:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, exponente;
    int matriz[MAX][MAX], resultado[MAX][MAX];

    printf("Introduce el tamaño de la matriz cuadrada (n x n, donde n <= %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) {
        printf("El tamaño máximo permitido es %d.\n", MAX);
        return 1;
    }
    
    ingresarMatriz(n, matriz);
    printf("\nIntroduce el exponente al que quieres elevar la matriz: ");
    scanf("%d", &exponente);
    
    elevarMatriz(n, matriz, exponente, resultado);
    imprimirMatriz(n, resultado);
    
    return 0;
}
