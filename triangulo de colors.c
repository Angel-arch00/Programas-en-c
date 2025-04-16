#include<stdio.h>
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
 
// Función para cambiar el color
void setColor(const char* color) {
    printf("%s", color);
}
int main(){
    printf("\033[0m"); //limpio
    setColor("\033[7;32m");//pongo color
    printf("Triangulo de colores\n ");


    printf("\033[0m"); //limpio
    int espacios=6, asteriscos=1;
    for(int i=6; i>=0;i--){
        for(int j=1;j<=espacios;j++){
            printf("%4s"," ");
        }
        espacios--;
        for(int k=1;k<=asteriscos;k++){
            setColor("\033[7;35m");//pongo color
            printf("%4s","*");
            printf("\033[0m"); //limpio
            
        }
        asteriscos +=2;
            printf("\n");
            printf("\033[0m"); //limpio
    }
    return 0;
}