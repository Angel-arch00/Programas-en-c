#include <stdio.h>
#include <math.h>

// Aqui defino la estructura para puntos en el plano cartesiano
struct Punto {
    float x, y; // Aqui defino X y Y como las variables para los puntos
};

// Hago esta funcion para calcular la distancia entre dos puntos
float distancia(struct Punto p1, struct Punto p2) { // Aqui usamos la fórmula de Pitágoras para calcular la distancia
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); // Formula de Pitágoras para obtener la distancia
}

// Esta función es para calcular el perímetro de un triángulo
float perimetroTriangulo(struct Punto p1, struct Punto p2, struct Punto p3) { // Con esta función calculo el perímetro
    return distancia(p1, p2) + distancia(p2, p3) + distancia(p3, p1); // Sumo las distancias de los tres lados del triángulo
}

// Esta es la función para calcular el área de un triángulo usando la fórmula de Herón
float areaTriangulo(struct Punto p1, struct Punto p2, struct Punto p3) { // En esta función defino la estructura para los puntos
    float a = distancia(p1, p2), b = distancia(p2, p3), c = distancia(p3, p1); // Calculo las distancias de los tres lados
    float s = (a + b + c) / 2; // Semi-perímetro
    return sqrt(s * (s - a) * (s - b) * (s - c)); // Aquí aplico la fórmula de Herón para el área
}

// Esta función es para calcular el perímetro de un cuadrado
float perimetroCuadrado(struct Punto p1, struct Punto p2, struct Punto p3, struct Punto p4) {
    return distancia(p1, p2) + distancia(p2, p3) + distancia(p3, p4) + distancia(p4, p1); // Sumo las distancias de los cuatro lados
}

// Función para calcular el área de un cuadrado (suponiendo que es un cuadrado válido)
float areaCuadrado(struct Punto p1, struct Punto p2) {
    return pow(distancia(p1, p2), 2); // Calculo el área usando la fórmula del cuadrado (lado^2)
}

// Función para verificar si los 4 puntos forman un cuadrado (compara distancias)
int esCuadrado(struct Punto p1, struct Punto p2, struct Punto p3, struct Punto p4) {
    float d1 = distancia(p1, p2), d2 = distancia(p2, p3), d3 = distancia(p3, p4), d4 = distancia(p4, p1);
    return d1 == d2 && d2 == d3 && d3 == d4; // Verifico si todos los lados tienen la misma longitud
}

int main() {
    struct Punto puntos[4]; // Defino un arreglo para los puntos
    int opcion; // Variable para elegir si es triángulo o cuadrado

    printf("Seleccione la figura:\n1. Triángulo\n2. Cuadrado\n"); // Le pido al usuario que elija la figura
    scanf("%d", &opcion); // Leo la opción del usuario

    if (opcion == 1) { // Si elige triángulo
        printf("Ingrese las coordenadas de los 3 puntos del triángulo (x y):\n");
        for (int i = 0; i < 3; i++) { // Leo los tres puntos del triángulo
            scanf("%f %f", &puntos[i].x, &puntos[i].y);
        }
        printf("Perímetro del triángulo: %.2f\n", perimetroTriangulo(puntos[0], puntos[1], puntos[2])); // Imprimo el perímetro
        printf("Área del triángulo: %.2f\n", areaTriangulo(puntos[0], puntos[1], puntos[2])); // Imprimo el área
    } else if (opcion == 2) { // Si elige cuadrado
        printf("Ingrese las coordenadas de los 4 puntos del cuadrado (x y):\n");
        for (int i = 0; i < 4; i++) { // Leo los cuatro puntos del cuadrado
            scanf("%f %f", &puntos[i].x, &puntos[i].y);
        }
        if (esCuadrado(puntos[0], puntos[1], puntos[2], puntos[3])) { // Verifico si los puntos forman un cuadrado
            printf("Perímetro del cuadrado: %.2f\n", perimetroCuadrado(puntos[0], puntos[1], puntos[2], puntos[3])); // Imprimo el perímetro
            printf("Área del cuadrado: %.2f\n", areaCuadrado(puntos[0], puntos[1])); // Imprimo el área
        } else {
            printf("Los puntos no forman un cuadrado.\n"); // Si no es cuadrado, informo al usuario
        }
    } else { // Si la opción no es válida
        printf("Opción no válida.\n"); // Mensaje de error
    }
    return 0; // Fin del programa
}

