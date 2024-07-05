#include <stdio.h>
#include <string.h>

int main() {
    char A[10];
    printf("char A[10];\n");
    scanf("%s", A); //scanf deja de leer en el primer espacio o salto de linea, y agrega un '\0' al final
    
    char c = A[0];
    int i = 0;
    while(c != '\0') {
	printf("A[%d] = %c\n", i, A[i]);
	i++;
	c = A[i];
    }
    if(c == '\0') printf("A[%d] = caracter nulo\n\n", i);

    printf("sizeof A: %ld\n", sizeof(A));
    printf("strlen of A: %ld\n", strlen(A));
    return 0;
}
