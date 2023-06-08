#include <stdio.h>
#include <iostream>
#include <sys/socket.h>

using namespace std;

// int main()
// {
//     printf("Console-chat Server is starting...\n");

//     int sock = socket(PF_INET, SOCK_STREAM, 0);

//     if (sock == -1)
//     {
//         printf("[ERR] sock is not created");
//     }
    
//     printf("sock:: %d\n", sock);
//     bind(sock, )

//     while (sock)
//     {

//     }
    
//     return 0;
// }
#include <netinet/in.h>
// need netinet to use sockaddr_in
// sockaddr_in => IPv4
// #include <stdlib.h>
#include <string.h>
#include <unistd.h>
// need unistd to use read/write
#define PORT 8080
#define IS_RUNNING 1

int initialize_server()
{
    return true;
}

int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = { 0 };
    char* hello = "Hello from server";
    int status = IS_RUNNING;
    int SOCKET_BACKLOG = 10;

    printf("Console-chat Server is starting...\n");
  
    // Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    printf("server socket no: %d\n", server_fd);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
  
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    while(IS_RUNNING)
    {
        if (listen(server_fd, SOCKET_BACKLOG) < 0)
        {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address,(socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        valread = read(new_socket, buffer, 1024);
        printf("%s\n", buffer);
        send(new_socket, hello, strlen(hello), 0);
        printf("Hello message sent\n");
        
    }
    
  // closing the connected socket
    close(new_socket);
  // closing the listening socket
    shutdown(server_fd, SHUT_RDWR);
    return 0;
}