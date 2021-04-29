/**
 * @file server.c
 * @author Chen Liang
 * @brief Write a server and two clients. Server should be listening
 *          for numbers on a port know to the clients
 *          - Should handle the client connections sequentially and
 *              accept connection from multiple clients
 *          - after servising on client to completion (Client 1),
 *              it should proceed to exit.
 *          Client 1 will send an integer to the server.
 *          The server will decrement the number and send the result
 *              to client 2.
 *          The server should print both the value it receives and
 *              the value that it sends.
 *          Client 2 prints the number it receives and then all the
 *              processes should terminate.
 *
 * @version 0.1
 * @date 2021-04-29
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

/* Creating socket descriptor */
int create_socket(void)
{
    int sock_desc = 0;
    printf("Create the socket\n");
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);

    return sock_desc;
}

/* Bind the network address to the socket descriptor */
int bind_created_socket(int sock_desc)
{
    int bind_result = -1;
    int listen_port = 12345;

    struct sockaddr_in remote = { 0 };

    /* Internet address family */
    remote.sin_family = AF_INET;

    /* Any incoming interface */
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(listen_port);   /* Specified listen port */

    bind_result = bind(sock_desc, (struct sockaddr *)&remote,
                                                    sizeof(remote));
    return bind_result;
}

int main(void)
{
    int i = 0;
    int socket_desc = 0;
    int socket = 0;
    int client_len = 0;
    int client_input_number = 0;

    struct sockaddr_in client = { 0 } ;

    char client_message[100] = { 0 };
    char server_message[100] = { 0 };

    /* Create socket descriptor */
    socket_desc = create_socket();

    if (socket_desc == -1)
    {
        perror("Could not create socket");
        return 1;
    }

    printf("Socket created\n");

    /* Bind the network address to the socket descriptor */
    if (bind_created_socket(socket_desc) < 0)
    {
        perror("Binding network address to socket descriptor failed");
        return 1;
    }

    printf("Binding done\n");

    /* Listening to incoming request */
    listen(socket_desc, 3);

    /* Accepting incoming connection */

    printf("Waiting for incoming connections...\n");
    client_len = sizeof(struct sockaddr_in);

    /* accept connection from an incoming client */
    socket = accept(socket_desc,
                        (struct sockaddr *)&client,
                        (socklen_t *) &client_len);

    if (socket < 0)
    {
        printf("%d accept failed", client.sin_addr.s_addr);
        return 1;
    }
    {
        printf("Connection from %d accepted\n", client.sin_addr.s_addr);
    }

    memset(client_message, '\0', sizeof(client_message));
    memset(server_message, '\0', sizeof(server_message));

    /* Received a message from the first client */
    if (recv(socket, client_message, 200, 0) < 0)
    {
        printf("Receive from %d failed\n", client.sin_addr.s_addr);
    }
    else
    {
        sscanf(client_message, "%d", &client_input_number);
        printf("Receive message %d from %d\n",
                                client_input_number, client.sin_addr.s_addr);

        client_input_number--;
        sprintf(server_message, "%d", client_input_number);

    }

    /* Close client 1's socket */
    close(socket);

    /* accept connection from an incoming client */
    socket = accept(socket_desc,
                        (struct sockaddr *)&client,
                        (socklen_t *) &client_len);

    if (socket < 0)
    {
        printf("%d accept failed", client.sin_addr.s_addr);
        return 1;
    }
    {
        printf("Connection from %d accepted\n", client.sin_addr.s_addr);
    }

    /* Send the result to the client2 */
    if (send(socket, server_message, strlen(server_message), 0) < 0)
    {
        printf("Send to %d failed\n", client.sin_addr.s_addr);
        return 1;
    }
    else
    {
        printf("Send message %s to %d\n", server_message, client.sin_addr.s_addr);
    }

    /* Close client 2's socket */
    close(socket);

    return 0;
}