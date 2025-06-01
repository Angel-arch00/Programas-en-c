#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include </Applications/MAMP/Library/bin/mysql57/include/mysql.h>

typedef struct {
    int id;
    char nombre[100];
    char apellido[100];
} Cliente;

typedef struct {
    int id;
    int cliente_id;
    char fecha_hora[20];
    double total;
} Pedido;

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

int crear_cliente(const Cliente *cliente) {
    char query[256];
    snprintf(query, sizeof(query),
             "INSERT INTO clientes(nombre, apellido) VALUES('%s', '%s')",
             cliente->nombre, cliente->apellido);

    if (mysql_query(con, query)) {
        finish_with_error();
    }
    return mysql_insert_id(con);
}

int crear_pedido(const Pedido *pedido) {
    char query[512];
    snprintf(query, sizeof(query),
             "INSERT INTO pedidos(cliente_id, fecha_hora, total) VALUES(%d, '%s', %.2f)",
             pedido->cliente_id, pedido->fecha_hora, pedido->total);

    if (mysql_query(con, query)) {
        finish_with_error();
    }
    return mysql_insert_id(con);
}

void leer_clientes_y_pedidos() {
    const char *query =
        "SELECT c.id AS cliente_id, c.nombre AS cliente_nombre, c.apellido AS cliente_apellido, "
        "p.id AS pedido_id, p.fecha_hora, p.total "
        "FROM clientes c "
        "LEFT JOIN pedidos p ON c.id = p.cliente_id "
        "ORDER BY c.id, p.fecha_hora";

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int last_cliente_id = -1;

    printf("\n--- Clientes y sus Pedidos ---\n");
    while ((row = mysql_fetch_row(result))) {
        int cliente_id = atoi(row[0]);
        const char *cliente_nombre = row[1];
        const char *cliente_apellido = row[2];
        const char *pedido_id_str = row[3];
        const char *fecha_hora = row[4];
        const char *total_str = row[5];

        if (cliente_id != last_cliente_id) {
            printf("\nCliente ID: %d, Nombre: %s %s\n", cliente_id, cliente_nombre, cliente_apellido);
            printf("  Pedidos:\n");
            last_cliente_id = cliente_id;
        }

        if (pedido_id_str != NULL) {
            printf("    - Pedido ID: %s, Fecha/Hora: %s, Total: %s\n",
                   pedido_id_str, fecha_hora, total_str);
        } else {
            printf("    - No tiene pedidos registrados.\n");
        }
    }

    mysql_free_result(result);
}

int main() {
    conectar();

    Cliente cliente1 = {0, "Ana", "Lopez"};
    int cliente1_id = crear_cliente(&cliente1);

    Cliente cliente2 = {0, "Pedro", "Martinez"};
    int cliente2_id = crear_cliente(&cliente2);

    Pedido pedido1 = {0, cliente1_id, "2025-05-30 18:00:00", 150.75};
    crear_pedido(&pedido1);

    Pedido pedido2 = {0, cliente1_id, "2025-05-30 19:30:00", 90.00};
    crear_pedido(&pedido2);

    Pedido pedido3 = {0, cliente2_id, "2025-05-30 20:00:00", 210.50};
    crear_pedido(&pedido3);

    leer_clientes_y_pedidos();

    mysql_close(con);
    return 0;
}
