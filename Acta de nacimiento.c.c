#include <stdio.h>

struct ActaDeNacimiento {
    char nombre[50];
    char apellido[50];
    char fechaNacimiento[15]; 
    char curp[20];
    char lugarNacimiento[50];
    char nacionalidad[20];
    char sexo[10];
    char nombrePadres[100]; 
};

int main() {
    int size;
    printf("Ingresa el número de actas a registrar: ");
    scanf("%d", &size);
    getchar(); // Limpia el buffer para evitar problemas con fgets

    if (size <= 0) {
        printf("Error: El número de actas debe ser mayor que 0.\n");
        return 1;
    }

    struct ActaDeNacimiento arreglo[size]; // Se crea el arreglo con el tamaño ingresado

    for (int i = 0; i < size; i++) {
        printf("\nIngrese los datos del acta de nacimiento %d:\n", i + 1);

        printf("Nombre: ");
        fgets(arreglo[i].nombre, sizeof(arreglo[i].nombre), stdin);

        printf("Apellido: ");
        fgets(arreglo[i].apellido, sizeof(arreglo[i].apellido), stdin);

        printf("Fecha de nacimiento (DD/MM/AAAA): ");
        fgets(arreglo[i].fechaNacimiento, sizeof(arreglo[i].fechaNacimiento), stdin);

        printf("CURP: ");
        fgets(arreglo[i].curp, sizeof(arreglo[i].curp), stdin);

        printf("Lugar de nacimiento: ");
        fgets(arreglo[i].lugarNacimiento, sizeof(arreglo[i].lugarNacimiento), stdin);

        printf("Nacionalidad: ");
        fgets(arreglo[i].nacionalidad, sizeof(arreglo[i].nacionalidad), stdin);

        printf("Sexo: ");
        fgets(arreglo[i].sexo, sizeof(arreglo[i].sexo), stdin);

        printf("Nombre de los padres: ");
        fgets(arreglo[i].nombrePadres, sizeof(arreglo[i].nombrePadres), stdin);
    }

    printf("\nActas de nacimiento registradas:\n");
    for (int i = 0; i < size; i++) {
        printf("\nActa %d:\n", i + 1);
        printf("Nombre: %s", arreglo[i].nombre);
        printf("Apellido: %s", arreglo[i].apellido);
        printf("Fecha de nacimiento: %s", arreglo[i].fechaNacimiento);
        printf("CURP: %s", arreglo[i].curp);
        printf("Lugar de nacimiento: %s", arreglo[i].lugarNacimiento);
        printf("Nacionalidad: %s", arreglo[i].nacionalidad);
        printf("Sexo: %s", arreglo[i].sexo);
        printf("Nombre de los padres: %s", arreglo[i].nombrePadres);
    }

    return 0;
}



