#include <stdio.h>
#include <string.h>

union Camion {
    float capacidad_carga; 
};

union Moto {
    char tipo_motor[10]; 
};


struct Vehiculo {
    char tipo[10]; 
    union {
        union Camion camion;
        union Moto moto;
    } datos;
};

int main() {
    struct Vehiculo v1, v2;


    strcpy(v1.tipo, "Camion");
    v1.datos.camion.capacidad_carga = 5.5; 


    strcpy(v2.tipo, "Moto");
    strcpy(v2.datos.moto.tipo_motor, "4T"); 
    
    printf("Vehiculo 1: %s\n", v1.tipo);
    printf("Capacidad de carga: %.1f toneladas\n\n", v1.datos.camion.capacidad_carga);

    printf("Vehiculo 2: %s\n", v2.tipo);
    printf("Tipo de motor: %s\n", v2.datos.moto.tipo_motor);

    return 0;
}
