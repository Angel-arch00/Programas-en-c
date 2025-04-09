#include <stdio.h>
#include <string.h>

#define FILAS 2
#define COLUMNAS 2

typedef struct {
    char nombre[50];
    int edad;
} Persona;

typedef struct {
    char producto[50];
    float precio;
} Producto;

typedef union {
    Persona persona;
    Producto producto;
} Dato;

typedef struct {
    Dato Valor;
    int tipo;
} Celda;

int main() {
    Celda matriz[FILAS][COLUMNAS];

    // Asignación de datos para tipo Persona
    strcpy(matriz[0][0].Valor.persona.nombre, "Roberto");
    matriz[0][0].Valor.persona.edad = 25;
    matriz[0][0].tipo = 1;

    strcpy(matriz[0][1].Valor.persona.nombre, "Alejandro");
    matriz[0][1].Valor.persona.edad = 30;
    matriz[0][1].tipo = 1;

    // Asignación de datos para tipo Producto
    strcpy(matriz[1][0].Valor.producto.producto, "Conejo");
    matriz[1][0].Valor.producto.precio = 88.99;
    matriz[1][0].tipo = 2;

    strcpy(matriz[1][1].Valor.producto.producto, "Golden");
    matriz[1][1].Valor.producto.precio = 1377.99;
    matriz[1][1].tipo = 2;

    printf("Recorriendo la matriz de uniones con estructuras:\n");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Celda [%d][%d]: ", i, j);
            if (matriz[i][j].tipo == 1) {
                printf("Persona - Nombre: %s, Edad: %d\n",
                       matriz[i][j].Valor.persona.nombre,
                       matriz[i][j].Valor.persona.edad);
            } else if (matriz[i][j].tipo == 2) {
                printf("Producto - Nombre: %s, Precio: %.2f\n",
                       matriz[i][j].Valor.producto.producto,
                       matriz[i][j].Valor.producto.precio);
            }
        }
    }
    return 0;
}
