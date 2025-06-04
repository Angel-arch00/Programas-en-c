#include <stdio.h>
#include <string.h>

int main() {
    char correo_electronico[50];
    char *arroba_encontrada;

    printf("Escribe tu correo electrónico: ");
    fgets(correo_electronico, sizeof(correo_electronico), stdin);
    correo_electronico[strcspn(correo_electronico, "\n")] = '\0'; 

    arroba_encontrada = strchr(correo_electronico, '@');

    if (arroba_encontrada != NULL) {
        printf("¡Encontré la '@'! Está en la posición número %ld de tu correo.\n", arroba_encontrada - correo_electronico + 1);
    } else {
        printf("parece que no hay una '@' en tu correo. ¡Algo anda mal!\n");
    }

    return 0;
}
