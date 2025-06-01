#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include </Applications/MAMP/Library/bin/mysql57/include/mysql.h>

typedef struct {
    int id;
    char nombre[100];
    char puesto[50];
} Empleado;

typedef struct {
    int empleado_id;
    char telefono[20];
    char email[100];
} InformacionContacto;

MYSQL *con;

void finish_with_error() {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void conectar() {
    con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "mysql_init() falló\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "root", "basedatos",
        8889, "/Applications/MAMP/tmp/mysql/mysql.sock", 0) == NULL) {
        finish_with_error();
    }
}

int crear_empleado(const Empleado *empleado) {
    char query[256];
    snprintf(query, sizeof(query),
             "INSERT INTO empleados(nombre, puesto) VALUES('%s', '%s')",
             empleado->nombre, empleado->puesto);

    if (mysql_query(con, query)) {
        finish_with_error();
    }
    return mysql_insert_id(con);
}

void crear_informacion_contacto(const InformacionContacto *contacto) {
    char query[256];
    snprintf(query, sizeof(query),
             "INSERT INTO informacion_contacto(empleado_id, telefono, email) VALUES(%d, '%s', '%s')",
             contacto->empleado_id, contacto->telefono, contacto->email);

    if (mysql_query(con, query)) {
        finish_with_error();
    }
}

void leer_empleados_y_contacto() {
    const char *query =
        "SELECT e.id, e.nombre, e.puesto, ic.telefono, ic.email "
        "FROM empleados e "
        "LEFT JOIN informacion_contacto ic ON e.id = ic.empleado_id "
        "ORDER BY e.id";

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    printf("\n--- Empleados e Información de Contacto ---\n");
    while ((row = mysql_fetch_row(result))) {
        printf("ID Empleado: %s, Nombre: %s, Puesto: %s\n", row[0], row[1], row[2]);
        printf("  Teléfono: %s, Email: %s\n", row[3] ? row[3] : "N/A", row[4] ? row[4] : "N/A");
    }

    mysql_free_result(result);
}

int main() {
    conectar();

    Empleado emp1 = {0, "Juan Perez", "Chef"};
    int emp1_id = crear_empleado(&emp1);

    InformacionContacto ic1 = {emp1_id, "555-1111", "juan.perez@restaurante.com"};
    crear_informacion_contacto(&ic1);

    Empleado emp2 = {0, "Maria Garcia", "Mesera"};
    int emp2_id = crear_empleado(&emp2);

    leer_empleados_y_contacto();

    mysql_close(con);
    return 0;
}