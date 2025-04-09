#include <stdio.h>

#define FILAS 3 // Número de filas

int main() {
    float val1[FILAS], val2[FILAS];
    float suma[FILAS], resta[FILAS], mult[FILAS], div[FILAS];

    printf("Ingrese los valores:\n");
    for (int i = 0; i < FILAS; i++) {
        printf("Ingrese val1[%d]: ", i);
        scanf("%f", &val1[i]);
        printf("Ingrese val2[%d]: ", i);
        scanf("%f", &val2[i]);

        
        suma[i] = val1[i] + val2[i];
        resta[i] = val1[i] - val2[i];
        mult[i] = val1[i] * val2[i];
        div[i] = (val2[i] != 0) ? (val1[i] / val2[i]) : 0; 
    }


    printf("\n----------------------------------------------------\n");
    printf("| Val1  | Val2  | Suma  | Resta | Mult. |  Div.  |\n");
    printf("----------------------------------------------------\n");
    
    for (int i = 0; i < FILAS; i++) {
        printf("| %-6.2f| %-6.2f| %-6.2f| %-6.2f| %-6.2f| %-6.2f|\n",
               val1[i], val2[i], suma[i], resta[i], mult[i], div[i]);
    }

    printf("----------------------------------------------------\n");

    return 0;
}
