#include <stdio.h>

#define MAX_BARRAS 5
#define MAX_ALTURA 10


const char *colores[] = {
    "\033[31m", // 1 - Rojo
    "\033[32m", // 2 - Verde
    "\033[33m", // 3 - Amarillo
    "\033[34m", // 4 - Azul
    "\033[35m", // 5 - Magenta
    "\033[36m", // 6 - Cian
    "\033[37m"  // 7 - Blanco
};
const char *RESET = "\033[0m"; 

void imprimirMarcoSuperior() {
    printf("***********************\n");
}

void imprimirMarcoInferior() {
    printf("***********************\n");
}

void imprimirGrafico(int valores[], int coloresElegidos[], int cantidad) {
    imprimirMarcoSuperior();

    for (int altura = MAX_ALTURA; altura > 0; altura--) {
        printf("* ");
        for (int i = 0; i < cantidad; i++) {
            printf("%s", colores[coloresElegidos[i] - 1]); 
            if (valores[i] >= altura) {
                printf("XX   ");
            } else {
                printf("     ");
            }
            printf("%s", RESET); 
        }
        printf("*\n");
    }

    imprimirMarcoInferior();
}

int main() {
    int valores[MAX_BARRAS], coloresElegidos[MAX_BARRAS], cantidad;

    printf("Ingrese la cantidad de barras (máximo %d): ", MAX_BARRAS);
    scanf("%d", &cantidad);

    if (cantidad > MAX_BARRAS || cantidad <= 0) {
        printf("Cantidad inválida. Debe estar entre 1 y %d.\n", MAX_BARRAS);
        return 1;
    }

    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el valor de la barra %d (máximo %d): ", i + 1, MAX_ALTURA);
        scanf("%d", &valores[i]);
        if (valores[i] > MAX_ALTURA) valores[i] = MAX_ALTURA; 

        do {
            printf("Elija un color para la barra %d (1-Rojo, 2-Verde, 3-Amarillo, 4-Azul, 5-Magenta, 6-Cian, 7-Blanco): ", i + 1);
            scanf("%d", &coloresElegidos[i]);
        } while (coloresElegidos[i] < 1 || coloresElegidos[i] > 7);
    }

    imprimirGrafico(valores, coloresElegidos, cantidad);

    return 0;
}
