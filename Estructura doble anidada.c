#include <stdio.h>

struct Estudiante {
    char nombre[50];
    char apellido[50];
    int edad;
    char correo[60];
};

struct Direccion {
    char calle[50];
    int numero;
    char colonia[50];
};

struct Coordenadas { 
    int longitud;
    int latitud;
};

int main() {
    struct Estudiante estudiante;
    struct Direccion direccion;
    struct Coordenadas coordenadas;

    printf("Ingrese su nombre: ");
    scanf("%s", estudiante.nombre); 

    printf("Ingrese su apellido: ");
    scanf("%s", estudiante.apellido);

    printf("Ingrese su edad: ");
    scanf("%d", &estudiante.edad);

    printf("Ingrese su correo: ");
    scanf("%s", estudiante.correo);

    printf("\n--- Datos del Estudiante ---\n");
    printf("Nombre: %s\n", estudiante.nombre);
    printf("Apellido: %s\n", estudiante.apellido);
    printf("Edad: %d\n", estudiante.edad);
    printf("Correo: %s\n", estudiante.correo);

    printf("\n--- Ingresar Dirección ---\n");
    printf("Ingrese calle: ");
    scanf("%s", direccion.calle);

    printf("Ingrese número: ");
    scanf("%d", &direccion.numero);

    printf("Ingrese colonia: ");
    scanf("%s", direccion.colonia);

    printf("\n--- Ingresar Coordenadas ---\n");
    printf("Ingrese longitud: ");
    scanf("%d", &coordenadas.longitud);

    printf("Ingrese latitud: ");
    scanf("%d", &coordenadas.latitud);

    printf("\n--- Datos Completos ---\n");
    printf("Nombre: %s %s\n", estudiante.nombre, estudiante.apellido);
    printf("Edad: %d\n", estudiante.edad);
    printf("Correo: %s\n", estudiante.correo);
    
    printf("\n--- Dirección ---\n");
    printf("Calle: %s, Número: %d, Colonia: %s\n", direccion.calle, direccion.numero, direccion.colonia);

    printf("\n--- Coordenadas ---\n");
    printf("Longitud: %d, Latitud: %d\n", coordenadas.longitud, coordenadas.latitud);

    return 0;
}




