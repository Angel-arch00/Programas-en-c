#include <stdio.h>

int mayor(int a, int b) {
    int resultado = 0;
    if (a < b) {
        resultado = b;
    } else {
        resultado = a;
    }
    return resultado;
}

void imprimir(int resultado) {
    printf("El numero mayor es: %d\n", resultado);
}

int main() {
    int a2, b2;
    printf("Dame tu num 1: ");
    scanf("%d", &a2);
    printf("Dame tu num 2: ");
    scanf("%d", &b2);
    
    int resultado = mayor(a2, b2);
    imprimir(resultado);

    return 0;
}