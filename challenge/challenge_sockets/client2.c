/**
 * @file client2.c
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

/* Create a socket for connecting to server */
short create_socket(void)
{
    short socket_desc = 0;
    printf("Create the socket\n");
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    return socket_desc;
}

/* Try to connect to the server */
int connect_to_server(int socket_desc)
{
    int con_result = -1;
    int server_port = 12345;

    struct sockaddr_in remote = { 0 };
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_family = AF_INET;
    remote.sin_port = htons(server_port);

    con_result = connect(socket_desc, (struct sockaddr *)&remote,
                                            sizeof(struct sockaddr_in));

    return con_result;
}

/* receive the data from the server */
int socket_receive(int socket_desc, char* rsv, short len_rsv)
{
    int result_val = -1;
    struct timeval tv;
    tv.tv_usec = 20;    /* 20 seconds timeout */
    tv.tv_sec = 0;

    if (setsockopt(socket_desc, SOL_SOCKET, SO_RCVTIMEO,
                                    (char *)&tv, sizeof(tv)) < 0)
    {
        printf("Time Out\n");
        return -1;
    }

    result_val = recv(socket_desc, rsv, len_rsv, 0);
    printf("Response %s\n", rsv);

    return result_val;
}

int main(void)
{
    int socket_desc = 0;
    int read_size = -1;

    struct sockaddr_in server;

    char server_reply[100] = { 0 };

    /* Create socket */
    socket_desc = create_socket();

    if (socket_desc == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }

    printf("Socket is created\n");

    /* Connect to remote server */
    if (connect_to_server(socket_desc) < 0)
    {
        perror("connect failed.\n");
        return 1;
    }

    printf("Successfully connected with server\n");
    /*
    while(1)
    {
        if (socket_receive(socket_desc, server_reply, 200) != -1)
            break;
    }
     */

    /* Received the data from the server */
    read_size = socket_receive(socket_desc, server_reply, 200);
    printf("Server Response: %s: read_size %d\n\n",server_reply,
                                                        read_size);

    close(socket_desc);
    return 0;
}