#include <stdio.h>

#define N 4 

void pedirMatrices(int a[N][N], int b[N][N]) {
    printf("Ingresa matriz A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("A*[%d]*[%d]*: ", i, j);
            setColor("\033[7;32m");
            printf("\n----------");
            setColor("\033[7;32m");
            scanf("*%d", &a[i][j]);
            
        }
    }

    printf("\nIngresa matriz B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
}

void multiplicarMatrices(int a[N][N], int b[N][N], int res[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = 0;
            for (int k = 0; k < N; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int matriz1[N][N];
    int matriz2[N][N];
    int resultado[N][N];

    pedirMatrices(matriz1, matriz2);
    multiplicarMatrices(matriz1, matriz2, resultado);

    printf("\nMatriz resultado (A x B):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("\n","%d", resultado[i][j]);
            
        }
        printf("\n");
    }

    return 0;
}