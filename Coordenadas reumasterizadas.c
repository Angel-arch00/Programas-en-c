#include <math.h>
        #include <stdio.h>
        
        struct Coordenadas {
            int x;
            int y;
        };
        
        int main() {
            int opc;
            printf("%s\n", "Seleccione una opción:");
            printf("%s\n", "1. Cuadrado");
            printf("%s\n", "2. Triángulo");
            scanf("%d", &opc);
        
            switch (opc) {
                case 1: { // Cuadrado
                    struct Coordenadas arreglo[4];
                    for (int i = 0; i < 4; i++) {
                        printf("Ingrese coordenada %d, x: ", i + 1);
                        scanf("%d", &arreglo[i].x);
                        printf("Ingrese coordenada %d, y: ", i + 1);
                        scanf("%d", &arreglo[i].y);
                    }
        
                    float ab = sqrt(pow(arreglo[1].x - arreglo[0].x, 2) + pow(arreglo[1].y - arreglo[0].y, 2));
                    float bc = sqrt(pow(arreglo[2].x - arreglo[1].x, 2) + pow(arreglo[2].y - arreglo[1].y, 2));
                    float cd = sqrt(pow(arreglo[3].x - arreglo[2].x, 2) + pow(arreglo[3].y - arreglo[2].y, 2));
                    float ad = sqrt(pow(arreglo[0].x - arreglo[3].x, 2) + pow(arreglo[0].y - arreglo[3].y, 2));
        
                    float perimetro = ab + bc + cd + ad;
                    float area = ab * bc; 
        
                    printf("Perímetro total: %.2f\n", perimetro);
                    printf("Área: %.2f\n", area);
        
                    break;
        
                }
                case 2:{// Triangulo
            }
        
            return 0;
        }
    }
