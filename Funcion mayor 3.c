#include <stdio.h>

int mayor(int a, int b, int c) {
    int resultado = a;

    if (b > resultado) {
        resultado = b;
    }
    if (c > resultado) {
        resultado = c;
    }

    return resultado;
}

void imprimir(int resultado) {
    printf("El numero mayor es: %d\n", resultado);
}

int main() {
    int a, b, c;
    
    printf("Dame tu num 1: ");
    scanf("%d", &a);
    
    printf("Dame tu num 2: ");
    scanf("%d", &b);
    
    printf("Dame tu num 3: ");
    scanf("%d", &c);
    
    int resultado = mayor(a, b, c);
    imprimir(resultado);

    return 0;
}