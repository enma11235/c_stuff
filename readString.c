const char* readString() {
    //creamos una estructura de lista
    struct nodo {
	char c;
	struct nodo* sig;
    }

    struct lista {
	struct nodo* inicio;
	struct nodo* final;
	int size;
    }

    //instanciamos una nueva lista
    struct lista buffer;
    buffer.inicio = (struct nodo*)malloc(sizeof(struct nodo));
    buffer.final = lista.inicio;
    buffer.size = 0;
    
    //leemos el primer caracter
    char c;
    c = getchar();
    buffer.inicio->c = c;
    buffer.size = 1;

    //loopeamos hasta encontrar un salto de linea
    while ((c = getchar()) != '\n'){
	buffer.final.sig = (struct nodo*)malloc(sizeof(struct nodo));
	buffer.final = lista.final->sig;
	buffer.final->c = c;
	buffer.final->sig = NULL;
	buffer.size++;
    }

    //volcamos los caracteres leidos en u string
    int pos = 0;
    char string[buffer.size + 1];
    for(struct nodo* i = buffer.inicio; i != NULL; i = i->sig){
	string[pos] = i->c;
	pos++;
    }
    string[pos] = '\0';

    //liberamos la lista

    //retornamos el string
    return string;
}
