#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

// Socket Programming Tutorial in C from Scratch - Socket Programming Basics
// Socket Programming Tutorial In C For Beginners | Part 1 | Eduonix
// https://www.youtube.com/watch?v=LtXEMwSG5-8

// Covering some of the low-level concepts aroudn programming sockets, specifcally
// the C Sockets API and the functions that are necesary to create sockets that will act
// as both Client and Servers in various Networking Applications. This course assumes

// 2:01 "Client" socket Workflow
// The Client socket is created with a socket() call, and then connected to a remote address
// With the connect() call, and then finally can retreive data with the recv() call

//                     1 socket()
//                          |
//                          v
//                     2 connect()
//                          |
//                          v
//                     3  recv()

int main() {
    // Done with Client https://youtu.be/LtXEMwSG5-8?t=1407

    // create a socket
    int network_socket;

    network_socket = socket(AF_INET, SOCK_STREAM, 6);

    // specify an address for the socket
    // this create one of the nedpoints needed for network communication.
    // Beecause this is going to be the client we are going to need to
    // write another one of these. We need to connect it to another side/socket.
    // In order to do so, we need to call the connect() function we talked about.

    // Before we get to calling the other port we need to have the address to connect to.
    // That why we needed the netinet header we included above. It contains the structure
    // we can define a few fields on (11:22)

    // wwe declare te address for the structure like this
    struct sockaddr_in server_address;

    // We have a couple fields we need to define on this sockaddr_in structure, the first
    // one will be Fammily Name
     server_address.sin_family = AF_INET;

    // Then we ned to define the port we need to connect to, aka sin_port
    // We could pass the port in as an integer, howeer the data structure
    // As the paramter to this funcion we pass the actual port number
    // Then you need to supply the actual address
    server_address.sin_port = htons(9062);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket, (struct sockadr *) &server_address, sizeof(server_address));

    if (connection_status == -1) {
        printf("There was an error making a connection to the remote socket \n\n");
    }

    // Receive Data from the server
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);
    // 23:36 server flow
    // Print out servers response
    printf("The server sent the data. %s\n", server_response);
    close(network_socket);
    return 0;

}