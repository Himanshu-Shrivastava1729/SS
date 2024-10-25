/*
============================================================================
Name : 33.c
Author : Himanshu Shrivastava
Description :Write a program to communicate between two machines using socket.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 2048

int main()
{
	int fd_server,incoming_socket;
	struct sockaddr_in addr;
	int lenaddr = sizeof(addr);
	char buff[BUFFER_SIZE] ={0};
	int opt = 1;
	if((fd_server = socket(AF_INET,SOCK_STREAM,0)) <  0)
	{
		perror("socket error");
		exit(1);
	}
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(PORT);
	if(bind(fd_server,(struct sockaddr*)&addr,sizeof(addr)) < 0)
	{
		perror("bind error");
		exit(1);
	}
	printf("listening for incoming connection\n");
	if(listen(fd_server,2) < 0)
	{
		perror("listen error");
		exit(1);
	}
	if((incoming_socket = accept(fd_server,(struct sockaddr*)&addr,(socklen_t*)&lenaddr)) < 0)
	{
		perror("accept error");
		exit(1);
	}
	read(incoming_socket,buff,BUFFER_SIZE);
	printf("msg from client to server: %s\n",buff);
	printf("now sending response from server to client\n");
	const char* server_to_client = "server received msg\n";
	send(incoming_socket,server_to_client,strlen(server_to_client),0);

	close(fd_server);
	close(incoming_socket);
	return 0;
}
