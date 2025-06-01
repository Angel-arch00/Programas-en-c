#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARCHIVO "../4datos.csv"
#define TEMP "temp.csv"
#define MAX 100

void crear();
void leer();
void actualizar();
void eliminar();
void menu();

int main (){
    FILE *f = fopen(ARCHIVO,"r");
    if (f == NULL){
        f = fopen (ARCHIVO, "w");
        if (f !=NULL){
            fprintf(f, "id,nombre,edad\n");
            fclose(f);
        }
    }else {
        fclose(f);
    }
    menu();
    return 0;
}

void menu (){
    int opcion;
    do{
        printf("\n=== CRUD CON CSV EN C===\n");
        printf("1.Crear registros\n");
        printf("2. Leer registros\n");
        printf("3. Actualizar registro\n");
        printf("4. Eliminar registro\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); //limpiar buffer 

        switch (opcion){
            case 1: Crear(); break;
            case 2: Leer(); break;
            case 3: Actualizar(); break;
            case 4: Eliminar(); break;
            case 5: printf("Saliendo...\n"); break;
            default: printf ("Opcion invalida.\n");
        }
    } while (opcion != 5);
}
void crear (){
    FILE *f = fopen(ARCHIVO,"w");
    if (f == NULL){
        perror("No se pudo abrir el archivo");
        return;
    }
    int id, edad;
    char nombre[MAX];

    printf("ingrese ID: ");
    scanf("%d", &id);
    getchar();
    printf("Ingrese nombre: ");
    fgets(nombre, MAX, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
    printf("Ingrese edad: ");
    scanf("%d", &edad);

    fprintf(f,  "%d,%s,%d\n", id, nombre, edad);
    fclose(f);
    printf("Registro agregado con exito.\n");

}
void leer (){
    FILE *f = fopen(ARCHIVO,"r");
    if(f == NULL){
        perror("No se pudo abrir el archivo");
        return;
    }

    char Linea [100];
    printf("\n---REGISTRO---\n");
    while (fgets(Linea, MAX, f)){
    {
        printf("%s", Linea);
    }

    fclose(f);
}

void actualizar (){
    int id_buscar, id, edad;
    char nombre[MAX];
    char linea [100], *token;
    int encontrado = 0;

    printf("Ingrese el ID a actualizar: ");
    scanf("%d", &id_buscar);
    getchar();

    FILE *F = fopen(ARCHIVO, "r");
    FILE *f = fopen(TEMP, "w");
    if (f == NULL || tmp == NULL){
        perror("No se pudo abrir archivo ");
        return;
    }
  }
    while (fgets (Linea, MAX, f)){
        char copia[MAX];
        strcpy(copia, Linea);
        token = strtok(copia, ",");
        if (token && strcmp(token, "id") == 0){
            fputs (Linea, tmp);
            continue;
         }

         id = atoi (token);
         if (id == id_buscar){
           printf("Ingrese nuevo nombre: ");
           fgets(nombre, MAX, stdin);
           nombre[strcspn(nombre, "\n")] = '\0';
           printf("Ingrese nueva edad: ");
           scanf("%d", &edad);
           getchar();
           fprintf(tmp, "%d,%s,%d\n", id, nombre, edad);
           encontrado = 1;
         }else{
            fputs(Linea, tmp);
         }
         fclose(f);
         fclose(tmp);
         remove(ARCHIVO);
         rename(TEMP, ARCHIVO);
         
         if (encontrado)
         {
           printf("Registro  actualizado.\n")
         }
        }
        void eliminar() {
            int id_buscar, id;
            char linea[MAX], *token;
            int encontrado = 0;
         
            printf("Ingrese el ID a eliminar: ");
            scanf("%d", &id_buscar);
            getchar();
         
            FILE *f = fopen(ARCHIVO, "r");
            FILE *tmp = fopen(TEMP, "w");
            if (f == NULL || tmp == NULL) {
                perror("No se pudo abrir archivo");
                return;
            }
         
            while (fgets(linea, MAX, f)) {
                char copia[MAX];
                strcpy(copia, linea);
                token = strtok(copia, ",");
                if (token && strcmp(token, "id") == 0) {
                    fputs(linea, tmp);
                    continue;
                }
         
                id = atoi(token);
                if (id == id_buscar) {
                    encontrado = 1;
                    continue;
                } else {
                    fputs(linea, tmp);
                }
            }
         
            fclose(f);
            fclose(tmp);
            remove(ARCHIVO);
            rename(TEMP, ARCHIVO);
         
            if (encontrado)
                printf("Registro eliminado.\n");
            else
                printf("ID no encontrado.\n");
        }
 
    
}
