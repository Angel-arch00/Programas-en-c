#include <stdio.h>
#include <string.h>

int main() {
    char marca_modelo[50] = "iPhone ";
    char nombre_completo_modelo[] = "15 Pro Max";
    int caracteres_a_pegar = 6; 

    printf("Marca inicial: %s\n", marca_modelo);
    strncat(marca_modelo, nombre_completo_modelo, caracteres_a_pegar);
    printf("Marca con modelo abreviado: %s\n", marca_modelo);

    return 0;
}