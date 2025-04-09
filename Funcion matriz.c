#include <stdio.h>
#define TAM 3  
void llenarMatriz(char *nombre, int matriz[TAM][TAM]) {
    printf(" %s:\n", nombre);
    for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
            printf("Mete el num en [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
                 }
    }
}

void imprimirMatriz(char *nombre, int matriz[TAM][TAM]) {
    printf("%s:\n", nombre);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
         printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

   void productoEscalar(int matriz1[TAM][TAM], int matriz2[TAM][TAM], int resultado[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            resultado[i][j] = matriz1[i][j] * matriz2[i][j];
        }
    }
}


int determinanteSarrus(int matriz[TAM][TAM]) {
    int suma = 0, resta = 0;   
        for (int i = 0; i < TAM; i++) {
        int producto = 1;
        for (int j = 0; j < TAM; j++) {
         producto *= matriz[j][(i + j) % TAM];
        }
        suma += producto;
    }
    for (int i = 0; i < TAM; i++) {
        int producto = 1;
       for (int j = 0; j < TAM; j++) {
            producto *= matriz[j][(i - j + TAM) % TAM];
            }
        resta += producto;
    }
    return suma - resta;
}


int main() {
    int matrizA[TAM][TAM], matrizB[TAM][TAM], matrizResultado[TAM][TAM];

    llenarMatriz("Matriz A", matrizA);
    llenarMatriz("Matriz B", matrizB);

    imprimirMatriz("Matriz A", matrizA);
    imprimirMatriz("Matriz B", matrizB);

    productoEscalar(matrizA, matrizB, matrizResultado);
    imprimirMatriz("Producto escalar:", matrizResultado);

    int detA = determinanteSarrus(matrizA);
    int detB = determinanteSarrus(matrizB);

    printf("Determinante de Matriz A : %d\n", detA);
    printf("Determinante de Matriz B : %d\n", detB);

    return 0;
}