#include <stdio.h>
#include <stdlib.h>

char* getString() {

    //variables
    char c;
    int pos;

    //estructura de lista 
    struct nodo {
	char c;
	struct nodo* sig;
    };

    struct lista {
	struct nodo* inicio;
	struct nodo* final;
	int size;
    };

    //instanciamos una nueva lista
    struct lista lista;
    lista.inicio = (struct nodo*)malloc(sizeof(struct nodo));
    lista.final = lista.inicio;
    lista.size = 0;

    //leemos el primer caracter
    scanf("%c", &c);

    //loopeamos hasta encontrar un salto de linea
    while (c != '\n'){
	lista.final->sig = (struct nodo*)malloc(sizeof(struct nodo));
	lista.final = lista.final->sig;
	lista.final->c = c;
	lista.final->sig = NULL;
	lista.size++;
	scanf("%c", &c);
    }

    //copiamos los caracteres de la lista a un array
    pos = 0;
    char* string = (char*)malloc(sizeof(char)*lista.size + 1);
    for(struct nodo* i = lista.inicio; i != NULL; i = i->sig){
	string[pos] = i->c;
	pos++;
    }
    string[pos] = '\0';

    //liberamos la lista
    struct nodo* i = lista.inicio;
    while(i != NULL) {
	struct nodo* aux = i;
	i = i->sig;
	free(aux);
    }

    //retornamos el string
    return string;
}
