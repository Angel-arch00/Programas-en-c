#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcion;

    do {
        printf("\n========= MENU PRINCIPAL =========\n");
        printf("1. Apuntador1\n");
        printf("2. ApuntadoresConstante\n");
        printf("3. Arreglo\n");
        printf("4. Arreglo2\n");
        printf("5. ArregloEstructuras\n");
        printf("6. BanderaEUA\n");
        printf("7. BanderaMexico\n");
        printf("8. ClaveValor\n");
        printf("9. Colores\n");
        printf("10. CuadradoColores\n");
        printf("11. DibujoMatrices\n");
        printf("12. EcuacionCuadraticaEstructura\n");
        printf("13. Estructrua\n");
        printf("14. EstructuraAnidada\n");
        printf("15. EstructuraAnidada2\n");
        printf("16. EstructuraCarro\n");
        printf("17. EstructuraImpresion\n");
        printf("18. EstructuraLeer\n");
        printf("19. EstructuraUnicon1\n");
        printf("20. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: system("Apuntador1.exe"); break;
            case 2: system("ApuntadoresConstante.exe"); break;
            case 3: system("Arreglo.exe"); break;
            case 4: system("Arreglo2.exe"); break;
            case 5: system("ArregloEstructuras.exe"); break;
            case 6: system("BanderaEUA.exe"); break;
            case 7: system("BanderaMexico.exe"); break;
            case 8: system("ClaveValor.exe"); break;
            case 9: system("Colores.exe"); break;
            case 10: system("CuadradoColores.exe"); break;
            case 11: system("DibujoMatrices.exe"); break;
            case 12: system("EcuacionCuadraticaEstructura.exe"); break;
            case 13: system("Estructrua.exe"); break;
            case 14: system("EstructuraAnidada.exe"); break;
            case 15: system("EstructuraAnidada2.exe"); break;
            case 16: system("EstructuraCarro.exe"); break;
            case 17: system("EstructuraImpresion.exe"); break;
            case 18: system("EstructuraLeer.exe"); break;
            case 19: system("EstructuraUnicon1.exe"); break;
            case 20: printf("Saliendo del programa...\n"); break;
            default: printf("Opción inválida. Intente de nuevo.\n"); break;
        }

    } while (opcion != 20);

    return 0;
}
