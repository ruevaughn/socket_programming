#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

// Server Flow 23:36
// "Server" Socket Workflow
// On the "server" end of the socket, we need to also create a socket with a socket() call, but
// then, we need to bind() that socket to an ip and port where it can then listen() for connections,
// and then finally accept() a connection and then send() or recv() data to the other sockets connected

int main() {
    // Finished code https://youtu.be/LtXEMwSG5-8?t=2191

    char server_message[256] = "You have reached the server";

    // Create the Server Socket
    int server_socket;

    // Still an internet socket and still a tcp/socket so using a
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    //Define the server address, type is struct, pretty much the same parameters
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    // INADDR_ANY resolves to any IP address on the local machine 30:27
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Now we can call the bind function in almost exactly the same way we called the connect function 30:39
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    listen(server_socket, 5);

    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    send(client_socket, server_message, sizeof(server_message), 0);

    close(server_socket);

    return 0;
}
