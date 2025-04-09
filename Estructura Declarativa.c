#include <stdio.h>

typedef struct{// firma sde la estructura
    char nombre[50];
    int edad;
    float promedio;
}Estudiante;
int main(){
    Estudiante estudiante1 = {"Maria Lopez",22,9.3};
    printf("Nombre: %s\n",estudiante1.nombre);
    return 0;

}