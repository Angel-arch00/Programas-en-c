#include <stdio.h>
#include <string.h>

int main() {
    char mensaje_original[] = "¡Tu teléfono ya está reparado!";
    char copia_mensaje[100];

    printf("Mensaje original: %s\n", mensaje_original);
    strcpy(copia_mensaje, mensaje_original);
    printf("Copia del mensaje: %s\n", copia_mensaje);

    return 0;
}