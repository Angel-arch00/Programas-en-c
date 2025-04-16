#include <stdio.h>

int main() {
    // Imprimir la bandera de Estados Unidos con asteriscos

    // Línea 1 (parte azul con las estrellas)
    printf("\033[7;34m");
    printf("***** ");
    printf("\033[0m");  // Resetear color
    printf("\033[7;31m");
    printf("**********\n");

    printf("\033[0m");  // Resetear color
    printf("\033[7;34m");
    printf("***** ");
    printf("\033[0m");  // Resetear color
    printf("\033[7;37m");
    printf("**********\n");

    printf("\033[0m");  // Resetear color
    printf("\033[7;31m");
    printf("********");
    printf("\033[0m");  // Resetear color
    printf("\033[7;31m");
    printf("********\n");

    printf("\033[0m");  // Resetear color
    printf("\033[7;37m");
    printf("********");
    printf("********\n");

    printf("\033[0m");  // Resetear color
    printf("\033[7;31m");
    printf("********");
    printf("********\n");

    printf("\033[0m");  // Resetear color
    printf("\033[7;37m");
    printf("********");
    printf("********\n");

    printf("\033[0m");  // Resetear color
    printf("\033[7;31m");
    printf("********");
    printf("********\n");
    printf("\033[0m");  // Resetear color

    return 0;
}