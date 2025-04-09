#include <stdio.h>
#define PI 3.1416

union Dato {
    float resultado;
};

typedef struct {
    float area;
    float volumen;
} Resultados;

// Figuras 2D
float cuadrado(float lado) {
    return lado * lado;
}

float triangulo(float base, float altura) {
    return (base * altura) / 2;
}

float rectangulo(float base, float altura) {
    return base * altura;
}

float circulo(float radio) {
    return PI * radio * radio;
}

float trapecio(float base_mayor, float base_menor, float altura) {
    return ((base_mayor + base_menor) / 2) * altura;
}

// Figuras 3D
Resultados cubo(float lado) {
    Resultados r;
    r.area = 6 * lado * lado;
    r.volumen = lado * lado * lado;
    return r;
}

Resultados piramide(float base, float altura) {
    Resultados r;
    r.area = base + (4 * ((base * altura) / 2));
    r.volumen = (base * altura) / 3;
    return r;
}

Resultados caja_rectangular(float largo, float ancho, float altura) {
    Resultados r;
    r.area = 2 * ((largo * ancho) + (largo * altura) + (ancho * altura));
    r.volumen = largo * ancho * altura;
    return r;
}

Resultados esfera(float radio) {
    Resultados r;
    r.area = 4 * PI * radio * radio;
    r.volumen = (4.0 / 3.0) * PI * radio * radio * radio;
    return r;
}

Resultados cono(float radio, float altura) {
    Resultados r;
    float generatriz = sqrt((radio * radio) + (altura * altura));
    r.area = PI * radio * (radio + generatriz);
    r.volumen = (1.0 / 3.0) * PI * radio * radio * altura;
    return r;
}

void imprimir(Resultados r) {
    printf("\nÁrea: %.2f\n", r.area);
    printf("Volumen: %.2f\n", r.volumen);
}

int main() {
    int opc;
    Resultados figura;
    
    printf("\nElige la dimensión de tu figura:");
    printf("\n1. Figuras 2D");
    printf("\n2. Figuras 3D");
    printf("\nOpc: ");
    scanf("%d", &opc);
    
    if (opc == 1) {
        printf("\nElige la figura 2D que deseas calcular su área:");
        printf("\n1. Cuadrado");
        printf("\n2. Triángulo");
        printf("\n3. Rectángulo");
        printf("\n4. Círculo");
        printf("\n5. Trapecio");
        printf("\nOpc: ");
        
        int opc2;
        scanf("%d", &opc2);
        
        float valor1, valor2;
        switch (opc2) {
            case 1:
                printf("\nIngrese el lado del cuadrado: ");
                scanf("%f", &valor1);
                printf("\nÁrea: %.2f\n", cuadrado(valor1));
                break;
            case 2:
                printf("\nIngrese la base del triángulo: ");
                scanf("%f", &valor1);
                printf("Ingrese la altura del triángulo: ");
                scanf("%f", &valor2);
                printf("\nÁrea: %.2f\n", triangulo(valor1, valor2));
                break;
            case 3:
                printf("\nIngrese la base del rectángulo: ");
                scanf("%f", &valor1);
                printf("Ingrese la altura del rectángulo: ");
                scanf("%f", &valor2);
                printf("\nÁrea: %.2f\n", rectangulo(valor1, valor2));
                break;
            case 4:
                printf("\nIngrese el radio del círculo: ");
                scanf("%f", &valor1);
                printf("\nÁrea: %.2f\n", circulo(valor1));
                break;
            case 5:
                printf("\nIngrese la base mayor del trapecio: ");
                scanf("%f", &valor1);
                printf("Ingrese la base menor del trapecio: ");
                scanf("%f", &valor2);
                printf("Ingrese la altura del trapecio: ");
                float altura;
                scanf("%f", &altura);
                printf("\nÁrea: %.2f\n", trapecio(valor1, valor2, altura));
                break;
            default:
                printf("\nOpción inválida\n");
                return 0;
        }
    }
    else if (opc == 2) {
        printf("\nElige la figura 3D que deseas calcular su área y volumen:");
        printf("\n1. Cubo");
        printf("\n2. Pirámide");
        printf("\n3. Caja Rectangular");
        printf("\n4. Esfera");
        printf("\n5. Cono");
        printf("\nOpc: ");
        
        int opc3;
        scanf("%d", &opc3);
        
        float valor1, valor2;
        switch (opc3) {
            case 1:
                printf("\nIngrese el lado del cubo: ");
                scanf("%f", &valor1);
                figura = cubo(valor1);
                break;
            case 2:
                printf("\nIngrese la base de la pirámide: ");
                scanf("%f", &valor1);
                printf("Ingrese la altura de la pirámide: ");
                scanf("%f", &valor2);
                figura = piramide(valor1, valor2);
                break;
            case 3:
                printf("\nIngrese el largo de la caja: ");
                scanf("%f", &valor1);
                printf("Ingrese el ancho de la caja: ");
                scanf("%f", &valor2);
                printf("Ingrese la altura de la caja: ");
                float altura;
                scanf("%f", &altura);
                figura = caja_rectangular(valor1, valor2, altura);
                break;
            case 4:
                printf("\nIngrese el radio de la esfera: ");
                scanf("%f", &valor1);
                figura = esfera(valor1);
                break;
            case 5:
                printf("\nIngrese el radio del cono: ");
                scanf("%f", &valor1);
                printf("Ingrese la altura del cono: ");
                scanf("%f", &valor2);
                figura = cono(valor1, valor2);
                break;
            default:
                printf("\nOpción inválida\n");
                return 0;
        }
        imprimir(figura);
    }
    else {
        printf("\nOpción inválida\n");
    }
    return 0;
}

