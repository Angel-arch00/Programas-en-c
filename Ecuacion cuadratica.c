#include <stdio.h>
#include <math.h>
#include <string.h>

struct EcuacionCuadratica {
    int a;
    int b;
    int c;
    int discriminante;
    double x1;
    double x2;
    char solucion[20]; 
};

int main() {
    struct EcuacionCuadratica arreglo[2] = {
        {2, 3, -5, 0, 0.0, 0.0, ""},
        {3, 7, -6, 0, 0.0, 0.0, ""}
    };

    for (int i = 0; i < 2; i++) {
        int d = pow(arreglo[i].b, 2) - 4 * arreglo[i].a * arreglo[i].c;
        arreglo[i].discriminante = d;

        if (d < 0) {
            strcpy(arreglo[i].solucion, "NO TIENE SOL.");
        } else {
            double valx1 = (-arreglo[i].b + sqrt(d)) / (2.0 * arreglo[i].a);
            double valx2 = (-arreglo[i].b - sqrt(d)) / (2.0 * arreglo[i].a);
            arreglo[i].x1 = valx1;
            arreglo[i].x2 = valx2;
            strcpy(arreglo[i].solucion, "Tiene solución");
        }
    }
    
    printf("%-3s %-3s %-3s %-10s %-10s %-15s\n", "a", "b", "c", "x1", "x2", "Solución");
    printf("--------------------------------------------------\n");


    for (int i = 0; i < 2; i++) {
        printf("%-3d %-3d %-3d %-10.2f %-10.2f %-15s\n",
               arreglo[i].a,
               arreglo[i].b,
               arreglo[i].c,
               arreglo[i].x1,
               arreglo[i].x2,
               arreglo[i].solucion);
    }

    return 0;
}

    

