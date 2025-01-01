#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

/* create a socket for serve communcation */
short socket_create(void)
{
	short h_socket;
	printf("Create the socket\n");
	h_socket = socket(AF_INET, SOCK_STREAM, 0);
	return h_socket;
}

/* try to connect with server */
int socket_connect(int h_socket)
{
	int i_retval = -1;
	int server_port = 12345;

	struct sockaddr_in remote = { 0 };
	remote.sin_addr.s_addr = inet_addr("127.0.0.1"); /* local host */
	remote.sin_family = AF_INET;
	remote.sin_port = htons(server_port);

	i_retval = connect(h_socket, (struct sockaddr *)&remote,
			   sizeof(struct sockaddr));
	return i_retval;
}

/* send the data to the server and set the timeout of 20 seconds */
int socket_send(int h_socket, char *rqst, short len_rqst)
{
	int short_retval = -1;
	struct timeval tv;
	tv.tv_sec = 20; /* 20 secs timeout */
	tv.tv_usec = 0;

	if (setsockopt(h_socket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv,
		       sizeof(tv)) < 0) {
		printf("Time out\n");
		return -1;
	}

	short_retval = send(h_socket, rqst, len_rqst, 0);
	return short_retval;
}

/* reveive the data from the servre */
int socket_receive(int h_socket, char *rsp, short rvs_size)
{
	int short_retval = -1;
	struct timeval tv;
	tv.tv_sec = 20; /* 20 secs timeout */
	tv.tv_usec = 0;

	if (setsockopt(h_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,
		       sizeof(tv)) < 0) {
		printf("Time out\n");
		return -1;
	}

	short_retval = recv(h_socket, rsp, rvs_size, 0);
	printf("Response %s\n", rsp);

	return short_retval;
}

/* main driver program */
int main(int argc, char *argv[])
{
	int h_socket = 0;
	int read_size = 0;

	struct sockaddr_in server;
	char send_to_server[100] = { 0 };
	char server_reply[200] = { 0 };

	/* create socket */
	h_socket = socket_create();

	if (h_socket == -1) {
		printf("Could not create socket\n");
		return 1;
	}

	printf("Socket is created\n");

	/* connecto remote server */
	if (socket_connect(h_socket) < 0) {
		perror("connect failed.\n");
		return 1;
	}

	printf("Successfully connected with server\n");
	printf("Enter the Message: ");
	fgets(send_to_server, 100, stdin);

	/* send data to the server */
	socket_send(h_socket, send_to_server, strlen(send_to_server));

	/* received the data from the server */
	read_size = socket_receive(h_socket, server_reply, 200);
	printf("Server Response: %s\n\n", server_reply);

	close(h_socket);

	return 0;
}
