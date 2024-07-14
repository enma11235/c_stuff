#if defined(_WIN32)

#ifndef _WIN32_WINNT 
#define _WIN32_WINNT 0x0600
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#else

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#endif

#if defined(_WIN32)
#define ISVALIDSOCKET(s) ((s) != INVALID_SOCKET)
#define CLOSESOCKET(s) closesocket(s)
#define GETSOCKETERRNO() (WSAGetLastError())

#else

#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETERRNO() (errno)

#endif

#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {

    #if defined(_WIN32)
	WSADATA d;
	if (WSAStartup(MAKEWORD(2,2), &d)) {
	    fprintf(stderr, "Failed to initialize.\n");
	    return 1;
	}
    #endif

    printf("Configuring local address...\n");
    struct addrinfo hints; //el tipo de direccion que queremos
    memset(&hints, 0, sizeof(hints)); //limpiamos basura
    hints.ai_family = AF_INET; //IPv4
    hints.ai_socktype = SOCK_STREAM; //TCP
    hints.ai_flags = AI_PASSIVE; //se asociara a un socket pasivo

    struct addrinfo *bind_address; //la direccion que usaremos
    getaddrinfo(0, "8080", &hints, &bind_address); //dejamos que el os nos la de

    printf("Creating socket...\n");
    SOCKET socket_listen;
    socket_listen = socket(bind_address->ai_family,
	    bind_address->ai_socktype, bind_address->ai_protocol);
    
    printf("Binding socket to local address...\n");
    if (bind(socket_listen,
		bind_address->ai_addr, bind_address->ai_addrlen)) {
	fprintf(stderr, "bind() failed. (%d)\n, GETSOCKETERRNO()");
	return 1;
    }
    
    printf("Listening...\n");
    if(listen(socket_listen, 10) < 0) {
	fprintf(stderr, "listen() failed. (%d\n)", GETSOCKETERRNO());
	return 1;
    }

    printf("Waiting for connection...\n");
    //struct sockaddr_storage se utiliza para almacenar direcciones de 
    //socket tanto de IPv4 como IPv6.
    //socklen_t se utiliza para almacenar la cantidad de bytes de una direccion
    //SOCKET es int, lo he renombrado para hacer el programa compatilbe con Windows
    struct sockaddr_storage client_address;
    socklen_t client_len = sizeof(client_address);
    //accept nos devuelve el socket del cliente que se ha conectado
    //sockk_listen es nuestro socket
    //accept almacenara en client_address la info de la direccion del cliente
    SOCKET socket_client = accept(socket_listen,
	    (struct sockaddr*) &client_address, &client_len);
    if(!ISVALIDSOCKET(socket_client)) {
	fprintf(stderr, "accept() failed. (%d)\n", GETSOCKETERRNO());
	return 1;
    }
    //El programa se detiene en este punto hasta que un cliente se conecte
    printf("Client is connected...\n");
    char address_buffer[100]; 
    getnameinfo((struct sockaddr*) &client_address,
	    client_len, address_buffer, sizeof(address_buffer), 0, 0,
	    NI_NUMERICHOST);
    printf("%s\n", address_buffer);

    printf("Reading request...\n");
    char request[1024];
    int bytes_received = recv(socket_client, request, 1024, 0);
    printf("Received %d bytes.\n", bytes_received);

    printf("Sending response...\n");
    //un simple string
    const char *response =  
	"HTTP/.1.1 200 OK\r\n"
	"Connection: close\r\n"
	"Content-Type: text/plain\r\n\r\n"
	"Local time is: ";
    //la funcion send devuelve la cantidad de bytes enviados
	int bytes_sent = send(socket_client, response, strlen(response), 0);
	printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(response));
}
