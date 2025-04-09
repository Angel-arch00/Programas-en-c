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
    Dato valor;
    int tipo; 
} Celda;

int main() {
    Celda matriz[FILAS][COLUMNAS];
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            int opcion;
            printf("Ingrese el tipo de dato para la celda [%d][%d]:\n", i, j);
            printf("1. Persona\n2. Producto\nSeleccione una opción: ");
            scanf("%d", &opcion);
            
            switch (opcion) {
                case 1:
                    matriz[i][j].tipo = 1;
                    printf("Ingrese el nombre de la persona: ");
                    scanf("%[^\n]s", matriz[i][j].valor.persona.nombre);

                    printf("Ingrese la edad de la persona: ");
                    scanf("%d", &matriz[i][j].valor.persona.edad);

                    break;

                case 2:
                    matriz[i][j].tipo = 2;
                    printf("Ingrese el nombre del producto: ");
                    scanf("%[^\n]s", matriz[i][j].valor.producto.producto);

                    printf("Ingrese el precio del producto: ");
                    scanf("%f", &matriz[i][j].valor.producto.precio);

                    break;

                default:
                    printf("Opción inválida. Se dejará la celda vacía.\n");
                    matriz[i][j].tipo = 0;
            }
        }
    }

    
    printf("\nRecorriendo la matriz:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Celda [%d][%d]: ", i, j);
            switch (matriz[i][j].tipo) {
                case 1:
                    printf("Persona - Nombre: %s, Edad: %d\n",
                           matriz[i][j].valor.persona.nombre,
                           matriz[i][j].valor.persona.edad);
                    break;

                case 2:
                    printf("Producto - Nombre: %s, Precio: %.2f\n",
                           matriz[i][j].valor.producto.producto,
                           matriz[i][j].valor.producto.precio);
                    break;

                default:
                    printf("Celda vacía.\n");
            }
        }
    }

    return 0;
}


