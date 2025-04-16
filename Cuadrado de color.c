#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setColor(int colorCode) {
    printf("\033[48;5;%dm", colorCode);  
}

int main() {
    int n;
    printf("Introduce el tamaño del cuadrado: ");
    scanf("%d", &n);

    srand(time(0));//lo del random



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            int color = rand() % 256;
            setColor(color);  //pongo color segun el random 
            printf("    ");  
        }
        printf("\033[0m\n");  
    }

    return 0;
}