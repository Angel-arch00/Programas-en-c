#include <stdio.h>
#include <string.h>

int main() {
    char modelo_cliente[20];
    char modelo_en_tienda[] = "Samsung Galaxy S23";

    printf("Escribe el modelo de tu teléfono: ");
    fgets(modelo_cliente, sizeof(modelo_cliente), stdin);
    modelo_cliente[strcspn(modelo_cliente, "\n")] = '\0'; 

    printf("Modelo ingresado: %s\n", modelo_cliente);
    printf("Modelo en inventario: %s\n", modelo_en_tienda);

    if (strcmp(modelo_cliente, modelo_en_tienda) == 0) {
        printf(" ¡Son el mismo modelo de teléfono!.\n");
    } else {
        printf("No son el mismo modelo de teléfono, ¡checa bien :(!.\n");
    }

    return 0;
}