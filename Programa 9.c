#include <stdio.h>
#include <string.h>

int main() {
    char campo_formulario[30];
   
    printf("Campo antes de limpiar: '%s'\n", campo_formulario);

 
    memset(campo_formulario, '\0', sizeof(campo_formulario));

    printf("Campo después de limpiar: '%s' (¡ya está listo para escribir!)\n", campo_formulario);

    return 0;
}