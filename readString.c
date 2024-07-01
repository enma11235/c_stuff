void readString() {
    //creamos una estructura de lista
    struct nodo {
	char c;
	struct nodo* sig;
    }

    struct lista {
	struct nodo* inicio;
	struct nodo* final;
    }

    //instanciamos un nuevo cabezal
    struct lista;
    cabezal.inicio = new steuct lista;
    cabezal.final = new;
    
    //leemos los caracteres
    char c;
    while ((c = getchar()) != '\n'){
	lista.final.sig = new struct nodo;
	lista.final = lista.final.sig;
	lista.final.c = c;
	list.final.sig = NULL;
    }

    //volcamos los caracteres leidos en u string
    struct nodo pointer = lista.inicio;
    char string[lista.size];
    for(struct nodo* i; i != NULL; i = i.sig){
	string[i.pos] = i.c;
    }

    //liberamos la lista
}
