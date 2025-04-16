// Función para cambiar el color
void setColor(const char* color) {
    printf("%s", color);
}
int main(){
    printf("\033[0m"); //limpio
    setColor("\033[7;32m");//pongo color
    printf("Bandera de mexico");
    printf("\033[0m"); //limpio
    printf("\n");
    printf("\033[0m"); //limpio


    for (int i = 0; i < 5; i++)
    {
        printf("\033[0m"); //limpio
        //verde
    setColor("\033[7;32m");//pongo color
    printf("%4s","*********");
    printf("\033[0m"); //limpio
    //blanco
    setColor("\033[7;37m");//pongo color
    printf("%4s","*********");
    printf("\033[0m"); //limpio
    //rojo
    setColor("\033[7;31m");//pongo color
    printf("%4s","*********");
    printf("\033[0m"); //limpio
    printf("\n");
    }
    
    return 0;
}