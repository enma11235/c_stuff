#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>

//programita para imprimir todas las direcciones ip en nuestra red local

int main() {

    //decalramos un puntero a struct ifaddrs, que almacenara 
    //las direcciones. La funcion getifaddrs() crea una lista enlazada
    //(memoria dinamica) de estrucutras que representan una 
    //direccion y la almacena adentro de nuestra variable.
    //si no hay errores retorna 0, si hay un error retorna -1.

    struct ifaddrs *addresses;
    if (getifaddrs(&addresses) == -1) {
	printf("getifaddrs call failed\n");
	return -1;
    }
    
    //declaramos un nuevo puntero a struct ifaddrs para recorrer la lsita
    //enlazada. Nos situamos al principio.
    struct ifaddrs *address = addresses;

    //Para avanzar en la lista usamos address->ifa_next que nos da el siguiente nodo.
    //El recorrido se detiene cuando llegamos al ultimo nodo, que es 0 (o NULL?) 

    //para cada direccion, obtenemos su familia. Estamos interesados en 
    //direcciones del tipo AF_INET (IPv4) y AF_INET6 (IPv6).
    //getifaddrs() retorna otros tipos, asi que debemos filtrarlos.
    //Para cada direcion, imprimimos el nombre de su adaptador y su tipo de direccion.
    //Luego definimos un buffer ap que almacenara el texto de la direccion. 
    //getnameinfo() rellena el buffer, que luego podemos imprimir.
    //Al final liberamos memoria reservada por getifaddres() 
    
    while(address) {
	int family = address->ifa_addr->sa_family;
	if (family == AF_INET || family == AF_INET6) {
	    printf("%s\t", address->ifa_name);
	    printf("%s\t", family == AF_INET ? "IPv4" : "IPv6");

	    char ap[100];
	    const int family_size = family == AF_INET ?
		sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
	    getnameinfo(address->ifa_addr,
		family_size, ap, sizeof(ap), 0, 0, NI_NUMERICHOST);
	    printf("\t%s\n", ap);
	}
	address = address->ifa_next;
    }
    freeifaddrs(addresses);
    return 0;
}
