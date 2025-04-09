#include <stdio.h>
int suma(int a,int b){
    return a+b;
}
int resta (int a, int b){
    int resultado = a-b;
    return resultado;
}
int multiplicar(int a){
    return a*a;
}
float dividir(int a, int b){
    return a/b;
}
void imprimir(int a, int b,int c, float d){
    printf("\n Retultados: \n Suma %d \n Resta %d \n Multiplicacion %d \n Divi %.2f");
}
int main(){
    //Mnadar a llamar las funciones
    int op1=suma(3,2);
    int op2=resta(5,3);
    int op3=multiplicar(3);
    float op4=dividir(5,3);
    imprimir (op1,op2,op3,op4);
    return 0;
}