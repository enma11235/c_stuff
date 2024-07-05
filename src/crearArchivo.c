#include <stdio.h>
#include <string.h>

void createFile(const char* nombre, const char* ruta, const char* contenido){

    //paso 1: obtenemos el largo de nombre
    int largoNombre = strlen(nombre);
    //paso 2: obtenemos el largo de ruta
    int largoRuta = strlen(ruta);
    //creamos un nuevo string de tamaño 'largo'
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

    //creamos un descriptor de archivo
    FILE* archivo;
    //abrimos un nuevo archivo en la ruta path (modo w)
    archivo = fopen(path, "w");{
    //escribimos el archivo
    fwrite(contenido, sizeof(char), sizeof(contenido), archivo);
    //cerramos el archivo
    fclose(archivo);
    return 0;
}
