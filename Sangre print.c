#include <stdio.h>

struct Sangre {
    char nombre[50];
    char tipo_sanguineo[5];
    char rh[3];
    float ph;
    char viscosidad[20];
    char color[15];
    float hematocrito;
    float hemoglobina;
    int leucocitos;
    int plaquetas;
    float glucosa;
    float oxigeno;
    float presion_osmotica;
};

int main() {
    int n;
    printf("Ingrese número de registros de sangre: ");
    scanf("%d", &n);
    getchar();  

    struct Sangre sangre[n];

    for (int i = 0; i < n; i++) {
        printf("\nIngrese los datos de la sangre %d:\n", i + 1);
        
        printf("Nombre: ");
        fgets(sangre[i].nombre, 50, stdin);
        
        printf("Tipo sanguíneo: ");
        scanf("%4s", sangre[i].tipo_sanguineo);

        printf("RH: ");
        scanf("%2s", sangre[i].rh);

        printf("pH: ");
        scanf("%f", &sangre[i].ph);

        printf("Viscosidad: ");
        scanf("%s", &sangre[i].viscosidad);

        printf("Color de sangre: ");
        scanf("%14s", sangre[i].color);

        printf("Hematocrito: ");
        scanf("%f", &sangre[i].hematocrito);

        printf("Hemoglobina: ");
        scanf("%f", &sangre[i].hemoglobina);

        printf("Leucocitos: ");
        scanf("%d", &sangre[i].leucocitos);

        printf("Plaquetas: ");
        scanf("%d", &sangre[i].plaquetas);

        printf("Nivel de glucosa: ");
        scanf("%f", &sangre[i].glucosa);

        printf("Nivel de oxígeno: ");
        scanf("%f", &sangre[i].oxigeno);

        printf("Presión osmótica: ");
        scanf("%f", &sangre[i].presion_osmotica);
        
        getchar();  
    }

    printf("\n%-20s | %-10s | %-5s | %-5.2f| %-10s | %-10s | %-10.2f | %-10.2f | %-10d | %-10d | %-10.2f| %-10.2f | %-10.2f\n", 
           "Nombre", "Tipo", "RH", "pH", "Viscosidad", "Color", "Hematocrito", "Hemoglobina", "Leucocitos", "Plaquetas", "Glucosa", "Oxígeno", "Pres. Osmotica");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-20s | %-10s | %-5s | %-5.2f | %-10s| %-10s | %-10.2f | %-10.2f | %-10d | %-10d | %-10.2f | %-10.2f | %-10.2f\n", 
               sangre[i].nombre, 
               sangre[i].tipo_sanguineo, 
               sangre[i].rh, 
               sangre[i].ph, 
               sangre[i].viscosidad, 
               sangre[i].color, 
               sangre[i].hematocrito, 
               sangre[i].hemoglobina, 
               sangre[i].leucocitos, 
               sangre[i].plaquetas, 
               sangre[i].glucosa, 
               sangre[i].oxigeno, 
               sangre[i].presion_osmotica);
    }

    return 0;
}
