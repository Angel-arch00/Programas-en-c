#include <stdio.h>
#include <string.h>

int main() {
    char comentario_cliente[] = "Me gusta mucho el voley";
    int cantidad_letras = strlen(comentario_cliente);

    printf("El comentario dice: '%s'\n", comentario_cliente);
    printf("Ese comentario tiene %d letras y espacios \n", cantidad_letras);

    return 0;
} 