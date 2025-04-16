#include <stdio.h>


void setBgColor(int color) {
    printf("\033[%dm", color + 10); 
}

void invertColors() {
    printf("\033[3m"); 
}

void resetFormat() {
    printf("\033[0m");
}

int main() {
    int num_barras, i, j;
    int alturas[7]; 
    int colors[] = {31, 32, 33, 34, 35, 36, 37}; 
    
    printf("Cuantas barras desea? (1-7): ");
    scanf("%d", &num_barras);
    
    while(num_barras < 1 || num_barras > 7) {
        printf("ingrese un numero entre el 1 y 7: ");
        scanf("%d", &num_barras);
    }
    
    for(i = 0; i < num_barras; i++) {
        printf("Altura de la barra %d: ", i+1);
        scanf("%d", &alturas[i]);
    }
    
    int max_altura = 0;
    for(i = 0; i < num_barras; i++) {
        if(alturas[i] > max_altura) {
            max_altura = alturas[i];
        }
    }
    
    printf("\nGrafica de barras:\n\n");

    printf(" ");
    for(i = 0; i < num_barras * 4; i++) {
        printf("-");
    }
    printf("\n");

    
    for(i = max_altura; i > 0; i--) {
        printf("|");
        for(j = 0; j < num_barras; j++) {
            if(alturas[j] >= i) {
                setBgColor(colors[j]); 
                invertColors();       
                printf(" * "); 
                resetFormat();       
                printf(" ");    
            } else {
                printf("    "); 
            }
        }
        printf("|\n");
    }

    
    printf(" ");
    for(i = 0; i < num_barras * 4; i++) {
        printf("-");
    }
    printf("\n");

   
    printf(" ");
    for(i = 0; i < num_barras; i++) {
        setBgColor(colors[i]);
        invertColors();
        printf(" %d ", i+1);  
        resetFormat();
        printf(" ");          
    }
    printf("\n");

    return 0;
}
