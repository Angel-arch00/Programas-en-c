#include <stdio.h>
#include <string.h>

int main() {
    char nombre[50] = "Alejandro ";
    char apellido[] = "Diaz ";

    printf("El nombre inicial es: %s\n", nombre);
    strcat(nombre, apellido);
    printf("El nombre completo ahora es: %s\n", nombre);

    return 0;
}
