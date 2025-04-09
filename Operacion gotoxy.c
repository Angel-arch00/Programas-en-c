#include <stdio.h>
 
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
 
// Función para cambiar el color
void setColor(const char* color) {
    printf("%s", color);
}
 
int main() {
    int num1;
    int num2;
    int opcion;
    printf("\033[2J"); // Limpia la pantalla
    setColor("\033[7;34m");
 
    gotoxy(10, 9);
    printf("%s\n", "Calculadora en C");
    do {
        gotoxy(10, 5);
        setColor("\033[4m");
        printf("%s\n", "Seleccione una operación");
        gotoxy(10, 6);
        setColor("\033[7;31m");
        printf("%s\n", "1-");
        setColor("\033[0m");
        gotoxy(15, 6);
        printf("suma");
        gotoxy(10, 7);
        setColor("\033[7;32m");
        printf("%s\n", "2-");
        setColor("\033[0m");
        gotoxy(15, 7);
        printf("resta");
        gotoxy(10, 8);
        setColor("\033[7;33m");
        printf("%s\n", "3-");
        setColor("\033[0m");
        gotoxy(15, 8);
        printf("multiplicacion");
        gotoxy(10, 9);
        setColor("\033[7;35m");
        printf("%s\n", "4-");
        setColor("\033[0m");
        gotoxy(15, 9);
        printf("division");
       
        gotoxy(10, 11);
        setColor("\033[7;37m");
        printf("%s\n", "6-");
        setColor("\033[0m");
        gotoxy(15, 11);
        printf("Salir");
        printf("%s", "Ingrese su opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("%s", "Ingrese el primer número: ");
            scanf("%f", &num1);
            printf("%s", "Ingrese el segundo número: ");
            scanf("%f", &num2);
            
            switch (opcion) {
            case 1:
                printf("%s%.2d\n", "Resultado: ", num1 + num2);
                break;
            case 2:
                printf("%s%.2d\n", "Resultado: ", num1 - num2);
                break;
            case 3:
                printf("%s%.2d\n", "Resultado: ", num1 * num2);
                break;
            case 4:
                if (num2 != 0)
                    printf("%s%.2d\n", "Resultado: ", num1 / num2);
                else
                    printf("%s\n", "Error: División por cero.");
                break;
            case 5:
                if ((int)num2 != 0)
                    printf("%s%d\n", "Resultado: ", (int)num1 % (int)num2);
                else
                    printf("%s\n", "Error: División por cero.");
                break;
            }
            break;
        case 6:
            printf("%s\n", "Saliendo...");
            break;
        default:
            printf("%s\n", "Opción no válida. Intente nuevamente.");
        }
    } while (opcion != 6);

    return 0;
}