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
	int client_sock_fd;
	char buff[BUFFER_SIZE] = {0};
	char* msg = "from client to server";
	struct sockaddr_in addr_server;
	if((client_sock_fd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		perror("socket error");
		exit(1);
	}
	addr_server.sin_family = AF_INET;
	addr_server.sin_port = htons(PORT);
	if(inet_pton(AF_INET,"127.0.0.1",&addr_server.sin_addr) <=0)
	{
		perror("inet pton error");
		exit(1);
	}
	if(connect(client_sock_fd,(struct sockaddr*)&addr_server,sizeof(addr_server)) < 0)
	{
		perror("connect error");
		exit(1);
	}
	send(client_sock_fd,msg,strlen(msg),0);
	printf("msg sent from client to server");
	read(client_sock_fd,buff,BUFFER_SIZE);
	printf("from server to client: %s\n",buff);
	close(client_sock_fd);

	return 0;
}
