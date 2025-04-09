#include <stdio.h>
#include <math.h>
#include <string.h>

struct Ecuacionescuadraticas {  //Aqui defino mi estrutura y que tipo de datos llevara*// 
    int a;//esta es la variable a que es la que esta elevada al cuadrado 
    int b;//esta es la variable b que siempre se multiplicara con la x
    int c;//esta es la variable c que por lo regular va sola
    int discriminante;//Esta es la Variable de la discriminaate que al hacer la operacion se imprimira su valor
    double x1;//Esta es la variable x1 donde se calculara en las condiciones dependiento sus valores
    double x2;//Esta es la variable x donde se calculara en las condiciones dependiento sus valores
    char solucion[20];
};

int main() {
    struct Ecuacionescuadraticas ecuacion; //Aqui declaro la estructura con la variable ecuacion//
    
    printf("Ingrese los coeficientes a, b y c separados por espacios: "); //Aqui pido que ingresen los valores de la ecuacion//
    scanf("%d %d %d", &ecuacion.a, &ecuacion.b, &ecuacion.c); //Mi escaner leera los valores ingresados//
    
    //Aqui hare la primera operacion que sera el sacar la discriminante
    ecuacion.discriminante = ecuacion.b * ecuacion.b - 4 * ecuacion.a * ecuacion.c;
    
    //Aqui hare una condicion para el discriminante 
    if (ecuacion.discriminante > 0) {
        //Si el discriminante es positivo se calculan las dos raices distintas
        ecuacion.x1 = (-ecuacion.b + sqrt((double)ecuacion.discriminante)) / (2.0 * ecuacion.a); // Aqui se hace el calculo para la raiz
        ecuacion.x2 = (-ecuacion.b - sqrt((double)ecuacion.discriminante)) / (2.0 * ecuacion.a);
        strcpy(ecuacion.solucion, "Raices reales distintas");
    } else if (ecuacion.discriminante == 0) { //Aqui tenemos otra condicion de que si es cero se calcula una raiz doble
        ecuacion.x1 = ecuacion.x2 = -((double)ecuacion.b / (2.0 * ecuacion.a));
        strcpy(ecuacion.solucion, "Raiz doble");
    } else {
        // Este si es negativo es una raiz compleja
        strcpy(ecuacion.solucion, "Raices complejas");
    }
    
    //Con estos print mostrare los resultados dependiendo que tipo de raices sean
    printf("\nResultados:\n");//Aqui se imprimiran los resultados
    printf("Discriminante: %d\n", ecuacion.discriminante);//Aqui impirme el valor del driscriminante
    printf("Solucion: %s\n", ecuacion.solucion);//y su solucinon
    
    if (strcmp(ecuacion.solucion, "Raices complejas") != 0) { 
        //Este if me ayudara a garantizar el imprimir x1 y x2 y asegurara que se muestren las raices cuando sean numeros reales
        printf("x1 = %.2f\n", ecuacion.x1);//Aqui imprime x1 
        printf("x2 = %.2f\n", ecuacion.x2);//Aqui imprime x2
    }

    return 0;
}




