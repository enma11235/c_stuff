#include <stdio.h>
#include "./readString.c"

int main() {
  printf("Hola Personita.\n");
  printf("Bienvenida a mi computadora :)\n");
  printf("Por favor escribe un mensajito y presiona [ENTER].\n");
  
  // abrimos un archivo en la carpeta "mensajitos"
  FILE* fd = fopen("/home/enma/mensajitos/mensaito1", "w");
  //creamos un array de 50 caracteres para almacenar el mensaje
  char* mensaje = getString();
  //leemos el mensaje
  scanf("%s", mensaje);
  //escribimos en el archivo
  fwrite(mensaje, sizeof(char), 50, fd);
  //cerramos el archivo
  fclose(fd);
  return 0;
}
