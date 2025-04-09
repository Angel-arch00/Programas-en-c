#include <stdio.h>
#include <stdbool.h>


bool es_raiz_cuadrada_exacta(int val, int *raiz) {
    for (int i = 1; i * i <= val; i++) {
        if (i * i == val) {
            *raiz = i; 
            return true;
        }
    }
    return false;
}

int main() {
    int num, raiz;
    bool flag = false;  

    
    do {
        printf("Ingrese un número con raíz cuadrada exacta: ");
        scanf("%d", &num);

        flag = es_raiz_cuadrada_exacta(num, &raiz);

        if (!flag) {
            printf("El número ingresado no tiene una raíz cuadrada exacta. Intente nuevamente.\n");
        }

    } while (!flag);
    char matriz[raiz][raiz];
    printf("Ingrese los caracteres en la matriz (%dx%d):\n", raiz, raiz);
    for (int i = 0; i < raiz; i++) {
        for (int j = 0; j < raiz; j++) {
            printf("Posición [%d][%d]: ", i, j);
            scanf(" %c", &matriz[i][j]); 
        }
    }

    printf("\nMatriz generada:\n");
    for (int i = 0; i < raiz; i++) {
        for (int j = 0; j < raiz; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nValores en arreglo lineal:\n");
    for (int i = 0; i < raiz; i++) {
        for (int j = 0; j < raiz; j++) {
            printf("%c ", matriz[i][j]);
        }
    }
    printf("\n");

    return 0;
}

