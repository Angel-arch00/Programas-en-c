#include <stdio.h>

int main() {
    int filas = 7;
    
    for (int i = filas; i >= 1; i--) {
       
        for (int j = 0; j < filas - i; j++) {
            printf("     "); 
        }

      
        printf("\033[0;32m");

        for (int k = 1; k <= i; k++) {
            gotoxy(10,5);
            printf("%5s", "*");
        }

        printf("\n");
    }

    
    printf("\033[0m");

    return 0;
}
