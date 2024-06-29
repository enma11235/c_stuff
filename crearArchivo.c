#include <stdio.h>
#include <string.h>

int createFile(const char* nombre, const char* ruta, const char* contenido){

    //concatenamos el nombre con la ruta
    //nota: esto lo pudimos haber hecho con sizeof()
    //paso 1: obtenemos el largo de nombre
    int pos = 0;
    int largoNombre = 0;
    while(nombre[pos] != '\0') {
	largoNombre++;
	pos++;
    }
    //paso 2: obtenemos el largo de ruta
    pos = 0;
    int largoRuta = 0;
    while(ruta[pos] != '\0') {
	largoRuta++;
	pos++;
    }
    //creamos un nuevo string
    int largo = largoRuta + largoNombre + 1;
    char path[largo];
    
    //lo rellenamos con ruta + nombre + \0
    pos = 0;
    for(int i = 0; i < largoRuta; i++) {
	path[pos] = ruta[i];
	pos++;
    }
    for(int i = 0; i < largoNombre; i++){
	path[pos] = nombre[i];
	pos++;
    }
    path[pos] = '\0';


    FILE* archivo;
    archivo = fopen(path, "w"); // Abre el archivo en modo escritura
    
    if(contenido != NULL) {
	int elementosEscritos = fwrite(contenido, sizeof(char), sizeof(contenido), archivo);
	if (elementosEscritos < sizeof(contenido)){
	    return 1;
	}
    }
    fclose(archivo);
    return 0;
}
