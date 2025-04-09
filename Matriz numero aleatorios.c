#include <stdio.h>
#define FILAS 6
#define COLUMNAS 6

int main() {
    int matriz[FILAS][COLUMNAS] = {
        {10, 15, 20, 25, 30, 35},
        {40, 45, 50, 55, 60, 65},
        {70, 75, 80, 85, 90, 95},
        {100, 105, 110, 115, 120, 125},
        {130, 135, 140, 145, 150, 155},
        {160, 165, 170, 175, 180, 185}
    };

    printf("Recorriendo la matriz:\n");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (j % 2 == 0) { 
                printf("|%d ", matriz[i][j]);
            } else { 
                printf("|# ");
            }
        }
        printf("\n");
    }

    return 0;
}
