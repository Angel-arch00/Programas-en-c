#include <stdio.h>
#include <string.h>

int main() {
    char descripcion_problema[] = "El celular no prende y tiene la pantalla estrellada.";
    char palabra_clave[] = "pantalla";
    char *encontrado;

    printf("Descripción del problema: '%s'\n", descripcion_problema);
    printf("Buscando la palabra: '%s'\n", palabra_clave);

    encontrado = strstr(descripcion_problema, palabra_clave);

    if (encontrado != NULL) {
        printf("¡Sí! La palabra '%s' está en la descripción del problema.\n", palabra_clave);
    } else {
        printf("No encontré la palabra '%s' en la descripción.\n", palabra_clave);
    }

    return 0;
}