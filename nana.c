#include <stdio.h>

int main() {
    printf("Hola Morwenna.\n");
    printf("Bienvenida a mi computadora.\n");
    printf("Escribe cualquier cosa y luego presiona 'enter'.\n");
    printf("Lo que escribas sera guardado en una carpeta especial y leido por mi >:)\n\n");
	const char* name = readString();

    //creamos un nuevo archivo en la carpeta de mensajitos
    //podemos crear un archivito que nos diga el número del mensaje más alto
    FILE* mensajito = fopen("/home/enma/mensajitos/mensaito1", "w");
    char mensaje[50];
    scanf("%s", mensaje);
    fclose(mensajito);
    return 0;
}
