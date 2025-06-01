#include <stdio.h>

#include <stdlib.h>

#include </usr/include/mysql/mysql.h>



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



 // Cambiar los parámetros según tu configuración de MySQL en Linux

 // user: root, password: root, database: basedatos, host: localhost, port: 3306, socket: NULL

 if (mysql_real_connect(con, "localhost", "root", "", "basedatos", 

 0, "/opt/lampp/var/mysql/mysql.sock", 0) == NULL) {

 finish_with_error();

}

}



void crear_persona(const char *nombre, int edad) {

 char query[256];

 snprintf(query, sizeof(query),

 "INSERT INTO personas(nombre, edad) VALUES('%s', %d)", nombre, edad);

 if (mysql_query(con, query)) {

 finish_with_error();

 } else {

 printf("Persona creada.\n");

 }

}



void leer_personas() {

 if (mysql_query(con, "SELECT id, nombre, edad FROM personas")) {

 finish_with_error();

 }



 MYSQL_RES *result = mysql_store_result(con);

 if (result == NULL) {

 finish_with_error();

 }



 int num_fields = mysql_num_fields(result);

 MYSQL_ROW row;



 while ((row = mysql_fetch_row(result))) {

 for (int i = 0; i < num_fields; i++) {

 printf("%s\t", row[i] ? row[i] : "NULL");

 }

 printf("\n");

 }



 mysql_free_result(result);

}



void actualizar_persona(int id, const char *nuevo_nombre, int nueva_edad) {

 char query[256];

 snprintf(query, sizeof(query),

 "UPDATE personas SET nombre='%s', edad=%d WHERE id=%d",

 nuevo_nombre, nueva_edad, id);

 if (mysql_query(con, query)) {

 finish_with_error();

 } else {

 printf("Persona actualizada.\n");

 }

}



void eliminar_persona(int id) {

 char query[128];

 snprintf(query, sizeof(query), "DELETE FROM personas WHERE id=%d", id);

 if (mysql_query(con, query)) {

 finish_with_error();

 } else {

 printf("Persona eliminada.\n");

 }

}



int main() {

 conectar();



 crear_persona("Ana", 28);

 leer_personas();

 actualizar_persona(1, "Ana María", 29);

 eliminar_persona(1);



 mysql_close(con);

 return 0;

}




/**

 * 

# Guía para compilar y ejecutar un programa C con MySQL en Linux



## 1. Instalar las dependencias necesarias



### Instalar GCC 



sudo apt-get update

sudo apt-get install build-essential



### Instalar la librería de desarrollo de MySQL

sudo apt-get install libmysqlclient-dev



## 2. Verificar la instalación

gcc --version



### Verificar que tienes el archivo `mysql.h`

ls /usr/include/mysql/mysql.h



Si se encuentra la ruta, todo ok



## 3. Compilar el programa



Asumiendo que tu archivo se llama `DemoLinux.c` y está en el directorio `4.BaseDatos/`:

cd 4.BaseDatos

gcc -o DemoLinux DemoLinux.c -I/usr/include/mysql -lmysqlclient



Explicacion

- `-I/usr/include/mysql` le dice a GCC dónde buscar los headers de MySQL.

- `-lmysqlclient` enlaza la librería cliente de MySQL.



---



## 4. Ejecutar el programa

./DemoLinux



## 5. Notas adicionales



- **Base de datos y tabla:** 

 CREATE DATABASE IF NOT EXISTS basedatos;

 USE basedatos;

 CREATE TABLE IF NOT EXISTS personas (

 id INT AUTO_INCREMENT PRIMARY KEY,

 nombre VARCHAR(100),

 edad INT

 );

 */
