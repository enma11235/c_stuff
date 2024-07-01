#include <stdio.h>

int main() {
    printf("Hola Morwenna.\n");
    printf("Bienvenida a mi computadora.\n");
    printf("Escribe cualquier cosa y luego presiona 'enter'.\n");
    printf("Lo que escribas sera guardado en una carpeta especial y leido por mi >:)\n\n");

    FILE* mensajito = fopen("/home/enma/mensajitos/mensaito1", "w");
    fclose(mensajito);
    return 0;
}
