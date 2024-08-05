#include <stdio.h>
#include <string.h>

int main() {

    //estudiar los enumerados y fijarse que se implementan como int.

    //Las variables de tipo int ocupan 4 bytes en memoria.
    //Las direcciones de memoria (pointers) ocupan 8 bytes.
    //El operador & devuelve la direccion de memoria de una variable.
    int n;
    printf("int n;\n");
    printf("sizeof(n) = %ld\n", sizeof(n));
    printf("sizeof(&n) = %ld\n", sizeof(&n));
    printf("&n = %p\n\n", &n);

    //Variables de tipo long ocupan 8 bytes en memoria.
    long l;
    printf("long l;\n");
    printf("sizeof(l) = %ld\n", sizeof(l));
    printf("sizeof(&l) = %ld\n", sizeof(&l));
    printf("&l = %p\n\n", &l);

    //Los arrays se implementan como un puntero a su 
    //primer elemento. Sin embargo, conceptualmente son 
    //distintos a un puntero. Por eso, su tamanio es
    //el tamanio de la estructura completa.
    char A[3];
    printf("char A[3];\n");
    printf("sizeof(A) = %ld\n", sizeof(A));
    printf("A = %p\n", A);
    printf("&A[0] = %p\n", &A[0]);
    printf("&A[1] = %p\n", &A[1]);
    printf("&A[2] = %p\n\n", &A[2]);

    int B[3];
    printf("int B[3]\n");
    printf("sizeof(B) = %ld\n", sizeof(B));
    printf("B = %p\n", B);
    printf("&B[0] = %p\n", &B[0]);
    printf("&B[1] = %p\n", &B[1]);
    printf("&B[2] = %p\n\n", &B[2]);

    //Se puede asignar un literal de cadena a un char pointer
    //los literales de cadena son convertidos por el compilador
    //en arrays de caracteres terminados por el caracter nulo.
    //Hay una diferencia conceptual entre declarar un puntero y
    //un array, por eso, el tamanio de un char pointer es el tamanio
    //del puntero, no de la estructura completa.

    //strlen() cuenta la cantidad de caracteres sin incluir
    //el caracter nulo.
    char* C = "abc"; 
    printf("char* C = 'abc':\n");
    printf("sizeof(C) = %ld\n", sizeof(C)); 
    printf("strlen(C) = %ld\n", strlen(C)); 
    printf("C = %p\n", C);

    //Si aplicamos strlen() en un array de caracteres que no 
    //contiene un caracter nulo...


    //es posible acceder a los caracteres individuales del literal
    //de cadena que hemos asignado al char pointer.
    printf("&C[0] = %p | C[0] = %c\n", &C[0], C[0]);
    printf("&C[1] = %p | C[1] = %c\n", &C[1], C[1]);
    printf("&C[2] = %p | C[2] = %c\n", &C[2], C[2]);
    printf("&C[3] = %p | C[3] = %c (caracter nulo)\n\n", &C[3], C[3]);
    
    //Podemos asignar un nuevo literal de cadena a nuestro char pointer.
    //Incluso podemos asignar un array. Es por eso que los pointers son mas 
    //flexibles que los arrays...
    C = "xy";
    printf("C = 'xy'\n");
    printf("sizeof(C) = %ld\n", sizeof(C));
    printf("strlen(C) = %ld\n", strlen(C)); 
    printf("C = %p\n", C);
    //podemos acceder a los caracteres del nuevo
    //literal de cadena que hemos asignado.
    printf("&C[0] = %p | C[0] = %c \n", &C[0], C[0]);
    printf("&C[1] = %p | C[1] = %c\n", &C[1], C[1]);
    printf("&C[2] = %p | C[2] = %c (caracter nulo)\n\n", &C[2], C[2]);

    //Podemos declarar arrays con tamanio indefinido,
    //y asignarles un literal de cadena.
    char D[] = "abc";
    printf("char D[] = 'abc'\n");
    printf("sizeof(D) = %ld\n", sizeof(D));
    printf("strlen(D) = %ld\n", strlen(D));
    printf("D = %p\n", D);
    printf("&D[0] = %p | C[0] = %c \n", &D[0], D[0]);
    printf("&D[1] = %p | C[1] = %c\n", &D[1], D[1]);
    printf("&D[2] = %p | C[2] = %c\n", &D[2], D[2]);
    printf("&D[3] = %p | C[3] = %c (caracter nulo)\n\n", &D[3], D[3]);

    //Los arrays indefnidos deben inicializarse inmediatamente.
    //No es posible hacer algo asi:
    //int E[];
    //E = {1, 2};

    //tambien podemos inicialiar un array de tamanio
    //indefinido asignandole los elementos especificamente.
    int E[] = {1, 2, 3};
    printf("int E[] = {1, 2, 3}\n");
    printf("sizeof(E) = %ld\n", sizeof(E));
    
    //tenemos que estudiar la memoria de los struct
    
    //llenar bloques de memoria
    //creamos un bloque de memoria de 5 bytes
    char a[5];
    memset(a, 0, 5);

    //struct addrinfo

}
