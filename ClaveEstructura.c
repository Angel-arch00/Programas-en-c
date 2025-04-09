#include <stdio.h>
#include <string.h>

struct KeyValue{
    char clave[50];
    char valor [100];
    };
    int  main(){
        struct KeyValue tabla[3]={
            {"usuario","admin"},
            {"contraseña","1234"},
            {"servidor","localhost"}
        };
        printf("Tabla Clave-Valor:\n");
        for (int i = 0; i< 3; i++){
            printf("%s: %s\n", tabla[1].clave, tabla[1].valor);
        }
        return 0;
    }