#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

void imprimirMarco() {
    printf("----------------------------\n");
    printf("|          MENÚ            |\n");
    printf("----------------------------\n");
    printf("| 1. Suma de matrices      |\n");
    printf("| 2. Resta de matrices     |\n");
    printf("| 3. Multiplicación        |\n");
    printf("| 4. Determinante          |\n");
    printf("| 5. Salir                 |\n");
    printf("----------------------------\n");
}

void llenarMatriz(int matriz[FILAS][COLUMNAS]) {
    printf("Introduce los valores de la matriz:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int matriz[FILAS][COLUMNAS]) {
    printf("Matriz:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void sumar(int a[FILAS][COLUMNAS], int b[FILAS][COLUMNAS], int r[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLUMNAS; j++)
            r[i][j] = a[i][j] + b[i][j];
}

void restar(int a[FILAS][COLUMNAS], int b[FILAS][COLUMNAS], int r[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLUMNAS; j++)
            r[i][j] = a[i][j] - b[i][j];
}

void multiplicarMatrices(int a[FILAS][COLUMNAS], int b[FILAS][COLUMNAS], int r[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            r[i][j] = 0;
            for (int k = 0; k < COLUMNAS; k++) {
                r[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int calcularDeterminante(int m[FILAS][COLUMNAS]) {
    int positivo = 0, negativo = 0;
    
    for (int i = 0; i < FILAS; i++) {
        int producto = 1;
        for (int j = 0; j < COLUMNAS; j++) {
            producto *= m[j][(i + j) % COLUMNAS];
        }
        positivo += producto;
    }

    for (int i = 0; i < FILAS; i++) {
        int producto = 1;
        for (int j = 0; j < COLUMNAS; j++) {
            producto *= m[j][(i - j + COLUMNAS) % COLUMNAS];
        }
        negativo += producto;
    }

    return positivo - negativo;
}

int main() {
    int A[FILAS][COLUMNAS], B[FILAS][COLUMNAS], R[FILAS][COLUMNAS];
    int opcion;

    do {
        imprimirMarco();
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Llenando matriz A:\n");
                llenarMatriz(A);
                printf("Llenando matriz B:\n");
                llenarMatriz(B);
                sumar(A, B, R);
                imprimirMatriz(R);
                break;
            case 2:
                printf("Llenando matriz A:\n");
                llenarMatriz(A);
                printf("Llenando matriz B:\n");
                llenarMatriz(B);
                restar(A, B, R);
                imprimirMatriz(R);
                break;
            case 3:
                printf("Llenando matriz A:\n");
                llenarMatriz(A);
                printf("Llenando matriz B:\n");
                llenarMatriz(B);
                multiplicarMatrices(A, B, R);
                imprimirMatriz(R);
                break;
            case 4:
                printf("Llenando matriz A:\n");
                llenarMatriz(A);
                printf("Determinante: %d\n", calcularDeterminante(A));
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intenta de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}
