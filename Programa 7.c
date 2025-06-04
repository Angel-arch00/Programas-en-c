#include <stdio.h>
#include <string.h>

int main() {
    char mensaje_largo[] = "¡Gracias por tu compra! Tu pedido será enviado en 24 horas.";
    char mensaje_corto[20]; 

    printf("Mensaje original: %s\n", mensaje_largo);

    strncpy(mensaje_corto, mensaje_largo, sizeof(mensaje_corto) - 1);
    mensaje_corto[sizeof(mensaje_corto) - 1] = '\0'; 

    printf("Mensaje acortado: %s...\n", mensaje_corto);

    return 0;
}