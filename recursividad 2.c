#include <stdio.h>

void hanoi(int n, char origen, char auxiliar, char destino) {
    if (n == 1) {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }
    
    hanoi(n - 1, origen, destino, auxiliar);
    printf("Mover disco %d de %c a %c\n", n, origen, destino);
    hanoi(n - 1, auxiliar, origen, destino);
}

int main() {
    int num_discos = 3; 
    
    printf("Movimientos para resolver Torres de Hanói con %d discos:\n", num_discos);
    hanoi(num_discos, 'A', 'B', 'C'); 

    return 0;
}   