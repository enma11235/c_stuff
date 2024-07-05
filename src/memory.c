#include <stdio.h>
#include <string.h>

int main() {
    //variables
    int n;
    printf("int n;\n");
    printf("sizeof(n) == %ld\n", sizeof(n));
    printf("sizeof(&n) == %ld\n", sizeof(&n));
    printf("&n == %p\n\n", &n);

    long l;
    printf("long l;\n");
    printf("sizeof(l) == %ld\n", sizeof(l));
    printf("sizeof(&l) == %ld\n", sizeof(&l));
    printf("&l == %p\n\n", &l);

    char A[3];
    printf("char A[3];\n");
    printf("sizeof(A) == %ld\n", sizeof(A));
    printf("&A == %p\n", A);
    printf("&A[0] == %p\n", &A[0]);
    printf("&A[1] == %p\n", &A[1]);
    printf("&A[2] == %p\n\n", &A[2]);

    int B[3];
    printf("int B[3]\n");
    printf("size of  B: %ld\n", sizeof(B));
    printf("adress of B: %p\n", B);
    printf("adress of B[0]: %p\n", &B[0]);
    printf("adress of B[1]: %p\n", &B[1]);
    printf("adress of B[2]: %p\n\n", &B[2]);

    char* C = "abc";
    printf("char* C = 'abc':\n");
    printf("size of C: %ld\n", sizeof(C));
    printf("strlen C: %ld\n", strlen(C));
    printf("adress of C: %p\n", C);
    printf("adress of C[0]: %p ---> C[0] = %c \n", &C[0], C[0]);
    printf("adress of C[1]: %p ---> C[1] = %c\n", &C[1], C[1]);
    printf("adress of C[2]: %p ---> C[2] = %c\n", &C[2], C[2]);
    printf("adress of C[3]: %p ---> C[3] = %c (caracter nulo)\n\n", &C[3], C[3]);

    C = "12";
    printf("C = '12'\n");
    printf("size of C: %ld\n", sizeof(C));
    printf("strlen C: %ld\n", strlen(C));
    printf("adress of C: %p\n", C);
    printf("adress of C[0]: %p ---> C[0] = %c \n", &C[0], C[0]);
    printf("adress of C[1]: %p ---> C[1] = %c\n", &C[1], C[1]);
    printf("adress of C[2]: %p ---> C[2] = %c (caracter nulo)\n\n", &C[2], C[2]);

    char D[] = "abc";
    printf("char D[] = 'abc' (literal de cadena):\n");
    printf("size of D: %ld\n", sizeof(D));
    printf("strlen D: %ld\n", strlen(D));
    printf("adress of D: %p\n", D);
    printf("adress of D[0]: %p ---> C[0] = %c \n", &D[0], D[0]);
    printf("adress of D[1]: %p ---> C[1] = %c\n", &D[1], D[1]);
    printf("adress of D[2]: %p ---> C[2] = %c\n", &D[2], D[2]);
    printf("adress of D[3]: %p ---> C[3] = %c (caracter nulo)\n\n", &D[3], D[3]);

}
