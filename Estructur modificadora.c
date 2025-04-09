#include <stdio.h>
struct Direccion{
    char calle[50];
    int numero;
};
struct Persona{
    char nombre [50];
    struct Direccion domicilio;
};
int main(){
    struct Persona persona1 = {"Carlos Alberto",{"AV.Palacios",223}};
    printf ("Nombre:%s\n", persona1.nombre);
    printf("Domicilio; %s #%d\n", persona1.domicilio.calle, persona1.domicilio.numero);
    return 0;
}