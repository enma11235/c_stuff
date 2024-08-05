#include <mysql/mysql.h>

int main() {
    //conectamos a mysql
    MYSQL* conn;
    conn = mysql_init(NULL);
    mysql_real_connect(conn, "localhost:3063", "root", "11235", "fing_statistics", 0, NULL, 0);


    bool seguirEnBoucle = true;
    char* comando;
    
    while(seguirEnBucle) {
	//leer comando
	scanf("%s", comando);

	if(comando == "new materia") {
	    scanf("ingresa el nombre: %s\n", comando);
	    //hacer un insert en la base de datos
	    printf("materia guardada con exito\n");
	} else if (comandon == "cargar notas") {
	    int nota;
	    printf("ingresa -1 para finalizar carga de notas");
	    while(nota >= 0) {
		//hacer un insert en tabla notas
	    }
	} else if (comando == "obtener estadisticas") {
	    int id_materia;
	    //preguntamos ppr la materia
	    mysql_query(conn, "SELECT * FROM materias");
	    scanf(%d, id_materia);

	    //pretuntamos por el parcial
	    char* query = "SELECT * FROM parciales WHERE (id_materia = " + id_materia + ");"
	    mysql_query(query);
	    MYSQL_RES* resultado = mysql_store_result(conn);
	    //recorrer las notas y obtener cant presentados 
	    //y cant aprobados
	    //llamar a python
	}


    }

}
