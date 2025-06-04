#include <stdio.h>
#include <string.h>

int main() {
    char apellido_completo[] = "Simon Salinas";
    char letra_buscada = 'a';
    char *ultima_aparicion;

    printf("Apellido: %s\n", apellido_completo);
    printf("Buscando la última letra '%c'\n", letra_buscada);

    ultima_aparicion = strrchr(apellido_completo, letra_buscada);

    if (ultima_aparicion != NULL) {
        printf("¡La última '%c' está en la posición %ld!\n", letra_buscada, ultima_aparicion - apellido_completo + 1);
    } else {
        printf("La letra '%c' no aparece en el apellido.\n", letra_buscada);
    }

    return 0;
}