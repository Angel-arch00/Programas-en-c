/**
 * una union en C es similar a una estrucutura 
 * pero todos los mienmbros comparten la misma ubicacion en memoria
 * 
 * Esto sigifica que solo se puede alamacenar un valor a la vez.
 */

 #include <stdio.h>
 union Dato
 {
    int ebtero,
    float decimal;
    char texto [50];
 };

 int main(){
    union Dato variable{
        variable.entero = 42;
        printf("Entero: %d\n", variable.entero);

        variable.decimal =3.1416;
        printf("Decimal: %.2f\n", variable.decimal);

        sprintf (variable.texto) = "Hola c";
        printf("Texto: %s\n", variable.texto);

        printf()


    };
    

 }
 