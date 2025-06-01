#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 

#define MAX 100


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    FILE *file;
    char nombre[MAX];
    int edad;
    char pais[MAX];
    int cantidad, i;
    int baseX = 5, baseY = 5; 

    file = fopen("salida.csv", "w");
    if (file == NULL) {
        perror("Error al crear el archivo");
        return 1;
    }

    fprintf(file, "Nombre,Edad,Pais\n");

    printf("¿Cuántas personas quieres registrar? ");
    scanf("%d", &cantidad);
    getchar(); 

    system("cls"); 
    setColor(11); 

    gotoxy(baseX, baseY);
    printf("No");
    gotoxy(baseX + 5, baseY);
    printf("Nombre");
    gotoxy(baseX + 20, baseY);
    printf("Edad");
    gotoxy(baseX + 30, baseY);
    printf("Pais");

    setColor(15); 

    for (i = 0; i < cantidad; i++) {
        gotoxy(baseX, baseY + i + 2);
        printf("%d", i + 1);

        gotoxy(baseX + 5, baseY + i + 2);
        printf("____________"); 

        gotoxy(baseX + 20, baseY + i + 2);
        printf("____");

        gotoxy(baseX + 30, baseY + i + 2);
        printf("__________");
    }

    
    for (i = 0; i < cantidad; i++) {
        gotoxy(0, baseY + cantidad + 4);
        printf("\nPersona %d\n", i + 1);

        printf("Nombre: ");
        fgets(nombre, MAX, stdin);
        nombre[strcspn(nombre, "\n")] = 0;

        printf("Edad: ");
        scanf("%d", &edad);
        getchar();

        printf("Pais: ");
        fgets(pais, MAX, stdin);
        pais[strcspn(pais, "\n")] = 0;

        fprintf(file, "%s,%d,%s\n", nombre, edad, pais);

 
        setColor(10); 
        gotoxy(baseX + 5, baseY + i + 2);
        printf("%-10s", nombre);

        setColor(14); 
        gotoxy(baseX + 20, baseY + i + 2);
        printf("%-4d", edad);

        setColor(13); 
        gotoxy(baseX + 30, baseY + i + 2);
        printf("%-10s", pais);

        setColor(15); 
    }

    gotoxy(0, baseY + cantidad + 6);
    fclose(file);
    printf("\nArchivo 'salida.csv' creado exitosamente.\n");

    return 0;
}

