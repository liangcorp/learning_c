#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

short socket_create(void)
{
	short h_socket;
	printf("Create the socket\n");
	h_socket = socket(AF_INET, SOCK_STREAM, 0);
	return h_socket;
}

int bind_created_socket(int h_socket)
{
	int i_retval = -1;
	int client_port = 12345;

	struct sockaddr_in remote = { 0 };

	/* Internet address family */
	remote.sin_family = AF_INET;

	/* Any incoming interface */
	remote.sin_addr.s_addr = htonl(INADDR_ANY);
	remote.sin_port = htons(client_port); /*local port */

	i_retval = bind(h_socket, (struct sockaddr *)&remote, sizeof(remote));

	return i_retval;
}

int main(int argc, char *argv[])
{
	int socket_desc = 0;
	int sock = 0;
	int client_len = 0;
	struct sockaddr_in client;
	char client_message[200] = { 0 };
	char message[100] = { 0 };
	const char *p_message = "hello from Jason's server";

	/* create socket */
	socket_desc = socket_create();

	if (socket_desc == -1) {
		printf("Could not create socket");
		return 1;
	}

	printf("Socket created\n");

	/* Bind */
	if (bind_created_socket(socket_desc) < 0) {
		perror("bind falied.");
		return 1;
	}
	printf("bind done\n");

	/* Listen */
	listen(socket_desc, 3);

	/* Accept and incoming connection */
	while (1) {
		printf("Waiting for incoming connections...\n");
		client_len = sizeof(struct sockaddr_in);

		/* accept connection from an incoming client */
		int socket = accept(socket_desc, (struct sockaddr *)&client,
				    (socklen_t *)&client_len);

		if (sock < 0) {
			perror("accept failed");
			return 1;
		}

		printf("Connection accepted\n");
		memset(client_message, '\0', sizeof client_message);
		memset(message, '\0', sizeof message);

		/* Receive a reply from the client */
		if (recv(sock, client_message, 200, 0) < 0) {
			printf("recv failed\n");
			break;
		}

		printf("Client reply: %s\n", client_message);

		if (strncmp(p_message, client_message, 5) == 0)
			strcpy(message, "Hi there!");
		else
			strcpy(message, "Invalid Message!");

		/* send some data */
		if (send(sock, message, strlen(message), 0) < 0) {
			printf("Send failed");
			return 1;
		}
		close(sock);
		sleep(1);
	}
	return 0;
}
