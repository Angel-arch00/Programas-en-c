#include <stdio.h>

void pedirMatriz(int m[3][3], char nombre) {
    printf("Dame los nums de la matris %c:\n", nombre);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c[%d][%d]: ", nombre, i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void imprimirMatrizHorizontal(int a[3][3], char op, int b[3][3], int r[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("* %2d  %2d  %2d *   %c   * %2d  %2d  %2d *   =   * %2d  %2d  %2d *\n", 
            a[i][0], a[i][1], a[i][2], op, b[i][0], b[i][1], b[i][2], r[i][0], r[i][1], r[i][2]);
        printf("|           |       |            |       |            |\n");
    }
}

void imprimirMatrizEscalar(int a[3][3], int esc, int r[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("* %2d  %2d  %2d *   x   %d   =   * %2d  %2d  %2d *\n", 
            a[i][0], a[i][1], a[i][2], esc, r[i][0], r[i][1], r[i][2]);
        printf("*            *       *            *\n");
    }
}

void imprimirDeterminante(int m[3][3], int det) {
    for (int i = 0; i < 3; i++) {
        printf("* %2d  %2d  %2d *\n", m[i][0], m[i][1], m[i][2]);
        printf("*            *\n");
    }
    printf("Determinante: %d\n", det);
}

void sumar(int a[3][3], int b[3][3], int r[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            r[i][j] = a[i][j] + b[i][j];
}

void restar(int a[3][3], int b[3][3], int r[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            r[i][j] = a[i][j] - b[i][j];
}

void escalar(int a[3][3], int r[3][3], int esc) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            r[i][j] = a[i][j] * esc;
}

int sarrus(int m[3][3]) {
    int positivo = 0, negativo = 0;

    for (int i = 0; i < 3; i++) {
        int producto = 1;
        for (int j = 0; j < 3; j++) {
            producto *= m[j][(i + j) % 3];
        }
        positivo += producto;
    }

    for (int i = 0; i < 3; i++) {
        int producto = 1;
        for (int j = 0; j < 3; j++) {
            producto *= m[j][(i - j + 3) % 3];
        }
        negativo += producto;
    }

    return positivo - negativo;
}

int main() {
    int A[3][3], B[3][3], R[3][3];
    int opcion, esc;

    pedirMatriz(A, 'A');
    pedirMatriz(B, 'B');
    printf("-----------------------\n");
    printf("|        MENÚ         |\n");
    printf("-----------------------\n");
    printf("| 1.Suma matriz       |\n");
    printf("-----------------------\n");
    printf("| 2.Resta matriz      |\n");
    printf("-----------------------\n");
    printf("| 3.MultiplicarMatrices|\n");
    printf("-----------------------\n");
    printf("| 4.Determinante      |\n");
    printf("-----------------------\n");

}
    switch(opcion){
        case 1:
            Sumarmatriz  (A, B, R);
            imprimirMatrizHorizontal(A, '+', B, R);
            break;
        case 2:
            restarmatriz(A, B, R);
            imprimirMatrizHorizontal(A, '-', B, R);
            break;
        case 3:
            printf("Pon tu num para el escalar: ");
            scanf("%d", &esc);
            escalar(A, R, esc);
            imprimirMatrizEscalar(A, esc, R);
            break;
        case 4:
            imprimirDeterminante(A, sarrus(A));
            break;
        default:
            printf("Opc invalida .\n");
    }

    return 0;
}
